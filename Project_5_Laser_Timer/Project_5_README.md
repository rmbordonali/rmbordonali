### Project Description:
Laser based timing system developed using code and resources from www.larryrocktimer.com. The original timer project by Larry Ehnert is designed to measure the speed and time of curling stones. This project modifies the original for use in rock climbing.

### File Guide:
- Code Files:
  - backline.ino
    - This file contains code for the "starting line" of the climbing wall, on the ground
  - hogline.ino
    - This file contains code for the "finish line" of the climbing wall, at the top
  - GetMacAddress.ino
    - This file contains code for getting the MAC adress corresponding to each esp32c3
    - The MAC address for the backline is needed for the hogline code
- Other Files:
  - Operating_Instructions.md
    - This file contains operating instructions for the timer as well as some troubleshooting steps
  - Materials.md
    - This file contains a list of materials used for the project (in-progress)

### Software Version Information:
- Arduino IDE 2.3.6
- GyverOLED 1.6.4 library by AlexGyver
- esp32 3.0.7 boards manager by Espressif Systems
 
### General Notes:
- Larry's website was under revisions at the time this project was developed, so the content currently shown on the site may differ slightly from what was used for this project
  - For example, "Larry Rock Timer 2.0" was added to the site when I was finishing the project based on an earlier version (1.0)
- The timer works independently of a laptop or smartphone
- Another helpful resource is the Seeed Studio Wiki page for the esp32c3: https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/
