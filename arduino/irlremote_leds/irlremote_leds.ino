#include "IRLremote.h"
#include <Servo.h>
Servo s;
const int interruptIR = 0;

uint8_t IRProtocol = 0;  // Variables para recibir los datos
uint16_t IRAddress = 0;
uint32_t IRCommand = 0;

void setup() 
   {
    pinMode(22, OUTPUT); 
    Serial.begin(115200);          // Fijate en la velocidad
        for (int i = 3 ; i<12 ; i++)
        pinMode(i, OUTPUT);
        s.attach(3);        
        IRLbegin<IR_ALL>(interruptIR);
              }
   
   void loop()
   {    uint8_t oldSREG = SREG;  // Parar las interrupciones
        cli();
        if (IRProtocol)
          {  
              switch (IRCommand) // Aqui tenemos la clausula switch con sus case:
                  { case 0x6897:
                        Serial.println("0");
                        digitalWrite(4, HIGH);
                        break;
                    case 0x30CF:
                        Serial.println("1");
                        digitalWrite(5, HIGH);
                        break;
                    case 0x18E7:
                         Serial.println("2");
                         digitalWrite(6, HIGH);
                         break;
                    case 0x7A85:
                         Serial.println("3");
                         digitalWrite(7, HIGH);
                         break;
                    case 0x10EF:
                         Serial.println("4"); 
                              digitalWrite(8, HIGH);
                         break;
                    case 0x38C7:
                         Serial.println("5"); 
                              digitalWrite(9, HIGH);
                         break;
                         case 0x5AA5:
                         Serial.println("6"); 
                              digitalWrite(10, HIGH);
                         break;
                         case 0x42BD:
                         digitalWrite(11, HIGH);
                         Serial.println("7"); 
                        
                         break;
                    case 0x22DD:
                         Serial.println("I");
                         s.write(175);
                         break;
                    case 0x2FD:
                         Serial.println("D");
                         s.write(0);
                         break;
                    case 0x906F:
                         Serial.println("M");
                         s.write(90);
                         break;
                         case 0xA857:
                         Serial.println("luces/encendidas");
                         digitalWrite(22, HIGH);
                         break;
                         case 0xE01F:
                         Serial.println("luces/apagadas");
                         digitalWrite(22, LOW);
                         break;                                
                    case 0xC23D:
                         Serial.println("P/P");
                         for (int k =0 ; k <12 ; k++) 
                              digitalWrite(k, LOW);
                         break;
                         case 0xB04F:
                         Serial.println("LOCUROTE");
                         
                          
                         break;

                  }
              IRProtocol = 0;
          }
       SREG = oldSREG; 
    }
void IREvent(uint8_t protocol, uint16_t address, uint32_t command)
   {
        IRProtocol = protocol;  // Recogemos los valores
        IRAddress = address;
        IRCommand = command;
   }
