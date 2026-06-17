# 🧊 ESP32 Dual-Zone Refrigerator Environmental Monitoring System

An ESP32-based embedded monitoring system designed to measure and track temperature and humidity in multiple refrigeration zones using dual SHT40 high-precision sensors connected through independent I2C buses.

This project demonstrates sensor interfacing, multi-bus I2C communication, embedded software development, and real-time environmental monitoring using the ESP32 platform.

---

## 🚀 Features

* Dual SHT40 temperature and humidity sensors
* Independent I2C buses for reliable sensor communication
* Real-time temperature monitoring
* Real-time humidity monitoring
* Automatic I2C device detection and scanning
* High-precision sensor measurements
* Serial debugging and diagnostics
* Modular and scalable architecture
* Built using PlatformIO and Arduino Framework

---

## 🛠 Hardware Used

### Microcontroller

* ESP32 Development Board

### Sensors

* 2 × SHT40 Temperature & Humidity Sensors

---

## 🔌 Wiring

### Sensor 1 (I2C Bus 1)

| ESP32  | SHT40 |
| ------ | ----- |
| GPIO21 | SDA   |
| GPIO22 | SCL   |
| 3.3V   | VCC   |
| GND    | GND   |

### Sensor 2 (I2C Bus 2)

| ESP32  | SHT40 |
| ------ | ----- |
| GPIO32 | SDA   |
| GPIO33 | SCL   |
| 3.3V   | VCC   |
| GND    | GND   |

---

## 📋 Software Stack

* ESP32 Arduino Framework
* PlatformIO
* C++
* Wire Library
* Adafruit SHT4x Library

---

## ⚙️ System Workflow

1. ESP32 boots and initializes serial communication.
2. Both I2C buses are scanned for connected devices.
3. Each SHT40 sensor is detected and initialized.
4. Sensors are configured for high-precision measurements.
5. Temperature and humidity readings are continuously collected.
6. Data is displayed through the serial monitor every 2 seconds.

---

## 📊 Example Output

```text
👋 System Initialization Successful!

🔍 I2C Scan on Wire1 (GPIO21=SDA, GPIO22=SCL)
✅ I2CBUS_1 Device found at 0x44

🔍 I2C Scan on Wire2 (GPIO32=SDA, GPIO33=SCL)
✅ I2CBUS_2 Device found at 0x44

✅ SHT40_1 initialized
✅ SHT40_2 initialized

T_1: 4.25 °C | RH_1: 82.1 %
T_2: -17.80 °C | RH_2: 61.4 %
```

---

## 📁 Project Structure

```text
.
├── include/
├── lib/
├── src/
│   └── main.cpp
├── test/
├── platformio.ini
└── README.md
```

---

## 🎯 Applications

* Refrigerator Monitoring
* Freezer Monitoring
* Cold Storage Systems
* Food Preservation Monitoring
* Pharmaceutical Storage Monitoring
* Environmental Data Logging
* Smart IoT Appliances

---

## 🔮 Future Improvements

* Wi-Fi connectivity
* Cloud dashboard integration
* MQTT support
* Mobile notifications
* Data logging to SD card
* Web-based monitoring interface
* OLED/LCD display support
* Historical trend analysis

---

## 🧠 Skills Demonstrated

* Embedded Systems Development
* ESP32 Programming
* I2C Communication
* Sensor Interfacing
* C/C++ Programming
* PlatformIO Development Environment
* Hardware Debugging
* Real-Time Data Acquisition

---

## 👨‍💻 Author

**Saptarshi Das**

Passionate about Embedded Systems, IoT, Robotics, and Hardware-Software Integration.

If you found this project interesting, feel free to ⭐ the repository.
