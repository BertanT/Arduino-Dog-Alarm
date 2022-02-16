// Include the library for the IR Distance sensor
#include <SharpIR.h>

// Enter the model of the sharp ir sensor you use below
#define SENSOR_MODEL SharpIR::GP2Y0A41SK0F

// Enter distance in cm at which you want to activate the alarm
#define DISTANCE_TRESHOLD 10

// Define pins for cleaner code
#define SENSOR_PIN A5
#define RELAY_PIN 2
#define PIEZZO_PIN 3


// Initialize sensor object
SharpIR distanceSensor(SENSOR_MODEL, SENSOR_PIN);

void setup()
{
  // Set the pin modes accordingly
  pinMode(SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(PIEZZO_PIN, OUTPUT);

}

void loop()
{
  // Measure the distance
  uint8_t distance = distanceSensor.getDistance();

  // Activate alarm if the treschold distance is reached
  // Deactivate if not
  if (distance <= DISTANCE_TRESHOLD)
  {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(PIEZZO_PIN, HIGH);
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(PIEZZO_PIN, LOW);
  }

}
