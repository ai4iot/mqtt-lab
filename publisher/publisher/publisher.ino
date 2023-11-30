#include <WiFi.h>
#include <PubSubClient.h>

const char * ssid = "ASUS_GRAM";
const char * password = "GramLab0rat0ri0";


const char * broker_ip = "192.168.77.106"

WiFiClient esp_client;

PubSubClient mqtt_client(esp_client);

void setup_wifi();


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  setup_wifi();

  Serial.println("Connected to WiFi");

  



}

void loop() {
  // put your main code here, to run repeatedly:

}


void setup_wifi(){

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi.");
  while (WiFi.status() != WL_CONNECTED)
       {  delay(500);
          Serial.print(".") ;
       }


}