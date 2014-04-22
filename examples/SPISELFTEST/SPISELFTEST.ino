#include <SPI.h>
#include <Wire.h>
#include <SC16IS750.h>
#include <string.h>


SC16IS750 spiuart = SC16IS750(SC16IS750_PROTOCOL_SPI,6); 

//Connect TX and RX with a wire and run this sketch
//Remove A0, A1 resistors which set the I2C address
//Remove SCL pull up resistors if you are using Duemilanove
//Pin 6 should be connected to CS of the module.
void setup() 
{
    //delay(500);
    Serial.begin(9600);
    Serial.println("Start testing");
    // UART to Serial Bridge Initialization
    spiuart.begin(9600);               //baudrate setting
    Serial.println("BAUDRATE SET");
    if (spiuart.ping()!=1) {
        Serial.println("Device not found");
        while(1);
    } else {
        Serial.println("Device found");
    }
    Serial.println("Start serial communication");
};

void loop() 
{
 
    spiuart.write(0x55);
    delay(10);
    if (spiuart.available()==0) {
        Serial.println("Please connnect TX and RX with a wire and reset your Arduino");
        while(1);
    }        
    if (spiuart.read()!=0x55) {
        Serial.println("Serial communication error");
        while(1);
    }   
    delay(200);
    
    spiuart.write(0xAA);
    delay(10);
    if (spiuart.available()==0) {
        Serial.println("Please connnect TX and RX with a wire and reset your Arduino");
        while(1);
    }  
    if (spiuart.read()!=0xAA) {
        Serial.println("Serial communication error");
        while(1);
    }   
    
    delay(200);
 
 
  
};

