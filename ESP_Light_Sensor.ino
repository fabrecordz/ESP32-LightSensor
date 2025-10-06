#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
#include <math.h>     

// Create the sensor instance (address 0x39 by default)
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

void setup() {
  Serial.begin(115200);
  // Initialize I2C on our chosen pins
  Wire.begin(8, 9);
  // Initialize the sensor
  if (!tsl.begin()) {
    Serial.println("TSL2561 not found");
    while (1);
  }
  // Configure gain/exposure for your lighting range
  tsl.setGain(TSL2561_GAIN_1X);            // No gain for bright light
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);
  // Let the sensor settle
  delay(500);
}

void loop() {
  sensors_event_t event;
  tsl.getEvent(&event);

  if (isnan(event.light)) {
    Serial.println("Sensor error");
  } else {
    Serial.print("Lux: ");
    Serial.println(event.light, 2);
  }

  delay(500);
}
