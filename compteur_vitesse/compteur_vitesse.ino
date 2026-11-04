const byte encodeurA = 2;
const  float PPR = 600;
const float diametreRoue = 0.065; // metres
volatile unsigned long impulsions = 0;

unsigned long dernierTemps = 0;
unsigned long ancienCompteur = 0;

const unsigned long period = 1000;
void compterImpulsion(){
  impulsions++;
}

void setup() {
  Serial.begin(9600);
  pinMode(encodeurA, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(encodeurA),
    compterImpulsion,
    RISING
  );

  dernierTemps = millis();

  
}

void loop() {

  unsigned long maintenant = millis();
  if (maintenant - dernierTemps >= period){
    unsigned long compteur;

    noInterrupts();
    compteur = impulsions;
    interrupts();
    unsigned long delta = compteur - ancienCompteur;
    unsigned long dt = maintenant - dernierTemps;

    float rpm = (delta / PPR) * (60000.0 / dt);

    float distance = (compteur / PPR) *PI * diametreRoue;

    float vitesse = (rpm * PI * diametreRoue) / 60.0;

    Serial.print("RPM : ");
    Serial.print(rpm);

    Serial.print("\tvitesse m/s: ");
    Serial.print(vitesse);

    Serial.print("\tdistance m :");
    Serial.println(distance);

    ancienCompteur = compteur;
    dernierTemps = maintenant;
  }


}
