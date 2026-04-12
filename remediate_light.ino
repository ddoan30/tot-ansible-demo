const int sensor = 8; 
const int relay = 13; 

int x = 0;
int y = 0;
int lastSensorStatus = 0;

void setup() {
  // sets relay pin 13 to output AND sensor pin 8 to input
  Serial.begin(96000);
  
  pinMode(relay, OUTPUT); 

  pinMode(sensor, INPUT); 
}

void loop(){
  // remediate: if light not on, turn it on
  if (digitalRead(relay) != LOW){
    digitalWrite(relay, LOW);
    Serial.println("Fixed");
  }

}
