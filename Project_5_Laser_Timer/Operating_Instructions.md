### Timer Operating Instructions:
The below instructions were adapted from the following site: https://sites.google.com/larryrocktimer.com/larryrocktimer/home/operatinginstructions?authuser=0

1. **Connect both esp32 boards to a power source and direct a laser beam at each sensor**
   - Both photosensor LEDs should be on if a laser beam is hitting the sensor
   - Check to make sure that breaking the laser beam turns off the second photosensor LED
2. **Test the IR sensor**
   - The backline OLED should start up automatically followed by a short period to test the IR sensor
   - A "1" is displayed until your hand (or another object that reflects IR light) is near the sensor, then it changes to a "0"
   - Select the mode for 1 sensor by keeping the displayed number at "1". Keep your hand behind the sensor to show a "0" if you are using 2 hogline sensors
   - Moving something that will reflect IR light close to the sensor is also used to arm the system to prepare for each measurement
4. **Arm the timer for a measurement**
   - Pass something (e.g. your hand) close to the IR sensor to arm the timer
   - While the device is waiting to be armed, the previous timing readings will be displayed
   - After the system is armed, it waits for the backline beam to be broken and reformed
5. **Take a measurement**
   - Once the system is armed, step into the starting area to break the backline laser beam
   - Timing begins once the backline beam is reformed (i.e. when the climber leaves the ground)
   - Break the hogline (i.e. finish line) beam at the top of the climbing wall
6. **Record results**
   - The recorded climb time in seconds will display on the backline OLED display
   - Record the time, and arm the timer for a new measurement
  
### Troubleshooting Steps:
- The timer can be sensitive to ambient lighting. If the IR or phototransistor sensors are not working, their potentiometers may need to be adjusted
- Also make sure that the IR sensor is not blocked (e.g. by a power cord). This could reflect IR light into the sensor and arm the system prematurely
- If timing data is not being sent from the hogline/finish to the backline/start, make sure that the correct backline MAC address is uploaded to the hogline esp32
  - If the issue persists with the correct MAC address, keep the backline unit on and turn the hogline on/off
    (Note: I have not personally experienced this issue, but others have suggested this solution if it occurs)
- For other issues (e.g. sensor LED not lighting up, OLED not turing on when connected to power, etc.), check for loose wiring connections or pins
  - Loose pins may need to be resoldered to the esp32c3 boards
