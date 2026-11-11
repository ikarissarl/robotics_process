const byte encodeurA = 2;
const  float PPR = 330;
const float diametreRoue = 0.065; // metres
volatile unsigned long impulsions = 0;

const unsigned long period = 1000;
unsigned long dernierTemps = 0;
unsigned long ancienCompteur = 0;

//motors
const byte ENA = 9;
const byte IN1 = 7;
const byte IN2 = 8;

//consigne
float consigneRPM = 100.0;

//gain pi
float kp = 0.8;
float ki = 0.0;

//variable de regulation
float vitesseRPM = 0;
float erreur = 0;
float integrale = 0;
float commandePWM = 0;



void compterImpulsion(){
  impulsions++;
}

void setup() {
  Serial.begin(9600);

  pinMode(encodeurA, INPUT_PULLUP);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  analogWrite(ENA, 0);
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
    float dtSecondes = dt / 1000.0;

    //mesure la vitesse
    vitesseRPM = (delta / PPR) * (60.0 / dtSecondes);

    //mesure erreur
    erreur = consigneRPM - vitesseRPM;

    //calcul de l'integrale candidate
    float nouvelleIntegrale = integrale + erreur * dtSecondes;
    float commandeCandidate = kp * erreur + ki * nouvelleIntegrale;

    //anti-windup  conditionnel
    if ((commandeCandidate >= 0 && commandeCandidate <= 255)|| (commandeCandidate >255 && erreur < 0)||(commandeCandidate < 0 && erreur >0)){
      integrale = nouvelleIntegrale;
    }

    //PI
    commandePWM = constrain(commandePWM, 0, 255);
    //affichage
    Serial.print("consigne: ");
    Serial.print(consigneRPM);

        Serial.print("  vitesse: ");
    Serial.print(vitesseRPM);
        Serial.print("  WM: ");
    Serial.println(commandePWM);

    /*float rpm = (delta / PPR) * (60000.0 / dt);

    float distance = (compteur / PPR) *PI * diametreRoue;

    float vitesse = (rpm * PI * diametreRoue) / 60.0;

    Serial.print("RPM : ");
    Serial.print(rpm);

    Serial.print("\tvitesse m/s: ");
    Serial.print(vitesse);

    Serial.print("\tdistance m :");
    Serial.println(distance);*/

    ancienCompteur = compteur;
    dernierTemps = maintenant;
  }


}
