#include <Wire.h>
#include <SC16IS750.h>
#include <string.h>
#include <SPI.h>

SC16IS750 i2cuart = SC16IS750(SC16IS750_PROTOCOL_I2C,SC16IS750_ADDRESS_AD);

//Connect TX and RX with a wire and run this sketch

void setup() 
{
    Serial.begin(9600);

    // UART to Serial Bridge Initialization
    i2cuart.begin(9600);               //baudrate setting
    if (i2cuart.ping()!=1) {
        Serial.println("device not found");
        while(1);
    } else {
        Serial.println("device found");
    }
    Serial.println("start serial communication");
    


};

void loop() 
{
   
    i2cuart.write(0x55);
    while(i2cuart.available()==0);
    if (i2cuart.read()!=0x55) {
        Serial.println("serial communication error");
        while(1);
    }   
    delay(200);
    
    i2cuart.write(0xAA);
    while(i2cuart.available()==0);
    if (i2cuart.read()!=0xAA) {
        Serial.println("serial communication error");
        while(1);
    }   
    
    delay(200);
      
     
  
  

  
};

