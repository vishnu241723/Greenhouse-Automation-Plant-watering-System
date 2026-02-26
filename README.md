# 🌱 ESP32 Smart Plant Monitoring System

An IoT-based smart irrigation system built using ESP32, soil moisture sensor, DHT11, OLED display, and the Blynk IoT platform.
This system monitors soil moisture, temperature, and humidity in real time and automatically controls watering based on predefined thresholds.

🚀 Features

📡 WiFi-enabled remote monitoring using Blynk

🌡️ Temperature & Humidity monitoring (DHT11)

💧 Soil moisture sensing with percentage mapping

🔁 Automatic irrigation mode

🎛️ Manual control mode (App + Physical Button)

🖥️ OLED live data display

🔔 Buzzer alert on mode change

💡 WiFi & Mode status LED indicators

🛠️ Hardware Components

ESP32 Development Board

Soil Moisture Sensor

DHT11 Temperature & Humidity Sensor

0.96” I2C OLED Display (SSD1306)

Relay Module

Buzzer

Push Buttons (Manual Control & Mode Switch)

Connecting Wires

📲 Blynk Virtual Pins
Virtual Pin	Function
V1	Soil Moisture (%)
V2	Temperature (°C)
V3	Humidity (%)
V4	Mode Switch (Auto/Manual)
V5	Relay Control
⚙️ Working Principle

The soil moisture sensor reads analog values from the soil.

Values are mapped into percentage (0–100%).

If moisture drops below the minimum threshold, the relay turns ON (watering starts).

If moisture exceeds the maximum threshold, watering stops.

In Manual Mode, the user can control the pump via Blynk app or hardware button.

All data is displayed on the OLED screen and synced to the Blynk cloud.

🔐 Important

Before uploading the code:

Replace:

#define BLYNK_AUTH_TOKEN "YOUR_NEW_AUTH_TOKEN"
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

⚠️ Never upload your real WiFi password or Auth Token to public repositories.

📦 Libraries Required

Install these from Arduino Library Manager:

Blynk

Adafruit SSD1306

Adafruit GFX

DHT Sensor Library

AceButton

🧠 Applications

Smart irrigation systems

Home gardening automation

Greenhouse monitoring

IoT-based agriculture projects

Final year / Mini IoT projects
