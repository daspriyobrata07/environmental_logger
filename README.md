# Portable Environmental Data Logger

An Arduino-based environmental monitoring system that measures temperature, relative humidity, and ambient light intensity. It displays live readings on an OLED and transmits sensor data to a computer via USB serial communication.

The project explores embedded systems, sensor interfacing, analog and digital electronics, and serial communication.

## Features

- Temperature and humidity monitoring using DHT11.
- Ambient light sensing using an LDR.
- Live readings on a 0.96-inch SSD1306 OLED.
- USB serial data transmission.
- Periodic sensor readings at 2-second intervals.
- CSV-formatted serial output.

## Hardware Components

| Component | Purpose |
|---|---|
| Arduino Uno R3 | Main microcontroller |
| DHT11 | Temperature and humidity sensing |
| LDR + 10 kΩ resistor | Light sensing |
| 0.96-inch OLED (SSD1306) | Display |
| Breadboard and jumper wires | Circuit assembly |
| USB cable | Power and communication |

## Circuit Connections

**DHT11**

| Sensor | Arduino |
|---|---|
| VCC | 5V |
| DATA | D2 |
| GND | GND |

**OLED (I²C)**

| OLED | Arduino |
|---|---|
| VCC | 5V (if supported) |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

**LDR Voltage Divider**
- LDR between 5V and A0.
- 10 kΩ resistor between A0 and GND.

## Software and Tools

- VS Code and PlatformIO
- Arduino framework (C++)
- Adafruit DHT Sensor Library
- Adafruit SSD1306 Library
- Adafruit GFX Library

## Future Improvements

- Python-based serial data logging to CSV using PySerial.
- Data analysis and visualization using Pandas and Matplotlib.
- Real-time computer dashboard.
- More accurate temperature and humidity sensors.
- SD card storage for standalone logging.
- RTC integration for independent timestamps.
- ESP32-based wireless monitoring.
- Battery-powered operation.
- Sensor calibration and measurement error analysis.
