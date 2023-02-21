// defines pins numbers
const int front_trigPin = 8;
const int front_echoPin = 9;
const int left_trigPin = 10;
const int left_echoPin = 11;
const int right_trigPin = 12;
const int right_echoPin = 13;

// Motor right connections
int enA = 7;
int in1 = 6;
int in2 = 5;
// Motor left connections
int enB = 2;
int in3 = 3;
int in4 = 4;

// defines variables
long font_duration;
int front_distance;
long left_duration;
int left_distance;
long right_duration;
int right_distance;


void setup() {
  pinMode(front_trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(front_echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(left_trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(left_echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(right_trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(right_echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(enA, 255);
  analogWrite(enB, 255);
  stope();
  delay(1000);
}

void loop() {
  // Clears the trigPin
  digitalWrite(front_trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(front_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(front_trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  font_duration = pulseIn(front_echoPin, HIGH);
  // Calculating the distance
  front_distance = font_duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(front_distance);
  if(front_distance < 30){
    //left side sensor
    // Clears the trigPin
    digitalWrite(left_trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(left_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(left_trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    left_duration = pulseIn(left_echoPin, HIGH);
    // Calculating the distance
    left_distance = left_duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print("Left Distance: ");
    Serial.println(left_distance);

    //right side sensor
    // Clears the trigPin
    digitalWrite(right_trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(right_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(right_trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    right_duration = pulseIn(right_echoPin, HIGH);
    // Calculating the distance
    right_distance = right_duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print("Right Distance: ");
    Serial.println(right_distance);
    if((left_distance > right_distance) && (left_distance >= 30)){
      //go left
      left();
    } else if((right_distance > left_distance) && (right_distance >= 30)) {
      //go right
      right();
      }
    else{
      reverse();
    }
    }else {
      forward();
      }
}

void stope(){
   // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }
void forward(){
  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }

void reverse(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  }
  
void left(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }

void right(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  }
