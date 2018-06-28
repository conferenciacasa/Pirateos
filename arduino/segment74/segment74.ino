int c1 = 46;
int c2 = 48;
int c3 = 50;
int c4 = 52;
int a = 30;
int b = 32;
int c = 34;
int d = 36;
int e = 38;
int f = 40;
int g = 42;
int pto = 44;


void setup() {
 pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
   pinMode(c, OUTPUT);
      pinMode(d, OUTPUT);
         pinMode(e, OUTPUT);   
            pinMode(f, OUTPUT);
               pinMode(g, OUTPUT);
                  pinMode(pto, OUTPUT);
                     pinMode(c1, OUTPUT);
                        pinMode(c2, OUTPUT);
                           pinMode(c3, OUTPUT);
                              pinMode(c4, OUTPUT);

}

void loop() {
digitalWrite(c1, 1);
digitalWrite(b, 1);
digitalWrite(c, 1);
digitalWrite(g, 1);
digitalWrite(e, 1);
digitalWrite(f, 1);
delay(1000);
digitalWrite(c1, 0);
digitalWrite(c2, 1);
digitalWrite(a, 0);
digitalWrite(b, 0);
digitalWrite(c, 0);
digitalWrite(d, 0);
digitalWrite(g, 0);
digitalWrite(e, 0);
digitalWrite(f, 0);
digitalWrite(a, 1);
digitalWrite(b, 1);
digitalWrite(c, 1);
digitalWrite(d, 1);
digitalWrite(e, 1);
digitalWrite(f, 1);
delay(1000);
digitalWrite(c2, 0);
delay(1000);


}
