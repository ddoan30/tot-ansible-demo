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
  
  if (incoming == "OK"){
    digitalWrite(relay, LOW);
  }

  // Only run if the state has changed
  if (currentSensorStatus != lastSensorStatus) {
    if (currentSensorStatus == HIGH) {
      digitalWrite(relay, HIGH); 
      Serial.println("sixseven"); // Send ONCE when triggered
    } 
    
    // Update the tracker
    lastSensorStatus = currentSensorStatus;
    delay(50); // Small debounce to prevent noise
  }
}
