//Multi Beam System
//modified 11/4/24 to allow user to choose number of beams on startup
//modified lines 12 and 80 for LR mode
// modified 11/15/24 to blink the light sensor pin 15 instead of the led on pin 13.
// modified on 1/12/25 to remove blinking and set up for Seeedstudio Xiao esp32-c3 Defined pins for LIGHTPIN and IRPIN. removed led13 boolean
//needed different pins for power and ground for sensors and display
//MODIFIED 1/22/26 for climbing: start on beam MADE, end on hog line BROKEN
//For Display pin 4 = SDA pin 5 = SCL
//For IR Sensor pin 9 = Vcc pin 10 = GND pin 6 = Dout
//For Light Sensor pin 2 = Vcc pin 1 = GND pin 0 = Dout
int numberOfBeams=1; //can use many hogline beams now. Adjust the arrays if > 2
//default of 1 hogline beam. Choose 2 in the void calibration
#include <GyverOLED.h>
GyverOLED<SSH1106_128x64> oled;
#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h> //to set for LR mode
#define IRPIN D8 //input pin for IR sensor
#define LIGHTPIN D0 //input pin for the light sensor
//counter for the number of hog line beam breaks
int beamCount=0;
//variables for interval time and stone speed
float intervalTime=12.34;
float stoneSpeed=6.92;
//variables for time calculations
unsigned long makeHogTime=1000;
unsigned long breakHogTime=1000;
unsigned long backLineBreakTime=1000;
unsigned long timeReceived=1000;
unsigned long throughBeamTime[]={1000,916.667,1000};
unsigned long beamBrokeTime[]={1000,1000,1000};//needs to be changed for the number of beams. Match up value to the initial backLineBreakTime to avoid initial value craziness 
//match up [1] value to avoid initial value craziness
// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
 int a;//time of hog line break
 int b;//time of hog line make after break
} struct_message;
// Create a struct_message called timeData
struct_message timeData;
//error created by the new IDE version 2.3.3
//void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
///Change to
//void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len)

//or downgrade the version
//***************************************************************
// callback function that will be executed when data is received
void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len)
{
 memcpy(&timeData, incomingData, sizeof(timeData));
timeReceived=millis();
//ignore the received data if the back line beam was not broken
//do this ignoring in the void armed
breakHogTime=timeData.a;
makeHogTime=timeData.b;
beamCount=beamCount+1;
if (beamCount <= numberOfBeams)
 {//only record data if true
throughBeamTime[beamCount]=makeHogTime-breakHogTime;
// Serial.print("Through the Beam ");
// Serial.println(throughBeamTime[beamCount]);
beamBrokeTime[beamCount]=timeReceived-throughBeamTime[beamCount];
 }//end of if beamCount<=numberOfBeams
}//end of void OnDataRecv
//************************************************************************
void setup()
{
Serial.begin(115200);
 // Set device as a Wi-Fi Station
 WiFi.mode(WIFI_STA);
 esp_wifi_set_protocol( WIFI_IF_STA , WIFI_PROTOCOL_LR); //to set for LR mode
 // Init ESP-NOW
 if (esp_now_init() != ESP_OK) {
 Serial.println("Error initializing ESP-NOW");
 return;
 }
 // Once ESPNow is successfully Init, we will register for recv CB to
 // get recv packer info
 esp_now_register_recv_cb(OnDataRecv);
//define pins for the Light Sensor
pinMode(LIGHTPIN,INPUT); //input for the light sensor is D0 for xiao
pinMode(D1,OUTPUT);
digitalWrite(D1,LOW);//GND for the light sensor

pinMode(D2,OUTPUT);
digitalWrite(D2,HIGH);//Vcc for the light sensor
//define pins for the IR sensor
pinMode(D9,OUTPUT); //GND for the IR sensor
pinMode(D10,OUTPUT); //Vcc for the IR sensor
digitalWrite(D9,LOW); //turn on to power the sensor
digitalWrite(D10,HIGH); //turn low to power the sensor
pinMode(IRPIN, INPUT); //input for the IR sensor
oled.init();
//Send Welcome Screen Message
 oled.clear();
 oled.setScale(3);
 oled.setCursor(0,0);
 oled.print("Welcome");
 oled.setScale(2);
 oled.setCursor(15,3);
 oled.print("Larry");
 oled.setCursor(5,5);
 oled.print("Rock Timer"); //welcome message from original code, can change
 oled.setCursor(0,7);
 oled.setScale(1);
 oled.print("MULTIBEAM xiao 1/22/26");
 oled.update();
 delay(2500);
 oled.clear();
 oled.update();
 delay(250);
 oled.setCursor(0,0);
 oled.print("macAddress");
 oled.setCursor(0,2);
 oled.print(WiFi.macAddress());
 oled.setCursor(0,4);
 oled.print("enter this into");
 oled.setCursor(0,6);
 oled.print("hogline esp32");
 oled.update();
 delay(3000);
//test the IR sensor for five seconds
 oled.clear();
 oled.setScale(1);
 oled.setCursor(0,0);
 oled.print("Test IR Sensor");
 oled.setCursor(0,1);
 oled.print("For 5 seconds");
 oled.setCursor(0,5);
 oled.print("Should change to 0");

 oled.setCursor(0,6);
 oled.print("When hand is near");
 oled.update();
 delay(3000);
unsigned long calibrateTime=millis();
while (millis()<calibrateTime+5000){
int IRvalue=digitalRead(IRPIN);
//is a 1 when no object is a 0 when an object is close to sensor
 oled.clear();
 oled.setScale(2);
 oled.setCursor(5,3);
 oled.print(IRvalue);
 oled.update();
}//end of five second while
//end of testing for the IR sensor
//
//use the IR beam to set the number of beams.
//keep as 1 beam system if IR value is no object or equal to 1
//hold IR as a 0 after the testing to set for 2 beams
if(digitalRead(IRPIN)==0)
{
 numberOfBeams=2;
}
 oled.clear();
 oled.setScale(1);
 oled.setCursor(0,4);
 oled.print("Number of Hog Line");
 oled.setCursor(0,5);
 oled.print("beams & sensors=");
 oled.setCursor(100,5);
 oled.print(numberOfBeams);
 oled.update();
 delay(3000);
}//end of void setup
void loop()
{
 //read IR sensor on pin 19 for arming
 //sensor returns a 0 when object is close 
if (digitalRead(IRPIN)==0)
 {
 armed();
 
 }//no IR received so Blink an external LED and display times
 // blink in the display loop now also
 //system is not armed
 
 //Display Timer Values while waiting to arm
//calculate and display values These are continuously displayed until the
//system is armed by the IR sensor
for (int i=1; i<numberOfBeams+1; i++){ 
 //intervalTime=(timeHogBreak[i+1]-timeHogBreak[i])/1000.000;
 oled.clear();
 oled.setScale(1);
 oled.setCursor(15,0);
 oled.print("Climb Time"); //CHANGED from "Interval Time"
 oled.setCursor(20,2);
 oled.setScale(3);
 oled.setCursor(20,2);
 oled.setScale(3);
 oled.print((beamBrokeTime[i]-beamBrokeTime[i-1])/1000.);
 oled.setScale(1);
 oled.setCursor(105,0);
 oled.print(i);
 oled.setCursor(105,4);
 oled.print("sec");
 oled.update();
 delay(800);
 

}//end of for loop to display multiple beams
}//end of void loop
void armed()
{
//check if laser is on the sensor
if(digitalRead(LIGHTPIN)==0){
 //sensor illuminated beam is on the the sensor
oled.clear();
oled.setScale(2);
oled.setCursor(20,0);
oled.print("System");
oled.setCursor(26,2);
oled.print("Armed");
oled.setScale(1);
oled.setCursor(0,5);
oled.print("Waiting for climber");
oled.setCursor(0,6);
oled.print("to break beam");
oled.update();
while(digitalRead(LIGHTPIN)==0){
//waiting for beam break at the back line
}
//BEAM IS NOW BROKEN - climber is blocking it
//Wait for beam to be MADE (climber starts)
oled.clear();
oled.setScale(2);
oled.setCursor(20,0);
oled.print("Beam");
oled.setCursor(15,2);
oled.print("Broken");
oled.setScale(1);
oled.setCursor(0,5);
oled.print("Waiting for climber");
oled.setCursor(0,6);
oled.print("to start (beam made)");
oled.update();
while(digitalRead(LIGHTPIN)==1){
//waiting for beam to be MADE at the back line
}
//break the loop when the beam is MADE on the back line - START TIMING
//need to reset beamCounter here also in case hog line sensors are broken while waiting for the back line beam
beamCount=0;
beamBrokeTime[0]=millis(); //RECORD START TIME
throughBeamTime[0]=916.667; //not relevant at the back beam
//now wait for addition data from the Hog Line Sensores
while (beamCount<numberOfBeams){
 //display the count from the hog line sender
oled.clear();
oled.setScale(3);
oled.setCursor(0,0);
oled.print("TIMING");
oled.setCursor(110,0);
oled.setScale(2);
oled.print(beamCount);
oled.setScale(1);

oled.setCursor(0,5);
oled.print("waiting for msg from ");
oled.setCursor(0,6);
oled.print(" hog line sensor");
oled.update();
} //end of while < numberOfBeams
}//end of if reset and beam made
else
{
//laser beam is not on the sensor after arming
oled.clear();
oled.setScale(1);
oled.setCursor(0,0);
oled.print("Fix the laser beam");
oled.setCursor(0,3);
oled.print("and arm system again");
oled.update();
//wait here until the laser is on the sensor
while (digitalRead(LIGHTPIN)==1){
}//wait for beam
}//end of else
}//end of void armed
