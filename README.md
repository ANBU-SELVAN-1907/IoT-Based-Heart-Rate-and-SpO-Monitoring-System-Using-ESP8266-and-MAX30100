# IoT-Based-Heart-Rate-and-SpO-Monitoring-System-Using-ESP8266-and-MAX30100
his project presents an IoT-based health monitoring system that uses the MAX30100 pulse oximeter sensor to measure a user's heart rate and SpO₂ (oxygen saturation) levels. The data is collected by an ESP8266 NodeMCU, transmitted to a Firebase Realtime Database, and visualized on a lightweight Flask-based web dashboard

----------------------------------------------------------------------------ANBU-SELVAN------------------------------------------------------------------------------------------

# 💓 IoT Health Monitor with ESP8266 and MAX30100

This project demonstrates how to monitor **heart rate and SpO₂** using the **MAX30100** sensor and an **ESP8266** microcontroller. The readings are sent to a **Firebase Realtime Database** and can be visualized using a simple **Flask-based dashboard**.

---

## 🧠 Technologies Used

- ⚙️ **ESP8266** (e.g., NodeMCU)
- ❤️ **MAX30100** Pulse Oximeter and Heart Rate Sensor
- ☁️ **Firebase Realtime Database**
- 🌐 **Flask (Python micro-framework)**
- 🔁 **HTTP (REST API via ESP8266)**
- 📊 **Web Dashboard** for live visualization

---

## 🔧 Hardware Requirements

- ESP8266 NodeMCU (or compatible)
- MAX30100 Pulse Oximeter sensor
- Jumper wires
- Breadboard
- Wi-Fi connection

---

## 🔌 Circuit Diagram

| MAX30100 Pin | ESP8266 Pin |
|--------------|-------------|
| VCC          | 3.3V        |
| GND          | GND         |
| SDA          | D2 (GPIO4)  |
| SCL          | D1 (GPIO5)  |

> 📌 Use **3.3V only** for MAX30100 — 5V may damage the sensor.

---

## 🚀 ESP8266 Firmware Overview

- Reads heart rate and SpO₂ data from MAX30100
- Pushes the data to Firebase using REST API
- Sends HTTP GET requests to Flask dashboard for visualization (optional)

### Arduino Libraries Used:

- `Wire.h`
- `ESP8266WiFi.h`
- `FirebaseESP8266.h` or `HTTPClient.h` (depending on Firebase method)
- `MAX30100_PulseOximeter.h`

---

## ☁️ Firebase Setup

1. Create a new **Firebase project**.
2. Enable **Realtime Database** in test mode.
3. Note the **Database URL**.
4. Generate and copy the **Database Secret** or set up rules for unauthenticated write.
5. Update ESP8266 code with:
   ```cpp
   const char* FIREBASE_HOST = "your-project-id.firebaseio.com";
   const char* FIREBASE_AUTH = "your-firebase-database-secret";

## OUTPUT: DASHBOARD:
![dashboard](https://github.com/user-attachments/assets/dbd457d4-cf81-476b-8aab-f1569dbe1209)
