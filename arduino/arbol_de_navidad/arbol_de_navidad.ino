//(C)Info Online 2017
//Todos los derechos reservados

#define PULSADOR 0      //Pin 0  (INPUT) --> Pulsador
#define BUZZER 1        //Pin 1 (OUTPUT) --> buzzer PWM
#define lED_ROJO 2      //Pin 2 (OUTPUT) --> contador 1
#define lED_VERDE 3     //Pin 3 (OUTPUT) --> contador 2
#define lED_AMARILLO 4  //Pin 4 (OUTPUT) --> contador 3
int contador = 0;
int resto;

void setup() {
  // Definimos los pines como entrada o salida
  pinMode(PULSADOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(lED_ROJO, OUTPUT);
  pinMode(lED_VERDE, OUTPUT);
  pinMode(lED_AMARILLO, OUTPUT);
  digitalWrite(PULSADOR, HIGH);
  cancion();
  delay(500);
  cancion();
  contador = 158;
}

void loopcontador() {
  if (contador >= 0 && contador <= 24) { //24
    resto = contador % 3;
    if (resto == 0) soloRojoOn();
    if (resto == 1) soloAmarilloOn();
    if (resto == 2) soloVerdeOn();
  }

  if (contador >= 25 && contador <= 69) { //46
    resto = (contador - 25) % 6;
    if (resto == 0) soloAmarilloOn();
    if (resto == 1) soloVerdeOn();
    if (resto == 2) soloRojoVerdeOn();
    if (resto == 3) soloAmarilloVerdeOn();
    if (resto == 4) todosOn();
    if (resto == 5) soloRojoOn();
    delay(125);
  }

  if (contador >= 70 && contador <= 93) { //24
    resto = (contador - 70)  % 3;
    if (resto == 0) soloRojoOn();
    if (resto == 1) soloAmarilloOn();
    if (resto == 2) soloVerdeOn();
  }

  if (contador >= 94 && contador <= 133) { //40
    resto = (contador - 94) % 8;
    if (resto == 0) soloRojoOn();
    if (resto == 2) soloAmarilloOn();
    if (resto == 4) soloVerdeOn();
    if (resto == 6) soloAmarilloOn();
  }

  if (contador >= 134 && contador <= 157) { //24
    resto = (contador - 134) % 3;
    if (resto == 0) soloRojoOn();
    if (resto == 1) soloAmarilloOn();
    if (resto == 2) soloVerdeOn();
  }

  if (contador >= 158 && contador <= 205) { //48
    resto = (contador - 158) % 8;
    if (resto == 0) todosOn();
    if (resto == 4) todosOff();
  }

  contador = contador + 1;
  if (contador > 206) contador = 0;
}

void soloRojoOn() {
  digitalWrite(lED_ROJO, HIGH);
  digitalWrite(lED_AMARILLO, LOW);
  digitalWrite(lED_VERDE, LOW);
}

void soloAmarilloOn() {
  digitalWrite(lED_ROJO, LOW);
  digitalWrite(lED_AMARILLO, HIGH);
  digitalWrite(lED_VERDE, LOW);
}

void soloVerdeOn() {
  digitalWrite(lED_ROJO, LOW);
  digitalWrite(lED_AMARILLO, LOW);
  digitalWrite(lED_VERDE, HIGH);
}

void soloRojoVerdeOn() {
  digitalWrite(lED_ROJO, HIGH);
  digitalWrite(lED_AMARILLO, LOW);
  digitalWrite(lED_VERDE, HIGH);
}

void soloAmarilloVerdeOn() {
  digitalWrite(lED_ROJO, LOW);
  digitalWrite(lED_AMARILLO, HIGH);
  digitalWrite(lED_VERDE, HIGH);
}

void todosOn() {
  digitalWrite(lED_ROJO, HIGH);
  digitalWrite(lED_AMARILLO, HIGH);
  digitalWrite(lED_VERDE, HIGH);
}

void todosOff() {
  digitalWrite(lED_ROJO, LOW);
  digitalWrite(lED_VERDE, LOW);
  digitalWrite(lED_AMARILLO, LOW);
}


















void tonoArbol (int frecuency, float duration)
{
  tone(BUZZER, frecuency, duration);
  loopcontador();
  if (contador > 2) contador = 0;
}











void cancion() {
  delay(86.8054166667);
  tonoArbol(311, 312.4995);
  delay(347.221666667);
  tonoArbol(415, 312.4995);
  delay(347.221666667);
  tonoArbol(415, 156.24975);
  delay(173.610833333);
  tonoArbol(466, 156.24975);
  delay(173.610833333);
  tonoArbol(415, 156.24975);
  delay(173.610833333);
  tonoArbol(391, 156.24975);
  delay(173.610833333);
  tonoArbol(349, 312.4995);
  delay(347.221666667);
  tonoArbol(349, 234.374625);
  delay(260.41625);
  delay(86.8054166667);
  tonoArbol(349, 312.4995);
  delay(347.221666667);
  tonoArbol(466, 312.4995);
  delay(347.221666667);
  tonoArbol(466, 156.24975);
  delay(173.610833333);
  tonoArbol(523, 156.24975);
  delay(173.610833333);
  tonoArbol(466, 156.24975);
  delay(173.610833333);
  tonoArbol(415, 156.24975);
  delay(173.610833333);
  tonoArbol(391, 312.4995);
  delay(347.221666667);
  tonoArbol(311, 234.374625);
  delay(260.41625);
  delay(86.8054166667);
  tonoArbol(311, 312.4995);
  delay(347.221666667);
  tonoArbol(523, 312.4995);
  delay(347.221666667);
  tonoArbol(523, 156.24975);
  delay(173.610833333);
  tonoArbol(554, 156.24975);
  delay(173.610833333);
  tonoArbol(523, 156.24975);
  delay(173.610833333);
  tonoArbol(466, 156.24975);
  delay(173.610833333);
  tonoArbol(415, 312.4995);
  delay(347.221666667);
  tonoArbol(349, 234.374625);
  delay(260.41625);
  delay(86.8054166667);
  tonoArbol(311, 156.24975);
  delay(173.610833333);
  tonoArbol(311, 156.24975);
  delay(173.610833333);
  tonoArbol(349, 234.374625);
  delay(260.41625);
  delay(86.8054166667);
  tonoArbol(466, 234.374625);
  delay(260.41625);
  delay(86.8054166667);
  tonoArbol(391, 234.374625);
  delay(260.41625);
  delay(86.8054166667);
  tonoArbol(415, 546.874125);
  delay(607.637916667);
  delay(86.8054166667);
  tonoArbol(311, 312.4995);
  delay(347.221666667);
  tonoArbol(415, 312.4995);
  delay(347.221666667);
  tonoArbol(415, 312.4995);
  delay(347.221666667);
  tonoArbol(415, 312.4995);
  delay(347.221666667);
  tonoArbol(391, 624.999);
  delay(694.443333333);
  tonoArbol(391, 312.4995);
  delay(347.221666667);
  tonoArbol(415, 312.4995);
  delay(347.221666667);
  tonoArbol(391, 312.4995);
  delay(347.221666667);
  tonoArbol(349, 312.4995);
  delay(347.221666667);
  tonoArbol(311, 546.874125);
  delay(607.637916667);
  delay(86.8054166667);
  tonoArbol(466, 312.4995);
  delay(347.221666667);
  tonoArbol(523, 312.4995);
  delay(347.221666667);
  tonoArbol(466, 312.4995);
  delay(347.221666667);
  tonoArbol(415, 312.4995);
  delay(347.221666667);
  tonoArbol(622, 312.4995);
  delay(347.221666667);
  tonoArbol(311, 312.4995);
  delay(347.221666667);
  tonoArbol(311, 156.24975);
  delay(173.610833333);
  tonoArbol(311, 156.24975);
  delay(173.610833333);
  tonoArbol(349, 234.374625);
  delay(260.41625);
  delay(86.8054166667);
  tonoArbol(466, 234.374625);
  delay(260.41625);
  delay(86.8054166667);
  tonoArbol(391, 234.374625);
  delay(260.41625);
  delay(86.8054166667);
  tonoArbol(415, 546.874125);
  delay(607.637916667);
}
// Programa principal se repite constantemente:
void loop() {
  if (digitalRead(PULSADOR) == LOW) {
    cancion();
    delay(500);
    cancion();
    contador = 158;
  }
  loopcontador();
  delay(250);
} 

