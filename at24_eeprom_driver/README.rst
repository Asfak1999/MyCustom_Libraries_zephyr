

AT24C256 EEPROM 
********
Zephyr RTOS library for AT24C256 EEPROM


Write function
==============
 Both read and write functions has 3 parameters - address, buffer and buffer size. 
 Address could be number from range 0-32768 - it addresses every single char. 
 As we decided to divide memory into blocks of 16, to read the first block, 
 we will use address 0. The following 16 chars will be readed (0-15). 
 To read second block, use address 16, and block 16-31 will be readed.

```c
 #include <Eeprom_at24c256.h>

Eeprom_at24c256 eeprom(0x50);
/*
 * FOR DETAILED INFORMATION ABOUT HOW THIS WORKS
 * VISIT whole_eeprom_test.ino SKETCH
 * IT COINTAINS EXPLANATION AND DOCUMENTATION
 */
void setup()
{
  Serial.begin(9600);
  char message[30]; //buffer
  Serial.println("now reading first 30 characters of eeprom at address 100");
  eeprom.read(100, (byte *) message, sizeof(message));
  Serial.println(message);

  Serial.println("write \"0123456789-eeprom-test\"(22 characters) to address 100");

  char writemessage[] = "0123456789-eeprom-test";
  eeprom.write(100, (byte*) writemessage, sizeof(writemessage));
  Serial.println("write done, reading");
  char readmessage[30];
  eeprom.read(100, (byte *) readmessage, sizeof(readmessage));
  Serial.println("readed:");
  Serial.println(readmessage);

  Serial.println("DONE");
  }

 void loop()
 {

 }
```