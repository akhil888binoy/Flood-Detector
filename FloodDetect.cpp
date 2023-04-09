// define the pin for the water level sensor
int waterLevelPin = A0;

// set the threshold for the water level sensor
int threshold = 500;

void setup() {
  // initialize the serial communication
  Serial.begin(9600);
}

void loop() {
  // read the value from the water level sensor
  int waterLevel = analogRead(waterLevelPin);
  
  // check if the water level is above the threshold
  if (waterLevel > threshold) {
    // send a message to the traffic control system
    String message = "Flood detected on road X. Water level: " + String(waterLevel) + ". Time: " + String(millis());
    Serial.println(message);
    // delay for 1 minute before sending another message
    delay(60000);
  }
}
