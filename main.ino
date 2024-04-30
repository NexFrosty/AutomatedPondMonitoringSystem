#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "blynktemplateid"
#define BLYNK_TEMPLATE_NAME "Pond Monitoring System"
#define BLYNK_AUTH_TOKEN "blynkauthtoken"

#define TRIGGER_PIN  D6
#define ECHO_PIN     D5
#define MAX_DISTANCE 400 

#define ONE_WIRE_BUS D4

#define waterpum1 D1
#define waterpum2 D2
#define waterpum3 D7
#define waterpum4 D8

#include <NewPing.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <BlynkSimpleEsp8266.h>

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Blynk.begin(BLYNK_AUTH_TOKEN, "wifiname", "wifipassword");
  sensors.begin();
  pinMode(waterpum1, OUTPUT);
  pinMode(waterpum2, OUTPUT);
  pinMode(waterpum3, OUTPUT);
  pinMode(waterpum4, OUTPUT);

  Blynk.virtualWrite(V5, "Temperature (°C)");
  Blynk.virtualWrite(V6, "Distance (cm)");
  Blynk.virtualWrite(V7, "Turbidity");
}

void loop() {
  Blynk.run();
  delay(1000);               
       
  sensors.requestTemperatures();
  int distance = sonar.ping_cm(); 
  int turbidity = analogRead(A0);
  float tempC = sensors.getTempCByIndex(0);
  
  Blynk.virtualWrite(V5, tempC);
  Blynk.virtualWrite(V6, distance);
  Blynk.virtualWrite(V7, turbidity);

  if (turbidity < 85){
    digitalWrite(waterpum2, LOW);
  } else {
    digitalWrite(waterpum2, HIGH);
  }
  if (distance > 3){
    digitalWrite(waterpum1, LOW);
  } else {
    digitalWrite(waterpum1, HIGH);
  }
  if (tempC < 25){
    digitalWrite(waterpum4, LOW);
  } else {
    digitalWrite(waterpum4, HIGH);
  }
  if (tempC > 32){
    digitalWrite(waterpum3, LOW);
  } else {
    digitalWrite(waterpum3, HIGH);
  }
}

