// comunicação com a interenet 
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>
#include "esp_wifi.h"
//#include <ESPmDNS.h>
// comunucação entre os componenetes
//#include <ADS1115.h>

const char *ssid = "Detector de fumaça inteligente";
const char *password = "12345678";

WiFiServer server(80);

const char *root =R"====( <head>
<title> esp_3280</title>
</head>
<body> 
  HElo :3

 </body> 
 </html> 
)====";

void setup() {
 Serial.begin(9600);

  esp_wifi_set_ps(WIFI_PS_NONE);
  WiFi.setSleep(false);
 Serial.println();
 Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid, password);
  IPAddress local_IP(192,168,1,2); 
  IPAddress gateway(192,168,1,1);
  IPAddress subnet(255,255,255,0);
  // IPAddress local_IP = WiFi.softAPIP();
  WiFi.softAPConfig(local_IP, gateway, subnet);
  Serial.print("AP IP address: ");
  Serial.println(local_IP);
  server.begin();

  Serial.println("Server started");
}



void loop() {
 
WiFiClient client = server.available();
   // Listen for incoming clients
client.println("<html>");
client.println(root);
client.println("</html>");

}          
