# Power Stage & Hardware Schematic Overview

## Power Distribution & Switching
- **Primary Power Supply:** Corsair CV450 ATX Power Supply (dedicated 12V 36A rail)
- **Power Stage:** PWM-modulated high-current N-channel MOSFET switching stage driving Peltier modules
- **Controller:** ESP32-WROOM-32 / LilyGO T-Display board
- **Cooling:** Aluminium extruded finned heatsinks with high-airflow 12V brushless fans

## Hardware Prototype Visuals

<p align="center">
  <img src="../docs/images/control_circuitry_enclosure.jpg" alt="MOSFET Driver Stage & ESP32 Enclosure" width="450"/>
  <br>
  <em>Figure: Custom driver enclosure showcasing high-power MOSFET bank with dedicated heat spreaders, 1602 LCD, and ESP32 controller.</em>
</p>

<p align="center">
  <img src="../docs/images/heatsink_fan_assembly.jpg" alt="Quad Heatsink Fan Array" width="450"/>
  <br>
  <em>Figure: Hot-side quad brushless fan and finned aluminium heatsink cooling module.</em>
</p>
