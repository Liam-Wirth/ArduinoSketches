// Pin definitions
#define ENA 3  // Enable pin for the left motor
#define ENB 4  // Enable pin for the right motor

#define IN1 5  // Control pin 1 for the left motor
#define IN2 6  // Control pin 2 for the left motor
#define IN3 7  // Control pin 1 for the right motor
#define IN4 8  // Control pin 2 for the right motor

#define carSpeed 100     // Speed for forward/backward movement
#define carSpeedTurn 200 // Speed for turning

// Function to move the car forward
void forward(int time){
    digitalWrite(ENA, HIGH);   // Enable left motor
    digitalWrite(ENB, HIGH);   // Enable right motor
    digitalWrite(IN1, HIGH);   // Set left motor to move forward
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);   // Set right motor to move forward
    digitalWrite(IN4, HIGH);
    Serial.println("vroom vroom");
    delay(time);               // Move for the specified time
}

// Function to move the car backward
void back(int time){
    digitalWrite(ENA, HIGH);   // Enable left motor
    digitalWrite(ENB, HIGH);   // Enable right motor
    digitalWrite(IN1, HIGH);   // Set left motor to move backward
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);    // Set right motor to move backward
    digitalWrite(IN4, LOW);
    Serial.println("beep beep");
    delay(time);               // Move for the specified time
}

// Function to turn the car left
void left(int time){
    analogWrite(ENA, carSpeedTurn); // Set left motor speed
    analogWrite(ENB, carSpeed);     // Set right motor speed
    digitalWrite(IN1, HIGH);        // Left motor forward
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);        // Right motor forward
    digitalWrite(IN4, LOW);
    Serial.println("skrrt");
    delay(time);                    // Turn for the specified time
}

// Function to turn the car right
void right(int time){
    analogWrite(ENA, carSpeed);     // Set left motor speed
    analogWrite(ENB, carSpeedTurn); // Set right motor speed
    digitalWrite(IN1, LOW);         // Left motor backward
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);         // Right motor backward
    digitalWrite(IN4, HIGH);
    Serial.println("skrrt");
    delay(time);                    // Turn for the specified time
}

// Function to stop the car
void stop(int time){
    digitalWrite(ENA, LOW);         // Disable left motor
    digitalWrite(ENB, LOW);         // Disable right motor
    digitalWrite(IN1, LOW);         // Stop left motor
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);         // Stop right motor
    digitalWrite(IN4, LOW);
    Serial.println("skeert");
    delay(time);                    // Stop for the specified time
}

// Arduino setup function, runs once when the program starts
void setup(){
    Serial.begin(9600);             // Initialize serial communication
    pinMode(ENA, OUTPUT);           // Set motor control pins as outputs
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    stop(1);                        // Ensure the car is stopped initially
}

// Function to curve left
void curveleft(int speed, float curve){
    analogWrite(ENA, speed);        // Set speed for left motor
    analogWrite(ENB, speed * curve);// Set speed for right motor
    digitalWrite(IN1, HIGH);        // Left motor forward
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);         // Right motor backward
    digitalWrite(IN4, LOW);
}

// Function to curve right
void curveright(int speed, float curve){
    analogWrite(ENA, speed);        // Set speed for left motor
    analogWrite(ENB, speed * curve);// Set speed for right motor
    digitalWrite(IN1, LOW);         // Left motor backward
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);         // Right motor backward
    digitalWrite(IN4, LOW);
}

// Function to navigate through a predefined maze
void maze1(){
    forward(1500);                  // Move forward for 1500 ms
    right(500);                     // Turn right for 500 ms
    forward(1000);                  // Move forward for 1000 ms
    left(400);                      // Turn left for 400 ms
    forward(1000);                  // Move forward for 1000 ms
    left(500);                      // Turn left for 500 ms
    forward(100);                   // Move forward for 100 ms
    back(500);                      // Move backward for 500 ms
    left(2000);                     // Turn left for 2000 ms
    stop(990000);                   // Stop for a long duration
}

// Arduino main loop function, runs repeatedly
void loop() {

}

