/*
 * NRF24L01       Arduino_ Uno    Arduino_Mega    Blue_Pill(stm32f01C)
 * __________________________________________________________________________
 * VCC        |       3.3v      |     3.3v      |     3.3v
 * GND        |       GND       |     GND       |      GND
 * CSN        |   Pin10 SPI/SS  | Pin10 SPI/SS  |     A4 NSS1 (PA4) 3.3v
 * CE         |   Pin9          | Pin9          |     B0 digital (PB0) 3.3v
 * SCK        |   Pin13         | Pin52         |     A5 SCK1   (PA5) 3.3v
 * MOSI       |   Pin11         | Pin51         |     A7 MOSI1  (PA7) 3.3v
 * MISO       |   Pin12         | Pin50         |     A6 MISO1  (PA6) 3.3v
 * 
 * 
 */

//
////
//
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//RF24 radio(9, 10); // CE, CSN
RF24 radio(PB0, PA4); // CE, CSN on Blue Pill
const uint64_t address = 0xF0F0F0F0E1LL;
boolean button_state = 0;
int led_pin = PB6;  //set the led indicator to pin B6
void setup() {
pinMode(led_pin, OUTPUT);
Serial.begin(9600);
radio.begin();
Serial.print("ADDRESS :");
radio.openReadingPipe(0, address);   //Setting the address at which we will receive the data
radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
radio.startListening();              //This sets the module as receiver
}
void loop()
{
if (radio.available())              //Looking for the data.
{
Serial.println("Radio is sniffing");
  
char text[32] = "";                 //Saving the incoming data
radio.read(&text, sizeof(text));    //Reading the data
radio.read(&button_state, sizeof(button_state));    //Reading the data
if(button_state == HIGH)
{
digitalWrite(led_pin, HIGH);
Serial.println(text);
}
else
{
digitalWrite(led_pin, LOW);
Serial.println(text);}
}
delay(5);
}



