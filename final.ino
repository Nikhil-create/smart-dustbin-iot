#define trigger 5
#define echo 4
#define BLYNK_PRINT Serial  
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "code_cend_by_blynk_app";
char ssid[] = "your_wifi_name";
char pass[] = "your_wifi_password";

void setup()
{
  Serial.begin (9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}
void loop()
{
 
  long duration, distance;
  digitalWrite(trigger, LOW);  
  delayMicroseconds(2);
 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
 
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
  Blynk.virtualWrite(V0, distance);
  if(distance < 8){
    Blynk.email("Your_email", "SMART D ", "FULL");
  }

Blynk.run();
}
