#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SHT4x.h>

#define __DEBUG_LEVEL_SILENT__ 0
#define __DEBUG_LEVEL_ERROR__ 1
#define __DEBUG_LEVEL_ESSENTIAL__ 2
#define __DEBUG_LEVEL_VERBOSE__ 3
#define __DEBUG_LEVEL__ __DEBUG_LEVEL_VERBOSE__

//Global Objects for each I2C Bus
TwoWire I2Cbus_1 = TwoWire(1);
TwoWire I2Cbus_2 = TwoWire(2);

//Global Objects for each temperature and humidity sensor
Adafruit_SHT4x sht40_1;
Adafruit_SHT4x sht40_2;

//The setup function runs once when you press reset or power on the board
void setup() {
  //Initialize Serial and completely boot the system
  {
  //Start Serial at low speed to avoid buffer overflow and crash
  Serial.begin(115200);
  //Wait for Serial to be ready and cpu to boot the rudimentary bios
  delay(2000);
  
  if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ESSENTIAL__) {
    Serial.println("👋 System Initialization Successful!");
  }
  }

  //Scan I2C Bus1 for devices
  {
  if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ESSENTIAL__) {
      Serial.println("🔍 I2C Scan on Wire1 (GPIO21=SDA, GPIO22=SCL)");
  }

  I2Cbus_1.begin(21, 22, 100000);

  for (byte i = 1; i < 127; i++) {
    I2Cbus_1.beginTransmission(i);
    if (I2Cbus_1.endTransmission() == 0) {
        if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ESSENTIAL__) {
          Serial.printf("✅ I2CBUS_1 Device found at 0x%02X\n", i);
        }
    }
  }
  I2Cbus_1.endTransmission();
  delay(200);
  }

  //Scan I2C Bus2 for devices
  {
  if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ESSENTIAL__) {
    Serial.println("🔍 I2C Scan on Wire2 (GPIO32=SDA, GPIO33=SCL)");
    }

  I2Cbus_2.begin(32, 33, 100000);

  for (byte i = 1; i < 127; i++) {
    I2Cbus_2.beginTransmission(i);
    if (I2Cbus_2.endTransmission() == 0) {
      if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ESSENTIAL__){
        Serial.printf("✅ I2CBUS_2 Device found at 0x%02X\n", i);
      }
    }
  }
  I2Cbus_2.endTransmission();
  delay(200);
  }

  // Try to initialize Temperature and Humidity sensor 1 on I2C bus 1
  {
  if (!sht40_1.begin(&I2Cbus_1)) {
      if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ERROR__) {
        Serial.println("❌ SHT40 not found on Wire1 (0x44). Check wiring/VCC/GND.");
      }
    while (1) { delay(500); } // stop here so we can debug
  }

  if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ESSENTIAL__) {
    Serial.println("✅ SHT40_1 initialized");
  }

  sht40_1.setPrecision(SHT4X_HIGH_PRECISION);
  delay(200);
  }

  // Try to initialize Temperature and Humidity sensor 2 on I2C bus 2
  {
  if (!sht40_2.begin(&I2Cbus_2)) {
    if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ERROR__) {
      Serial.println("❌ SHT40 not found on Wire2 (0x44). Check wiring/VCC/GND.");
    }
    while (1) { delay(500); } // stop here so we can debug
  }

  if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ESSENTIAL__) {
    Serial.println("✅ SHT40_2 initialized");
  }

  sht40_2.setPrecision(SHT4X_HIGH_PRECISION);
  delay(200);
  }
}

//The loop function runs over and over again forever until power down or reset
void loop() {

  //read temperature and humidity data from sensors 1 and 2
  #pragma region Read_Temperature_and_Humidity
  sensors_event_t humidity_1, temp_1;
  sensors_event_t humidity_2, temp_2;
  bool ok_1 = sht40_1.getEvent(&humidity_1, &temp_1);
  bool ok_2 = sht40_2.getEvent(&humidity_2, &temp_2);
  #pragma endregion

  //print temperature and humidity sensor 1 data
  {
  if (ok_1) {
    // print compactly to reduce heap pressure
    if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_VERBOSE__) {
      Serial.print("T_1: ");
      Serial.print(temp_1.temperature, 2);
      Serial.print(" °C  | RH_1: ");
      Serial.print(humidity_1.relative_humidity, 1);
      Serial.println(" %");
    }
  } else {
    if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ERROR__) {
      Serial.println("⚠️ read failed");
    }
  }
  }

  //print temperature and humidity sensor 2 data
  {
  if (ok_2) {
  // print compactly to reduce heap pressure
    if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_VERBOSE__) {
      Serial.print("T_2: ");
      Serial.print(temp_2.temperature, 2);
      Serial.print(" °C  | RH_2: ");
      Serial.print(humidity_2.relative_humidity, 1);
      Serial.println(" %");
    }
  } else {
    if (__DEBUG_LEVEL__ >= __DEBUG_LEVEL_ERROR__) {
      Serial.println("⚠️ read failed");
    }
  }
  }
  
  delay(2000); // give CPU and sensor breathing room
}
