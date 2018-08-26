# Arduino-LCD-Thermometer
A basic arduino sketch to read the temperature from a DS18B20 temperature sensor and display it on a 20 x 4 LCD screen.

# Requirements - Libraries
The following libraries are required to read the sensor and control the LCD screen.
1) Wire Library - To use the I2C interface to control the LCD. (Supplied with Arduino IDE.)
2) OneWire Library - To access the one wire bus for the DS18B20 temperature sensor. (Available from https://github.com/PaulStoffregen/OneWire)
3) DallasTemperature Library - Reads the data bytes returned by the DS18B20. (Available from https://github.com/milesburton/Arduino-Temperature-Control-Library)
4) LiquidCrystal_I2C - To read / write data to LCD and control backlight, cursor etc. (Available from https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/)

# Requirements - Hardware
1) Arduino (Obviously!)
2) DS18B20 Temperature Sensor
3) 4k7 Resistor. Must be installed as a pull up from the power line to the data line of the DS18B20. (required for One-Wire interface.)
4) 20 x 4 LCD Screen with I2C 'backpack' 

# Connections
DS18B20 - Power to 5V pin, Ground to GND and data to Digital Pin 5

LCD Screen - Power to 5V pin, Ground to GND, SCL to SCL and SDA to SDA

Upload the sketch and BOOM! one honest to goodness digital thermometer.
