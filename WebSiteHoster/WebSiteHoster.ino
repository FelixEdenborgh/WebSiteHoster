#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include "Functions.h"

static char *ssid = "IoT";
static char *pass = "IoT2018!";
ESP8266WebServer myserver(80); // port 80 = HTTP, port 443 = HTTPS(Kräver SSL-certifikat)

void showText(){
  //200 = OK, 201 = Created, 403 = Forbidden, 404 = Not Found, 500 = Internal Server error, Status codes 
  myserver.send(200, "text/plain", "Här är min text jag skrivit. "); 
}


void setup() {
  Serial.begin(115200);
  initWifi(ssid, pass);
  myserver.on("/", showText); 
  myserver.begin();
}

void loop() {
  myserver.handleClient();
}
