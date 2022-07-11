# tsck-BrightsignDimmer

This code monitors the High/Low state of a brightsign output pin. Then the pin is high, power to LEDs are reduced using PWM to a minimum level. When the pin is Low, power to the LED is ramped back up to 100%.
MAX level is set by the external power supply, MIN level is set by an offboard pot.
