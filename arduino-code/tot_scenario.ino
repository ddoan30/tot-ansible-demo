const int sensor = 8; 
const int relay = 13; 

int x = 0;
int y = 0;
//int lastSensorStatus = 0;

int lastSensorStatus = LOW; 
String incoming;

void setup() {
  pinMode(relay, OUTPUT); 
  pinMode(sensor, INPUT); 
  Serial.begin(9600);
}

void loop(){
  int currentSensorStatus = digitalRead(sensor);
  int currentRelayStatus = digitalRead(relay);
  incoming = Serial.readStringUntil('\n');

  // turns light on if reads OK from serial -- sync.py sends "OK"
  if (incoming == "OK"){
    digitalWrite(relay, LOW);
  }

  // only run if the state has changed
  if (currentSensorStatus != lastSensorStatus) {
    if (currentSensorStatus == HIGH) { //if sensor touched, print 67 to serial
      digitalWrite(relay, HIGH); 
      Serial.println("sixseven"); 
    } 
    
    // Update the tracker
    lastSensorStatus = currentSensorStatus;
    delay(50); 
  }
}
