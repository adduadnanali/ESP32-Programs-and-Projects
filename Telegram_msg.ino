

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include "DHT.h"
DHT dht(15,DHT11);

// Wifi network station credentials
#define WIFI_SSID "LG"
#define WIFI_PASSWORD "getjar123"
// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "5488242344:AAFp8ZiCqbYHC2yt4XICWuMPmNBnjqmFXws"

// Use @myidbot (IDBot) to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "1441821453"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

void setup() {
  Serial.begin(115200);
  Serial.println();
  dht.begin();
  
 // attempt to connect to Wifi network:
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(5000);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);

  bot.sendMessage(CHAT_ID, "Bot started up", "");
}

void loop() {
  float temperature, humidity;
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  
  if(temperature > 30) {
    bot.sendMessage(CHAT_ID, "ALERT!!TEMPERATURE IS ABOVE 30 ", ""); // parse mode is emptystring 
  }
}
