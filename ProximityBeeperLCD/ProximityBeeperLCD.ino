#include <LiquidCrystal.h>
#define trig 9
#define echo 10
#define buzz 11
#define led 13

long duration;
int distance;
int safeDistance;
const int rs = 12, en = 8, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Setup pin modes and LCD
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  Serial.begin(9600); // Start serial communication
}

int loops = 0;

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Read the echo pin
  duration = pulseIn(echo, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;
  safeDistance = distance;

  // Handle safe distance
  if (safeDistance <= 5) {
    digitalWrite(buzz, HIGH);
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(buzz, LOW);
    digitalWrite(led, LOW);
  }

  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Display the distance on the LCD
  if (loops == 5) {
    char buffer[16]; // Create a buffer to hold the formatted string
    snprintf(buffer, sizeof(buffer), "Distance: %d cm", distance);
    lcd.setCursor(0, 0); // Set cursor to the first row
    lcd.print("                "); // Clear the previous content
    lcd.setCursor(0, 0); // Set cursor to the beginning of the first row
    lcd.print(buffer);   // Print the formatted string
    loops = 0;
  } else {
    loops += 1;
  }
}
