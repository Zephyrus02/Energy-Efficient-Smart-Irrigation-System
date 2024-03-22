#define BLYNK_TEMPLATE_ID "TMPL35WqK7b-2"
#define BLYNK_TEMPLATE_NAME "soilmoisture"
#define BLYNK_AUTH_TOKEN "_Dc8Y5MGHBEZFUp9A1b4MofKsXmReYoN"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 2




char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "";  // type your wifi name
char pass[] = "";  // type your wifi password

BlynkTimer timer;

    BLYNK_WRITE(V3)
    {
      Serial.println("HI");
      int x = param.asInt(); // assigning incoming value from pin V5 to a variable
      // You can also use:
      // String i = param.asStr();
      // double d = param.asDouble();
      Serial.println(x);
      
      if(x == 0)
        digitalWrite(D0,LOW);
      else
        digitalWrite(D0,HIGH);

    }



void sendSensor()
{
  /*int soilmoisturevalue = analogRead(A0);
   soilmoisturevalue = map(soilmoisturevalue, 0, 1023, 0, 100);*/
   int value = analogRead(A0);
    int chk = DHT.read11(DHT11_PIN);
            


  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V2, value);
    Blynk.virtualWrite(V0, DHT.temperature);
    Blynk.virtualWrite(V1, DHT.humidity);
    Serial.print("Soil Moisture : ");
    Serial.print(value);
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    delay(1000);

}
void setup()
{   
  
  Serial.begin(9600);
  pinMode(D0,OUTPUT);

  

  Blynk.begin(auth, ssid, pass);
    timer.setInterval(100L, sendSensor);
 
  }

void loop()
{
  Blynk.run();
  timer.run();
 }