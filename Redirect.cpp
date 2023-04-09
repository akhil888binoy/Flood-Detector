#include <Ethernet.h>
#include <SPI.h>

// define the MAC and IP address for the Ethernet shield
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 1, 177);

// define the address and port of the traffic control system
IPAddress server(192, 168, 1, 100);
int port = 8080;

