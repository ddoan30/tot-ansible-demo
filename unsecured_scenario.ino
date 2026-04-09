const int sensor = 8; 
const int relay = 13; 

int x = 0;
int y = 0;
int lastSensorStatus = 0;

void setup() {
  // sets relay pin 13 to output AND sensor pin 8 to input
  pinMode(relay, OUTPUT); 

  pinMode(sensor, INPUT); 
}

void loop(){
  // create unsecured scenario
  if (digitalRead(sensor) == HIGH){
    digitalWrite(relay, HIGH);
  }

}
