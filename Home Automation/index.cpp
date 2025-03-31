#include <WiFi.h>  // For ESP32
#include <BlynkSimpleEsp32.h>  // Use BlynkSimpleEsp8266.h for ESP8266

// Blynk Authentication Token
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

char ssid[] = "Your_WiFi_SSID";  // WiFi Name
char pass[] = "Your_WiFi_Password";  // WiFi Password

// Relay Pins (Connect to Lights, Fans, etc.)
#define LIGHT_PIN 4
#define FAN_PIN 5

void setup() {
    Serial.begin(115200);
    
    pinMode(LIGHT_PIN, OUTPUT);
    pinMode(FAN_PIN, OUTPUT);
    
    digitalWrite(LIGHT_PIN, LOW); // Initially OFF
    digitalWrite(FAN_PIN, LOW);

    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    Serial.println("Home Automation System Initialized.");
}

// Blynk Button to Control Light
BLYNK_WRITE(V1) {  
    int state = param.asInt();
    digitalWrite(LIGHT_PIN, state);
    Serial.println(state ? "Light ON" : "Light OFF");
}

// Blynk Button to Control Fan
BLYNK_WRITE(V2) {  
    int state = param.asInt();
    digitalWrite(FAN_PIN, state);
    Serial.println(state ? "Fan ON" : "Fan OFF");
}

void loop() {
    Blynk.run();
}