// Include the libraries we need
// adapted the dallas simple temp by index 
// for reading two thermomoters
// for set up see https://randomnerdtutorials.com/guide-for-ds18b20-temperature-sensor-with-arduino/

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");
  delay(1500);
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);
  float tempC1= sensors.getTempCByIndex(1);
  Serial.print(tempC);
  Serial.print(",");
  Serial.println(tempC1);

  /* Check if reading was successful
  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  }
  else
  {
    Serial.println("Error: Could not read temperature data");
  }
  */
}
