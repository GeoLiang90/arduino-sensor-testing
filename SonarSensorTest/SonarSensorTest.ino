//Defining Constants
//Digital pins
const int triggPin = 11;
const int echoPin = 13;

long travelTime;
int distance;

//Ground is GND and Vcc was connected to 5V
void setup() {
  //changing pinMode
  pinMode(triggPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Mostly for display board
  Serial.begin(9600);
}

void loop() {
  //Toggle pin with digitalWrite
  //Low is off
  digitalWrite(triggPin, LOW);
  delayMicroseconds(3);
  //Generate a pulse by setting pin to HIGH 
  digitalWrite(triggPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggPin, LOW);
  //pulseIn will wait for a Pin to go high and times how long it takes to go low
  travelTime = pulseIn(echoPin, HIGH);
  //Speed of sound wave in microseconds
  //Sound wave also travels forward and bounces backwards
  distance = travelTime * 0.034/2;
  //Print result on serial
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  //Test was accurate starting at about 5cm
}
