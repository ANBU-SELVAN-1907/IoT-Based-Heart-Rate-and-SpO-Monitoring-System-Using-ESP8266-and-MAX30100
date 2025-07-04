#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS 2000

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char* firebaseHost = "https://your-project-id.firebaseio.com/";
const char* firebasePath = "/health.json";

PulseOximeter pox;
uint32_t tsLastReport = 0;

void onBeatDetected() {
  Serial.println("💓 Beat!");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected!");

  if (!pox.begin()) {
    Serial.println("❌ FAILED to initialize MAX30100");
    while (1);
  } else {
    Serial.println("✅ MAX30100 ready");
  }

  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
  pox.update();

  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    tsLastReport = millis();

    float bpm = pox.getHeartRate();
    float spo2 = pox.getSpO2();

    Serial.printf("Heart Rate: %.2f bpm, SpO2: %.2f%%\n", bpm, spo2);

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      String url = String(firebaseHost) + firebasePath;

      http.begin(url);
      http.addHeader("Content-Type", "application/json");

      String payload = "{";
      payload += "\"heartrate\":" + String(bpm) + ",";
      payload += "\"spo2\":" + String(spo2) + ",";
      payload += "\"timestamp\":\"" + String(millis()) + "\"";
      payload += "}";

      int httpResponseCode = http.PUT(payload); // or use POST for new entries

      if (httpResponseCode > 0) {
        Serial.println("✅ Data sent to Firebase");
      } else {
        Serial.print("❌ Error sending data: ");
        Serial.println(httpResponseCode);
      }

      http.end();
    }
  }
}