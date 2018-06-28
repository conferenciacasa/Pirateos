#define CARACTER_INICIO_CMD '*'
#define CARACTER_FINAL_CMD '#'
#define CARACTER_DIV_CMD '|'
#define ESCRITURA_DIGITAL_CMD 10
#define ESCRITURA_ANALOGA_CMD 11
#define TEXTO_CMD 12
#define LECTURA_ARDUDROID_CMD 13
#define MAX_COMMAND 20  
#define MIN_COMMAND 10 
#define LONGITUD_ENTRADA_STRING 40
#define ESCRITURA_ANALOGICA_MAX 255
#define PIN_ALTO 3
#define PIN_BAJO 2

String inText;

void setup() {
  Serial.begin(9600);
  Serial.println("elprofegarcia.com");
  Serial.flush();
}

void loop()
{
  Serial.flush();
  int ard_command = 0;
  int pin_num = 0;
  int pin_value = 0;

  char get_char = ' ';  //lee serial

  // esperar a que los datos entren
  if (Serial.available() < 1) return; // si no hay datos en el serial retornar al Loop().

  // analizar entrada de indicador de inicio de comando
  get_char = Serial.read();
  if (get_char != CARACTER_INICIO_CMD) return; // si no hay indicación de inicio del sistema, volver  loop ().
  // parse incoming command type
  ard_command = Serial.parseInt(); // read the command
  
  // analizar el tipo de comando entrante
  pin_num = Serial.parseInt(); // leer el pin
  pin_value = Serial.parseInt();  // leer el valor

  // 1) OBTENER COMANDO DE TEXTO PARA ARDUDROID
  if (ard_command == TEXTO_CMD){   
    inText =""; // borra variable para nueva entrada
    while (Serial.available())  {
      char c = Serial.read();  // recibe un byte de la memoria intermedia serie
      delay(5);
      if (c == CARACTER_FINAL_CMD) { // si la cadena completa ha sido leida
        // add your code here
        break;
      }              
      else {
        if (c !=  CARACTER_DIV_CMD) {
          inText += c; 
          delay(5);
        }
      }
    }
  }

  // 2) OBTENER DATOS DE digitalWrite ARDUDROID
  if (ard_command == ESCRITURA_DIGITAL_CMD){  
    if (pin_value == PIN_BAJO) pin_value = LOW;
    else if (pin_value == PIN_ALTO) pin_value = HIGH;
    else return; // error en el valor de PIN. regresar.
    set_digitalwrite( pin_num,  pin_value);  // Eliminar el comentario de esta función para utilizarla
    return;  // regrese al inicio de loop()
  }

  // 3) GET analogWrite DATA FROM ARDUDROID
  if (ard_command == ESCRITURA_ANALOGA_CMD) {  
    analogWrite(  pin_num, pin_value ); 
    // add your code here
    return;  // Done. return to loop();
  }

  // 4) Enviar datos a ARDUDROID
  if (ard_command == LECTURA_ARDUDROID_CMD) { 
    // char send_to_android[] = " Coloca el texto aquí." ;
    // Serial.println(send_to_android);   // Ejemplo: Envío de texto
    Serial.print(" Analogo 0 = "); 
    Serial.println(analogRead(A0));  // Ejemplo: Leer y enviar valor analógico del Pin de Arduino
    return;  // Listoe. regrese al loop();
  }
}

// 2a) seleccionar el pin # solicitado para la acción digitalWrite
void set_digitalwrite(int pin_num, int pin_value)
{
  switch (pin_num) {
  case 13:
    pinMode(13, OUTPUT);
    digitalWrite(13, pin_value);  
    // adicione su código aquí, para este número de pin del Arduino
    break;
  case 12:
    pinMode(12, OUTPUT);
    digitalWrite(12, pin_value);   
    // adicione su código aquí, para este número de pin del Arduino
    break;
  case 11:
    pinMode(11, OUTPUT);
    digitalWrite(11, pin_value);         
    // adicione su código aquí, para este número de pin del Arduino
    break;
  case 10:
    pinMode(10, OUTPUT);
    digitalWrite(10, pin_value);         
    // adicione su código aquí, para este número de pin del Arduino
    break;
  case 9:
    pinMode(9, OUTPUT);
    digitalWrite(9, pin_value);         
    // adicione su código aquí, para este número de pin del Arduino
    break;
  case 8:
    pinMode(8, OUTPUT);
    digitalWrite(8, pin_value);         
    // adicione su código aquí, para este número de pin del Arduino
    break;
  case 7:
    pinMode(7, OUTPUT);
    digitalWrite(7, pin_value);         
    // adicione su código aquí, para este número de pin del Arduino
    break;
  case 6:
    pinMode(6, OUTPUT);
    digitalWrite(6, pin_value);         
    // adicione su código aquí, para este número de pin del Arduino
    break;
  case 5:
    pinMode(5, OUTPUT);
    digitalWrite(5, pin_value); 
    // adicione su código aquí, para este número de pin del Arduino 
    break;
  case 4:
    pinMode(4, OUTPUT);
    digitalWrite(4, pin_value);         
    // adicione su código aquí, para este número de pin del Arduino
    break;
  case 3:
    pinMode(3, OUTPUT);
    digitalWrite(3, pin_value);         
    // adicione su código aquí, para este número de pin del Arduino
    break;
  case 2:
    pinMode(2, OUTPUT);
    digitalWrite(2, pin_value); 
    // adicione su código aquí, para este número de pin del Arduino
    break;      
    // por defecto
    // si nada más fue seleccionado, hacer el defecto (default)
    // default es opcional
    case 22:
    pinMode(22, OUTPUT);
    digitalWrite(22, pin_value);   
    // adicione su código aquí, para este número de pin del Arduino
    break;
    case 23:
    pinMode(23, OUTPUT);
    digitalWrite(23, pin_value);   
    // adicione su código aquí, para este número de pin del Arduino
    break;
    case 24:
    pinMode(24, OUTPUT);
    digitalWrite(24, pin_value);   
    // adicione su código aquí, para este número de pin del Arduino
    break;
    case 25:
    pinMode(25, OUTPUT);
    digitalWrite(25, pin_value);   
    // adicione su código aquí, para este número de pin del Arduino
    break;
    case 26:
    pinMode(26, OUTPUT);
    digitalWrite(26, pin_value);   
    // adicione su código aquí, para este número de pin del Arduino
    break;
    case 27:
    pinMode(27, OUTPUT);
    digitalWrite(27, pin_value);   
    // adicione su código aquí, para este número de pin del Arduino
    break;
    
    case 28:
    pinMode(28, OUTPUT);
    digitalWrite(28, pin_value);   
    // adicione su código aquí, para este número de pin del Arduino
    break;
    case 29:
    pinMode(29, OUTPUT);
    digitalWrite(29, pin_value);   
    // adicione su código aquí, para este número de pin del Arduino
    break;
    case 30:
    pinMode(30, OUTPUT);
    digitalWrite(30, pin_value);   
    // adicione su código aquí, para este número de pin del Arduino
    break;

  } 
}
