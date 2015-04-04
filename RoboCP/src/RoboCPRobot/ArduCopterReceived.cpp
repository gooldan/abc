#include "ArduCopterReceived.h"


ArduCopterReceived::ArduCopterReceived(void)
{
  Roll = 0;
  Pitch = 0;
  Yaw = 0;
  AltitudeSonic = 0;
  AltitudeBarometer = 0;
  Acceleration.setx(0);
  Acceleration.sety(0);
  Acceleration.setz(0);
}


ArduCopterReceived::~ArduCopterReceived(void)
{
}
