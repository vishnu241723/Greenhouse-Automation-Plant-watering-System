#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <AceButton.h>

using namespace ace_button;

#include "config.h"
#include "sensors.h"
#include "display.h"
#include "control.h"

char auth[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;

ButtonConfig config1;
AceButton relayButton(&config1);

ButtonConfig config2;
AceButton modeButton(&config2);

/************ BLYNK ************/
BLYNK_CONNECTED(){
  Blynk.syncAll();
}

BLYNK_WRITE(VPIN_RELAY){
  if(!autoMode){
    toggleRelay = param.asInt();
    digitalWrite(RelayPin, toggleRelay);
  }
}

BLYNK_WRITE(VPIN_MODE){
  autoMode = param.asInt();
  currMode = autoMode ? "A" : "M";
  digitalWrite(ModeLed, autoMode);
  controlBuzzer(500);
}

/************ BUTTON HANDLERS ************/
void relayButtonHandler(AceButton*, uint8_t eventType, uint8_t){
  if(eventType == AceButton::kEventReleased && !autoMode){
    toggleRelay = !toggleRelay;
    digitalWrite(RelayPin, toggleRelay);
    Blynk.virtualWrite(VPIN_RELAY, toggleRelay);
  }
}

void modeButtonHandler(AceButton*, uint8_t eventType, uint8_t){
  if(eventType == AceButton::kEventReleased){
    autoMode = !autoMode;
    currMode = autoMode ? "A" : "M";
    digitalWrite(ModeLed, autoMode);
    Blynk.virtualWrite(VPIN_MODE, autoMode);
    controlBuzzer(500);
  }
}

void sendSensor(){
  getMoisture();
  getWeather();

  displayData(String(moisturePercentage) + "%",
              "T:" + String(temperature1) + "C H:" + String(humidity1) + "% " + currMode);

  Blynk.virtualWrite(VPIN_MOISTURE, moisturePercentage);
  Blynk.virtualWrite(VPIN_TEMPERATURE, temperature1);
  Blynk.virtualWrite(VPIN_HUMIDITY, humidity1);
}

void setup(){
  Serial.begin(115200);

  pinMode(RelayPin, OUTPUT);
  pinMode(wifiLed, OUTPUT);
  pinMode(ModeLed, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);

  pinMode(RelayButtonPin, INPUT_PULLUP);
  pinMode(ModeSwitchPin, INPUT_PULLUP);

  dht.begin();

  config1.setEventHandler(relayButtonHandler);
  relayButton.init(RelayButtonPin);

  config2.setEventHandler(modeButtonHandler);
  modeButton.init(ModeSwitchPin);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
  }

  digitalWrite(wifiLed, HIGH);

  Blynk.config(auth);
  Blynk.connect();

  timer.setInterval(3000L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
  relayButton.check();
  modeButton.check();
  controlMoist();
}
