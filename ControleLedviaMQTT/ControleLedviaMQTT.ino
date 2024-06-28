#include <Adafruit_BMP085.h>

#define LED 2 // GPIO 5 (D1) for LED
bool ledState = false;

Adafruit_BMP085 bmp;
#include <PubSubClient.h>
#include <WiFi.h>

// WiFi
const char* ssid = "";                
const char* wifi_password = "";

// MQTT
const char* mqtt_server = ""; 
const char* light_topic = "home/sensor2/light";
const char* mqtt_username = ""; // MQTT username
const char* mqtt_password = ""; // MQTT password
const char* clientID = "Light_Control"; // MQTT client ID

// Initialise the WiFi and MQTT Client objects
WiFiClient wifiClient;

// 1883 is the listener port for the Broker
PubSubClient client(mqtt_server, 1883, wifiClient);

 

// Custom function to connect to the MQTT broker via WiFi
void connect_MQTT(){
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Connect to the WiFi
  WiFi.begin(ssid, wifi_password);

  // Wait until the connection is confirmed
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Debugging – Output the IP Address of the ESP8266
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Connect to MQTT Broker
  if (client.connect(clientID, mqtt_username, mqtt_password)) {
    Serial.println("Connected to MQTT Broker!");
    client.subscribe(light_topic);
  }
  else {
    Serial.println("Connection to MQTT Broker failed…");
  }
}

void mqttCallback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message received on topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    String message;
    for (int i = 0; i < length; i++) {
        message += (char) payload[i];  // Convert *byte to string
    }
    // Control the LED based on the message received
    if (message == "on" && !ledState) {
        digitalWrite(LED, HIGH);  // Turn on the LED
        ledState = true;
        Serial.println("LED is turned on");
    }
    if (message == "off" && ledState) {
        digitalWrite(LED, LOW); // Turn off the LED
        ledState = false;
        Serial.println("LED is turned off");
    }
    Serial.println();
    Serial.println("-----------------------");
}



void setup() {
  Serial.begin(9600);
  client.setCallback(mqttCallback);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (!client.connected()) {
      connect_MQTT();
  }  
  client.loop();
}
  

  

