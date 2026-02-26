#ifndef CONFIG_H
#define CONFIG_H

/************ BLYNK CONFIG ************/
#define BLYNK_TEMPLATE_ID "TMPL35lD4PCXf"
#define BLYNK_TEMPLATE_NAME "ESP 32 Plant Monitor"
#define BLYNK_AUTH_TOKEN "YOUR_NEW_AUTH_TOKEN"

/************ WIFI ************/
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

/************ SOIL CALIBRATION ************/
int wetSoilVal = 930;   
int drySoilVal = 3000;  

int moistPerLow = 20;   
int moistPerHigh = 80;  

/************ PIN DEFINITIONS ************/
#define SensorPin       34
#define DHTPin          14
#define RelayPin        25
#define wifiLed         2
#define RelayButtonPin  32
#define ModeSwitchPin   33
#define BuzzerPin       26
#define ModeLed         15

/************ BLYNK VIRTUAL PINS ************/
#define VPIN_MOISTURE    V1
#define VPIN_TEMPERATURE V2
#define VPIN_HUMIDITY    V3
#define VPIN_MODE        V4
#define VPIN_RELAY       V5

#endif
