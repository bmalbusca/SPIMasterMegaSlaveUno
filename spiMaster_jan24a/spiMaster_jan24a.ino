#include <SPI.h>

/*
 * This example was followed by:
 *  http://gammon.com.au/spi
 *  https://www.linkedin.com/pulse/arduino-uno-mega-connected-via-serial-peripheral-spi-nikos-mouzakitis/
 *  https://www.e-tinkers.com/2020/03/do-you-know-arduino-spi-and-arduino-spi-library/
 */

void setup() {

Serial.begin (115200);

 digitalWrite(SS, HIGH); // disable Slave Select

 SPI.begin();

 SPI.setClockDivider(SPI_CLOCK_DIV8);//divide the clock by 8



} 

void loop() {

 char c, r;


 digitalWrite(SS, LOW); // enable Slave Select

 c ='b';

 r = SPI.transfer(c);
 Serial.println(r);

 delay(60);

 digitalWrite(SS, HIGH); // disable Slave Select


}
