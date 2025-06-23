#define trigPin 9
#define echoPin 10
#define buzzer 8

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Receive echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 50) {  // obstacle within 50cm
    digitalWrite(buzzer, HIGH);  // turn on buzzer
    delay(200);  // beep duration
    digitalWrite(buzzer, LOW);
    delay(200);  // interval between beeps
  } else {
    digitalWrite(buzzer, LOW);  // buzzer off
  }

  delay(100);
}
