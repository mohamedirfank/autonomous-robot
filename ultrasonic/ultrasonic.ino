// defines pins numbers
const int front_trigPin = 8;
const int front_echoPin = 9;
const int left_trigPin = 10;
const int left_echoPin = 11;
const int right_trigPin = 12;
const int right_echoPin = 13;

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
    if(left_distance > right_distance){
      //go left
    } else {
      //go right
      
      }
    }
}
