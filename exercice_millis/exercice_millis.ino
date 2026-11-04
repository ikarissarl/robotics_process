unsigned long past = 0;
unsigned long past2 = 0;
const int capt = 4;
const int led = 5;

unsigned long marge = 500;
unsigned long marge2 = 50;
bool etat = 0;
bool etat2 = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(capt, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long now = millis();


  if(now - past >= marge2){
    past = now;
    etat =! etat;
    int cap = digitalRead(capt);
    if(cap == 1){
    
    digitalWrite(led, HIGH);
    }
    else{
     
      digitalWrite(led, LOW);
    }


  }

  if(now - past2 >= marge){
    past2 = now;
    etat2 =! etat2;
    int cap = digitalRead(capt);

    Serial.print("la valeur est de :");
     Serial.println( cap);

  }
}
