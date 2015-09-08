#include <SPI.h> // needed in Arduino 0019 or later
#include <Ethernet.h>
#include <Twitter.h>

// The includion of EthernetDNS is not needed in Arduino IDE 1.0 or later.
// Please uncomment below in Arduino IDE 0022 or earlier.
//#include <EthernetDNS.h>


// Ethernet Shield Settings
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// If you don't specify the IP address, DHCP is used(only in Arduino 1.0 or later).
byte ip[] = { 10, 0, 0, 15 };

// Your Token to Tweet (get it from http://arduino-tweet.appspot.com/)
Twitter twitter("3491000954-JoQ3TcuAGX3C6vFHQoAiWZyO0QUECz2EbO2CWrd");

// Message to post
char msg[] = "Hello, World! I'm Arduino!";

void setup()
{
 // or you can use DHCP for autoomatic IP address configuration.
 // Ethernet.begin(mac);
  Serial.begin(9600);
  
  delay(1000);
Ethernet.begin(mac,ip);


  Serial.println(Ethernet.localIP());
  
  Serial.println("connecting ...");
  if (twitter.post(msg)) {
    // Specify &Serial to output received response to Serial.
    // If no output is required, you can just omit the argument, e.g.
    // int status = twitter.wait();
    int status = twitter.wait(&Serial);
    if (status == 200) {
      Serial.println("OK.");
    } else {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }
}

void loop()
{
}