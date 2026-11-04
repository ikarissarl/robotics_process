const int signal_a = 2;
const int signal_b = 3;
volatile unsigned long impulse = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(signal_a, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(signal_a),
    impulsion,
    RISING);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long compteur;
  noInterrupts();
  compteur = impulse;
  interrupts();
  Serial.println(compteur);
  delay(500);

}

void impulsion(){
  impulse ++;
}
