#include <Arduino.h>
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pin configuration
constexpr uint8_t DHT_PIN = 2;
constexpr uint8_t LDR_PIN = A0;
constexpr uint8_t DHT_TYPE = DHT11;

// OLED display configuration
constexpr int SCREEN_WIDTH = 128;
constexpr int SCREEN_HEIGHT = 64;
constexpr int OLED_RESET = -1;
constexpr uint8_t OLED_ADDRESS = 0x3C;

DHT dht(
  DHT_PIN, 
  DHT_TYPE
);

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

// Logging interval
constexpr unsigned long LOG_INTERVAL_MS = 2000;
unsigned long previousLogTime = 0;

void setup() {
    Serial.begin(9600);
    dht.begin();

    pinMode(LDR_PIN, INPUT);

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
        Serial.println("ERROR: OLED not detected");
        while (true) {
            delay(100);
        }
    }

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Environmental");
    display.println("Data Logger");
    display.println();
    display.println("Starting...");
    display.display();

    // CSV header for the serial data stream.
    Serial.println(
        "timestamp_ms,temperature_C,humidity_pct,light_raw"
    );

    delay(1000);
}

void loop() {
    unsigned long now = millis();

    // Used instead of delay() so other tasks can run
    if (now - previousLogTime < LOG_INTERVAL_MS) {
        return;
    }

    previousLogTime = now;

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    int lightRaw = analogRead(LDR_PIN);

    bool validDHT =
        !isnan(temperature) && !isnan(humidity);

    // OLED display output
    display.clearDisplay();
    display.setCursor(0, 0);

    display.println("ENVIRONMENT MONITOR");
    display.println("-------------------");

    if (validDHT) {
        display.print("Temp: ");
        display.print(temperature, 1);
        display.println(" C");

        display.print("Humidity: ");
        display.print(humidity, 1);
        display.println(" %");
    } else {
        display.println("DHT read error");
    }

    display.print("Light raw: ");
    display.println(lightRaw);

    display.display();

    // USB serial output in CSV format
    Serial.print(now);
    Serial.print(",");

    if (validDHT) {
        Serial.print(temperature, 1);
        Serial.print(",");
        Serial.print(humidity, 1);
    } else {
        Serial.print(",");
    }

    Serial.print(",");
    Serial.println(lightRaw);
}