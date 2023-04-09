#include <Ethernet.h>
#include <SPI.h>

// define the MAC and IP address for the Ethernet shield
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 1, 177);

// define the address and port of the traffic control system
IPAddress server(192, 168, 1, 100);
int port = 8080;

EthernetClient client;

void setup() {
  // initialize the serial communication
  Serial.begin(9600);
  
  // initialize the Ethernet shield
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
  }
  else {
    Serial.print("Ethernet connection established. IP address: ");
    Serial.println(Ethernet.localIP());
  }
}

void loop() {
  // read the value from the water level sensor and check if it's above the threshold
  // ...
  
  // if flood is detected, send a message to the traffic control system
  if (waterLevel > threshold) {
    if (client.connect(server, port)) {
      String message = "Flood detected on road X. Water level: " + String(waterLevel) + ". Time: " + String(millis());
      client.println("GET /redirect_traffic?message=" + message + " HTTP/1.1");
      client.println("Host: " + String(server));
      client.println("Connection: close");
      client.println();
      delay(1000);
      client.stop();
    }
    else {
      Serial.println("Connection to the traffic control system failed");
    }
    // delay for 1 minute before sending another message
    delay(60000);
  }
}
