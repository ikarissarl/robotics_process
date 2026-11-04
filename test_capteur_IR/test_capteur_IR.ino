
const int cap1 = 2, cap2 = 3, cap3 = 4, cap4 = 11, cap5 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(cap1, INPUT);
  pinMode(cap2, INPUT);
  pinMode(cap3, INPUT);
  pinMode(cap4, INPUT);
  pinMode(cap5, INPUT);
}

void loop() {

int capt1 = digitalRead(cap1);
int capt2 = digitalRead(cap2);
int capt3 = digitalRead(cap3);
int capt4 = digitalRead(cap4);
int capt5 = digitalRead(cap5);
  Serial.print("valeur1 : ");
  Serial.print(capt1);
  Serial.print(" ");
  Serial.print("valeur2 : ");
  Serial.print(capt2);
  Serial.print(" ");
  Serial.print("valeur3 : ");
  Serial.print(capt3);
  Serial.print(" ");
  Serial.print("valeur4 : ");
  Serial.print(capt4);
  Serial.print(" ");
  Serial.print("valeur5 : ");
  Serial.print(capt5);
  Serial.println(" ");


  delay(1);

}
