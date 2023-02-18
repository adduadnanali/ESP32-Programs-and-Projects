#include<WiFi.h>
#include<DHT.h>
DHT dht(15,DHT11);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(hum)||isnan(temp))
  {
     return;
  }

  Serial.print("#");
  Serial.print(",");
  Serial.print(hum);
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.println("~");
  delay(4000);
  

}
