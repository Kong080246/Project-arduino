const int trigPin = 11;
const int echoPin = 12;

long duration;
int distance;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
}


void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance : ");
  Serial.println(distance);


  if (distance <= 4 ) {
    tone(13,400);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
  else {
    noTone(13);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
}