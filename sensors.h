#ifndef SENSORS_H
#define SENSORS_H

#include <DHT.h>

#define DHTTYPE DHT11

DHT dht(DHTPin, DHTTYPE);

int sensorVal;
int moisturePercentage;
int temperature1 = 0;
int humidity1 = 0;

void getMoisture() {
  sensorVal = analogRead(SensorPin);
  moisturePercentage = map(sensorVal, drySoilVal, wetSoilVal, 0, 100);
  moisturePercentage = constrain(moisturePercentage, 0, 100);
}

void getWeather() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (!isnan(h) && !isnan(t)) {
    humidity1 = int(h);
    temperature1 = int(t);
  }
}

#endif
