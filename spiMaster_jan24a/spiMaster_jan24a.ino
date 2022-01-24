#include <SPI.h>

void setup() {



 digitalWrite(SS, HIGH); // disable Slave Select

 SPI.begin();

 SPI.setClockDivider(SPI_CLOCK_DIV8);//divide the clock by 8



} 

void loop() {

 char c;


 digitalWrite(SS, LOW); // enable Slave Select

 c ='b';

 SPI.transfer (c);

 delay(60);

 digitalWrite(SS, HIGH); // disable Slave Select


}
