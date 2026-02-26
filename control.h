#ifndef CONTROL_H
#define CONTROL_H

bool toggleRelay = LOW;
bool autoMode = true;
String currMode = "A";

void controlBuzzer(int duration){
  digitalWrite(BuzzerPin, HIGH);
  delay(duration);
  digitalWrite(BuzzerPin, LOW);
}

void controlMoist(){
  if(autoMode){
    if(moisturePercentage < moistPerLow){
      digitalWrite(RelayPin, HIGH);
      toggleRelay = HIGH;
      Blynk.virtualWrite(VPIN_RELAY, toggleRelay);
    }
    else if(moisturePercentage > moistPerHigh){
      digitalWrite(RelayPin, LOW);
      toggleRelay = LOW;
      Blynk.virtualWrite(VPIN_RELAY, toggleRelay);
    }
  }
}

#endif
