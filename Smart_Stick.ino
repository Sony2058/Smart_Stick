#define trigPin 9
#define echoPin 10
#define buzzerPin 8

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance (in cm)
  distance = duration * 0.0344 / 2;
  
  // If the distance is less than 30 cm, turn on the buzzer
  if (distance < 30) {
    digitalWrite(buzzerPin, HIGH);  // Buzzer ON
  } else {
    digitalWrite(buzzerPin, LOW);   // Buzzer OFF
  }
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100);
}
