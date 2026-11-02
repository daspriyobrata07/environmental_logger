# Portable Environmental Data Logger

An Arduino-based environmental monitoring system that measures temperature, relative humidity, and ambient light intensity. It displays live sensor readings on an OLED screen and transmits measurement data to a computer through USB serial communication.

The project demonstrates the integration of embedded systems, sensors, analog and digital interfacing, serial communication, and data analysis.

## 1. Features

- Real-time temperature monitoring using DHT11.
- Relative humidity measurement.
- Ambient light sensing using an LDR.
- Live readings displayed on a 0.96-inch OLED.
- USB serial communication between Arduino and computer.
- Periodic sensor readings at 2-second intervals.
- CSV-formatted measurement output.
- Optional Python-based automated data logging.
- Optional data visualization using Python.

## 2. Hardware Components

| Component | Purpose |
|---|---|
| Arduino Uno R3 | Main microcontroller |
| DHT11 | Temperature and humidity sensing |
| LDR | Ambient light detection |
| 10 kΩ resistor | LDR voltage divider |
| 0.96-inch OLED (SSD1306) | Display |
| Breadboard | Circuit assembly |
| Jumper wires | Connections |
| USB cable | Power and serial communication |

## 3. Circuit Connections

### DHT11

| Sensor | Arduino |
|---|---|
| VCC | 5V |
| DATA | D2 |
| GND | GND |

### OLED Display (I2C)

| OLED | Arduino Uno |
|---|---|
| VCC | 5V (if supported by module) |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### LDR Voltage Divider

- One LDR terminal connected to 5V.
- Other LDR terminal connected to A0.
- A 10 kΩ resistor connected between A0 and GND.

## 4. Software and Tools

- VS Code
- PlatformIO IDE extension
- Arduino framework
- C++
- Adafruit DHT Sensor Library
- Adafruit SSD1306 Library
- Adafruit GFX Library

Optional computer-side tools:

- Python 3
- PySerial
- Pandas
- Matplotlib

## 9. Future Improvements

- Replace DHT11 with a more accurate temperature and humidity sensor.
- Add SD card storage for standalone logging.
- Add an RTC module for independent calendar timestamps.
- Implement wireless data transmission using ESP32.
- Add battery-powered operation.
- Implement sensor calibration and measurement error analysis.
- Develop a real-time computer dashboard.
