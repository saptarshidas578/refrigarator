# 🧊 ESP32 Smart Thermoelectric Refrigerator

A custom-built 11-liter smart thermoelectric refrigerator powered by an ESP32 microcontroller and TEC1-12706 Peltier modules. The project was developed to explore embedded systems, power electronics, thermal management, and real-world control systems.

Unlike conventional compressor-based refrigerators, this system uses thermoelectric cooling based on the Peltier effect, providing a compact, refrigerant-free, and low-maintenance cooling solution.

---

## Features

* Real-time temperature and humidity monitoring
* ESP32-based control system
* PWM-controlled thermoelectric cooling
* MOSFET driver stage for high-current TEC control
* LCD-based live system monitoring
* Dual SHT40 environmental sensing
* Active hot-side cooling with heatsinks and fans
* Modular and scalable architecture

---

## Hardware Components

| Component             | Description                    |
| --------------------- | ------------------------------ |
| ESP32-WROOM-32        | Main controller                |
| TEC1-12706            | Thermoelectric cooling modules |
| SHT40                 | Temperature & humidity sensor  |
| MOSFET Driver Circuit | PWM power control              |
| 16×2 LCD              | Real-time display              |
| Aluminium Heatsinks   | Heat dissipation               |
| Cooling Fans          | Forced-air cooling             |
| Corsair CV450 PSU     | System power supply            |

---

## System Architecture

1. SHT40 sensors continuously monitor environmental conditions.
2. ESP32 processes sensor data in real time.
3. PWM signals regulate cooling power delivered to the TEC modules.
4. MOSFET drivers handle high-current switching.
5. LCD displays live system information.
6. Heatsinks and fans remove heat from the hot side of the Peltier modules.

---

## Performance

* Internal chamber volume: **11 Liters**
* Ambient temperature: **~38°C**
* Lowest achieved chamber temperature: **22°C**
* Temperature reduction: **12–13°C below ambient**
* Power consumption: **300–330 W**

---

## Engineering Challenges

### Thermal Management

The most significant challenge was maintaining a low hot-side temperature. Since Peltier efficiency decreases rapidly as hot-side temperature rises, multiple heatsink and airflow configurations were tested.

### Power Delivery

The TEC modules require substantial current. Designing a reliable MOSFET-based switching stage and stable power distribution system was critical for safe operation.

### System Optimization

Several iterations were required to balance cooling performance, airflow, power consumption, and thermal stability.

---

## Future Improvements

* PID temperature control
* Wi-Fi remote monitoring
* Mobile application integration
* Data logging and analytics
* Improved insulation materials
* Optimized airflow channels
* Higher efficiency heatsinks and fans

---

## Skills Demonstrated

* Embedded Systems Development
* ESP32 Programming
* Power Electronics
* PWM Motor/Power Control
* Sensor Interfacing
* Thermal System Design
* Hardware Prototyping
* System Debugging & Optimization

---

## Author

**Saptarshi Das**

An embedded systems and IoT enthusiast passionate about designing intelligent hardware solutions and exploring real-world engineering challenges.
