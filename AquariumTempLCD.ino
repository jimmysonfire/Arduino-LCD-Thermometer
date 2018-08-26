// Reads a DS18b20 temperature sensor and displays the temperature on a 20 x 4 LCD screen.
//    Copyright (C) <2018>  <James Lloyd-Addecott>

//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

/* Import Libraries */
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Declarations
// Set up one wire bus, lcd screen and ds18b20 temp sensor.
#define ONE_WIRE_BUS 5
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Declare some variables
float Celcius=0;
float Fahrenheit=0;

void setup() 
{
// put your setup code here, to run once:
// Start LCD.
 lcd.begin(20,4);
 lcd.backlight();
 lcd.setCursor(1,1);
 lcd.print("Starting......");
 delay(2000);
 lcd.clear();
 delay(500);
 lcd.setCursor(0,0);
 lcd.print("Getting Temp");
 lcd.clear();
}

void loop()
{
// will run repeatedly:
//
// Request temperature from DS18b20 and wait 1 second before reading the sensor return.
 sensors.requestTemperatures();
 delay(1000);
 Celcius = sensors.getTempCByIndex(0);
 Fahrenheit = sensors.toFahrenheit(Celcius);
 // Print the temp. to a 20x4 LCD screen every 5 seconds.
 lcd.setCursor(0,0);
 lcd.print("Current Temp. C");
 lcd.setCursor(2,1);
 lcd.print(Celcius);
 lcd.setCursor(0,2);
 lcd.print("Current Temp. F");
 lcd.setCursor(2,3);
 lcd.print(Fahrenheit);
 delay(5000);
}
