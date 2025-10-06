# ESP32-LightSensor
Light sensor to detect when a LED is on/off
I used this to detect when my laundry washing machine start/stop so it can send me notifications via text/email

⚙️ Features

Measures ambient light in lux using the Adafruit TSL2561 sensor
Prints live readings to the serial monitor at 115 200 baud
Detects sensor connection errors and invalid readings
Uses I²C communication (pins customizable via Wire.begin())
Adjustable gain and integration time for different lighting conditions


🧠 How It Works

Initializes I²C communication on pins GPIO 8 (SDA) and GPIO 9 (SCL).

Configures the TSL2561 sensor for 1× gain and 101 ms integration time — ideal for typical indoor lighting.

Continuously reads the current light intensity and reports it as lux every 0.5 seconds.

If no valid reading is detected, outputs “Sensor error” to help with debugging.

<img width="716" height="203" alt="image" src="https://github.com/user-attachments/assets/a19e0bd0-46d0-4c5f-8b36-91e2f695f5c0" />


🪄 Future Ideas

Send notifications via Wi-Fi (MQTT / HTTP )

Trigger an LED or buzzer when light falls below a set threshold
