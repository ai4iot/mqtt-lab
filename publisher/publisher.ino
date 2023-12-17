#include <WiFi.h>
#include <PubSubClient.h>

#define TRIG_PIN 11
#define ECHO_PIN 12

#define SOUND_SPEED 340
#define TRIG_PULSE_DURATION_US 10

long ultrasonic_duration;
float distance_cm;
char buffer[20];

const char * ssid = "******";
const char * password = "******";


const char * broker_ip = "******";
const uint16_t mqtt_port = 1883;

WiFiClient esp_client;

PubSubClient mqtt_client(esp_client);

void setup_wifi();
void init_mqtt();
void connect_mqtt();
void handdle_qmtt();
void mqtt_publish(String topic, char * payload);

float get_distance();


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  setup_wifi();

  init_mqtt();

  connect_mqtt();
  

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);


  Serial.println("\n Ok");



}

void loop() {
  // put your main code here, to run repeatedly:
  handdle_qmtt();
  distance_cm = get_distance();
  sprintf(buffer, "%.2f", distance_cm);
  Serial.println(distance_cm);
  mqtt_publish("esp32/distance", buffer);
  delay(300);

}



float get_distance(){


  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(TRIG_PULSE_DURATION_US);
  digitalWrite(TRIG_PIN, LOW);

  ultrasonic_duration = pulseIn(ECHO_PIN, HIGH);

  return ultrasonic_duration * SOUND_SPEED/2*0.0001;



}

void mqtt_publish(String topic, char * payload){


  mqtt_client.publish(topic.c_str(), payload);



}

void init_mqtt(){

  Serial.print("Connect to MQTT -");
  Serial.print(broker_ip);
  Serial.print("-");
  Serial.println(mqtt_port);

  mqtt_client.setServer(broker_ip, mqtt_port);
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