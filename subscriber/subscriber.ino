#include <WiFi.h>
#include <PubSubClient.h>

const char * ssid = "******";
const char * password = "******";


const char * broker_ip = "******";
const uint16_t mqtt_port = 1883;

const int pinR = 15;
const int pinG = 16;
const int pinB = 17;

WiFiClient esp_client;
PubSubClient mqtt_client(esp_client);


void setup_wifi();
void init_mqtt();
void connect_mqtt();
void handdle_qmtt();
boolean mqtt_subscribe(String topic);
void OnMqttReceiver(char * topic, byte * payload, unsigned int length);
void updateLedColor(int distance);

void setup() {
  // put your setup code here, to run once:


  Serial.begin(115200);

  setup_wifi();

  init_mqtt();

  connect_mqtt();


  Serial.println("\n Ok");


}

void loop() {
  // put your main code here, to run repeatedly:

  handdle_qmtt();

}


void OnMqttReceiver(char * topic, byte * payload, unsigned int length){


  Serial.print("Received on ");
  Serial.print(topic);
  Serial.print(": ");

  String content = "";
  for (size_t i = 0; i < length; i++){
        content.concat((char)payload[i]);
  }
  Serial.print(content);
  Serial.println();
  int distance = content.toInt();
  updateLedColor(distance);

}


boolean mqtt_subscribe(String topic){

  return mqtt_client.subscribe(topic.c_str());

}

void init_mqtt(){

  Serial.print("Connect to MQTT -");
  Serial.print(broker_ip);
  Serial.print("-");
  Serial.println(mqtt_port);

  mqtt_client.setServer(broker_ip, mqtt_port);

  mqtt_client.setCallback(OnMqttReceiver);

}

void connect_mqtt(){

  while(!mqtt_client.connected()){

    Serial.print("Connecting to MQTT");

    if (mqtt_client.connect("ESP32Client"))
           Serial.println("connected");
       
    else{   
           Serial.print("failed with state ");
           Serial.print(mqtt_client.state());
           delay(500);
       }
  }


}

void handdle_qmtt(){

  if(!mqtt_client.connected()){

    connect_mqtt();

  }

  mqtt_client.loop();

}

void setup_wifi(){

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi.");
  while (WiFi.status() != WL_CONNECTED)
       {  delay(500);
          Serial.print(".") ;
       }

  Serial.println("Connected to WiFi");

}

void updateLedColor(int distance)
{
  if (distance < 50)
  {
    analogWrite(pinR, 255);
    analogWrite(pinG, 0);
    analogWrite(pinB, 0);
  }
  else if (distance < 100)
  {
    analogWrite(pinR, 0);
    analogWrite(pinG, 255);
    analogWrite(pinB, 0);
  }
  else
  {
    analogWrite(pinR, 0);
    analogWrite(pinG, 0);
    analogWrite(pinB, 255);
  }
}