unsigned long past = 0;
unsigned long past2 = 0;

unsigned long marge = 1000;
unsigned long marge2 = 500;
int led = 7;
int led2 = 8;
bool etat = 0;
bool etat2 = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long now = millis();
  /*Serial.println(now);
  digitalWrite(led, 1);
  delay(1000);
  digitalWrite(led, 0);
  delay(1000);*/

  if(now - past >= marge){
    past = now;
    etat =! etat;
     digitalWrite(led, etat);
    Serial.println(now);
  }
  if(now-past2 >= marge2){
    past2 = now;
    etat2 =! etat2;
    digitalWrite(led2, etat2);
    Serial.println(now);

  }
  

}
