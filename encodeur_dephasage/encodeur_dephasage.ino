const int signal_a = 2;
const int signal_b = 3;
volatile long impulse = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(signal_a, INPUT_PULLUP);
  pinMode(signal_b, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(signal_a),
    impulsion,
    RISING);
  

}

void loop() {
  // put your main code here, to run repeatedly:

   long compteur;
  noInterrupts();
  compteur = impulse;
  interrupts();
  Serial.println(compteur);
  delay(500);

}

void impulsion(){
  if (digitalRead(signal_b) == LOW){
    impulse++;
  }
else{
  impulse--;
  }
}