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
  // read in signals of sensor and relay
  x = digitalRead(sensor);
  y = digitalRead(relay);

  // default light status is ON 
  digitalWrite(relay, LOW);

  // logic: while sensor gets input --> light status is OFF
  // aka: light is off while finger is on sensor
  while (x == HIGH){
    digitalWrite(relay, HIGH);
    x = digitalRead(sensor);
  }
  digitalWrite(relay, LOW);

}
