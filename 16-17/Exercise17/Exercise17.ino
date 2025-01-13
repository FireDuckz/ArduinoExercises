#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
const char* ssid = "Worst&SmellyHotspot";
const char* pass = "nsvq0894";
WiFiClient client;

unsigned long channelID = 2808227; //your TS channal
const char * APIKey = "EOTDESBGZ3ZRRTKO"; //your TS API
const char* server = "api.thingspeak.com";
const int postDelay = 20 * 1000; //post data every 20 seconds

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
}
float data; //measured data
float Volts;
void loop() {
  Volts = analogRead(A0);
  data = WiFi.RSSI();
  ThingSpeak.begin(client);
  client.connect(server, 80); //connect(URL, Port)
  ThingSpeak.setField(1, data); //set data on the X graph
  ThingSpeak.setField(2,Volts);
  ThingSpeak.writeFields(channelID, APIKey); //post everything to TS
  client.stop();
  delay(postDelay); //wait and then post again
}