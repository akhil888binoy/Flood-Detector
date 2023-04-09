# Flood Detector
This project uses an Arduino board and a water level sensor to detect floods on a road and send a message to the traffic control system to redirect traffic.

# Components
Arduino board (e.g. Uno or Mega)
Water level sensor (e.g. YF-S201)
Ethernet shield (e.g. W5100)
# Wiring
Connect the water level sensor to the Arduino board as follows:

VCC -> 5V
GND -> GND
SIG -> A0
Connect the Ethernet shield to the Arduino board as follows:

5V -> 5V
GND -> GND
SS -> D10
MOSI -> D11
MISO -> D12
SCK -> D13
RST -> D4
# Installation
Clone this repository to your computer.
Open the Arduino IDE and select File > Open.
Navigate to the cloned repository and open the FloodDetector.ino file.
Upload the code to the Arduino board.
Connect the Ethernet shield to a network with internet access.
# Configuration
Edit the config.h file with the necessary configuration parameters:

SENSOR_THRESHOLD: The threshold value for the water level sensor, in centimeters.
SERVER_ADDRESS: The IP address or domain name of the server that receives the flood alert messages.
SERVER_PORT: The port number used by the server to receive messages.
# Usage
When the water level rises above the threshold value, the Flood Detector sends an alert message to the server. The message contains the date and time of the alert, the sensor value, and a status code indicating the severity of the flood.

# License
This project is licensed under the MIT License. See the LICENSE file for details.



