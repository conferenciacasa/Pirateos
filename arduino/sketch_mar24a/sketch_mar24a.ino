int in3 = 9;
int in4 = 8;

void setup() {
 pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
delay(1000);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
delay(1000);
                      
                        
  // put your main code here, to run repeatedly:

}
