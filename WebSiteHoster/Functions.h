void initWifi(char *ssid, char *pass){
  Serial.printf("Connecting to SSID: %s.\r\n", ssid);
  WiFi.begin(ssid, pass);
  Serial.print("Loading.");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected to WiFi.");

  uint8_t mac[6];
  WiFi.macAddress(mac);
  Serial.printf("MAC: %02x:%02x:%02x:%02x:%02x:%02x\r\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  
    
}
