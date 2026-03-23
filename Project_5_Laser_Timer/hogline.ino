//modified on 1/18/25 to change pin declarations. 
//now is used with a esp32C3 as the receiver.
//modified on 11/5/24 to use LR mode lines 5 and line 34
//set up on 12/6/24 for exp32 xiao c3 power the laser from usb and gnd.
//power the sensor from 3v3 pin, pin d10 for ground, pin d9 for input.
#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>
//MAC address of receiver to broadcast to the BackLine ESP32
//this is the device that will display the time data
//MAC address for backline: 58:8c:81:ae:85:e4
uint8_t broadcastAddress[] = {0x58, 0x8C, 0x81, 0xAE, 0x85, 0xE4};
//define a data structure for sending the time data
typedef struct struct_message2{
 int a; //for the millis value when the beam is broke
 int b; //for the millis value when the beam is made after break
} struct_message2;
//create a structured object
struct_message2 timeData;//send data in the object timeData with timeData.a and timeData.b
//Peer info
esp_now_peer_info_t peerInfo;
//Callback function called when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status){
//Serial.print("\r\nLast Packet Send Status:\t");
//Serial.println(status== ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
void setup() {
 // put your setup code here, to run once:
//Serial.begin(115200);
WiFi.mode(WIFI_STA);
esp_wifi_set_protocol( WIFI_IF_STA , WIFI_PROTOCOL_LR);
//initialize esp now
if (esp_now_init() != ESP_OK){
// Serial.println("Error initializing ESP-NOW");
 return;
}//end of if
//Register the send callback
esp_now_register_send_cb(OnDataSent);
//Register peer
memcpy(peerInfo.peer_addr, broadcastAddress, 6);
peerInfo.channel = 0;
peerInfo.encrypt = false;
//add peer
if (esp_now_add_peer(&peerInfo) != ESP_OK){
// Serial.println("Failed to add peer");
 return;

}//end of if
pinMode(D9, INPUT); //for the signal from light sensor
pinMode(D10,OUTPUT); //use for ground
digitalWrite(D10,LOW);
}//end of void setup
void loop()
{
while(digitalRead(D9)==0){
 //beam is closed waiting for a break
 }
 //Beam just broke, send data immediately for climbing
 timeData.a=millis();
 timeData.b=millis(); // Not used for climbing but must match structure
// Serial.println("Finish line beam is broken, sending immediately");

//Send the message AS SOON AS the beam breaks
esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)&timeData, sizeof(timeData));
if (result == ESP_OK){
// Serial.println("Sending confirmed");
}
else {
// Serial.println("Sending error");
}

 //Wait for beam to close again before next climb
 while(digitalRead(D9)==1) {
 //finish line beam is broken waiting for a close
 }
 
 //Additional delay before accepting another climb
 delay(3000);
// Serial.println("Ready for next climb");
}//end of void loop
