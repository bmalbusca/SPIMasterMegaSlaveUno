#include <SPI.h>
char buff [50];
volatile byte indx;
volatile boolean process;
/*
 * This example was followed by:
 *  http://gammon.com.au/spi
 *  https://www.linkedin.com/pulse/arduino-uno-mega-connected-via-serial-peripheral-spi-nikos-mouzakitis/
 *  https://www.e-tinkers.com/2020/03/do-you-know-arduino-spi-and-arduino-spi-library/
 */
void setup() {
  Serial.begin (115200);
  pinMode(MISO, OUTPUT); // have to send on master in so it set as output
  SPCR |= _BV(SPE); // turn on SPI in slave mode
  indx = 0; // buffer empty
  process = false;
  SPI.attachInterrupt(); // turn on interrupt
}

ISR (SPI_STC_vect) {// SPI interrupt routine
  //Serial.println("interrupt");
  char c = SPDR; // read byte from SPI Data Register
  //Serial.println(c);
  if (indx < sizeof buff) {
    buff [indx++] = c; // save data in the next index in the array buff
    //Serial.println("written buffer");
    //if ( (c == '\r') || (c == '\n') || (c=='\0') ) //check for the end of the word
      process = true;
  }
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);
  SPI.transfer ("index ");
  
  
}

void loop(){
  if (process) {
    //Serial.println("SPI reception ");
    process = false; //reset the process
    //Serial.print("index ");
    //Serial.println(indx);
    Serial.print(buff); //print the array on serial monitor
    indx= 0; //reset button to zero
  }
}
