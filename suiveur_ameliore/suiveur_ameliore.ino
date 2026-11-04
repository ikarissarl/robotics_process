const int ena = 5, in1 = 6, in2 = 7, in3 = 9, in4 = 8, enb = 10;
const int cap1 = 2, cap2 = 3, cap3 = 4, cap4 = 11, cap5 = 12;
int capt1 = digitalRead(cap1);
  int capt2 = digitalRead(cap2);
  int capt3 = digitalRead(cap3);
  int capt4 = digitalRead(cap4);
  int capt5 = digitalRead(cap5);


void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  pinMode(cap1, INPUT);
  pinMode(cap2, INPUT);
  pinMode(cap3, INPUT);
  pinMode(cap4, INPUT);
  pinMode(cap5, INPUT);
}

void loop() {
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

  final();
}


void avancer() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(ena, 50);
  analogWrite(enb, 50);
}

void reculer() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(ena, 100);
  analogWrite(enb, 100);
}

void arreter() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(ena, 0);
  analogWrite(enb, 0);
}

void gauche() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(ena, 50);
  analogWrite(enb, 50);
}

void droite() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(ena, 50);
  analogWrite(enb, 50);
}

void rotation_g() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(ena, 90);
  analogWrite(enb, 90);
}
void rotation_d() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(ena, 180);
  analogWrite(enb, 180);
}
void lecteur() {

  capt1 = digitalRead(cap1);
  capt2 = digitalRead(cap2);
  capt3 = digitalRead(cap3);
  capt4 = digitalRead(cap4);
  capt5 = digitalRead(cap5);
}

void final() {
    /*int capt1 = digitalRead(cap1);
    int capt2 = digitalRead(cap2);
    int capt3 = digitalRead(cap3);
    int capt4 = digitalRead(cap4);
    int capt5 = digitalRead(cap5);*/

  //avancer
  lecteur();
  if (capt1 == 0 && capt2 == 0 && capt3 == 1 && capt4 == 0 && capt5 == 0) {
    avancer();
    delay(1);
    
    lecteur();
     //trait interompu
    if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
      avancer();
      delay(100);
    }
    else if (capt1 == 1 && capt2 == 1 && capt3 == 1 && capt4 == 1 && capt5 == 1) {
      arreter();
    }

  }

  //ajustement
  else if (capt1 == 0 && capt2 == 1 && capt3 == 1 && capt4 == 0 && capt5 == 0) {
    gauche();
    delay(1);

    lecteur();
     //trait interompu
    if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
      rotation_g();
      delay(10);
      avancer();
      delay(100);
    }
    else if (capt1 == 1 && capt2 == 1 && capt3 == 1 && capt4 == 1 && capt5 == 1) {
      avancer();
      delay(200);
      Serial.println("dans le noir");
      //contrainte virage faux trait noir

      lecteur();
      arreter();
      //ce n'est pas un double noir
      if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
      rotation_g();
      delay(250);
      Serial.println("dans le blanc");
      lecteur();
        if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
        arreter();
        Serial.println("dans le blanc");
        }
      }
    }
  } 
  else if (capt1 == 0 && capt2 == 0 && capt3 == 1 && capt4 == 1 && capt5 == 0) {
    droite();
    delay(1);
    lecteur();

     //trait interompu
    if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
      rotation_d();
      delay(10);
      avancer();
      delay(100);
    }
    else if (capt1 == 1 && capt2 == 1 && capt3 == 1 && capt4 == 1 && capt5 == 1) {
      avancer();
      delay(200);
      Serial.println("dans le noir");
      //contrainte virage faux trait noir

      lecteur();
      arreter();
      //ce n'est pas un double noir
      if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
      rotation_g();
      delay(250);
      Serial.println("dans le blanc");
      lecteur();
        if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
        arreter();
        Serial.println("dans le blanc");
        }
      }
    }
  }

  //virage droit 90degre
  else if (capt1 == 0 && capt2 == 0 && capt3 == 1 && capt4 == 1 && capt5 == 1) {
    avancer();
    delay(70);
    arreter();
    delay(1000);

    lecteur();
    //contrainte deux lignes noires
    if (capt1 == 1 && capt2 == 1 && capt3 == 1 && capt4 == 1 && capt5 == 1) {
      avancer();
      delay(250);
      Serial.println("dans le noir");

      lecteur();
      //ce n'est pas un double noir
      if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
      rotation_g();
      delay(250);
      Serial.println("dans le blanc");
      lecteur();
        if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
        arreter();
        Serial.println("dans le blanc");
        }
      }
    } 
    else {
      avancer();
      delay(150);
      rotation_d();
      delay(100);
      Serial.println("virage");
    }
  } 
  else if (capt1 == 0 && capt2 == 1 && capt3 == 1 && capt4 == 1 && capt5 == 1) {
    avancer();
    delay(70);
    arreter();

    lecteur();
    //contrainte deux lignes
    if (capt1 == 1 && capt2 == 1 && capt3 == 1 && capt4 == 1 && capt5 == 1) {
      avancer();
      delay(200);
      Serial.println("dans le noir");

      lecteur();
      arreter();

      //ce n'est pas un double noir
      if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
      rotation_g();
      delay(250);
      Serial.println("dans le blanc");

      lecteur();
        if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
        arreter();
        Serial.println("dans le blanc");
        }
      }
    } else {
      avancer();
      delay(150);
      rotation_d();
      delay(100);
      Serial.println("virage");
    }
  }

  //contrainte sortie virage n1 10 essais
  else if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 1 && capt5 == 1) {  //3/10
    avancer();
    delay(100);
    rotation_d();
    delay(50);
  } 
  else if (capt1 == 0 && capt2 == 1 && capt3 == 1 && capt4 == 1 && capt5 == 0) {  //1/10
    avancer();
    delay(100);
    rotation_d();
    delay(50);
  } 
  else if (capt1 == 0 && capt2 == 1 && capt3 == 0 && capt4 == 0 && capt5 == 0) {  //6/10
    avancer();
    delay(100);
    rotation_d();
    delay(50);
  }


  //rotation 90 degre gauche
  else if (capt1 == 1 && capt2 == 1 && capt3 == 1 && capt4 == 1 && capt5 == 0) {
    avancer();
    delay(70);
    arreter();

    lecteur();
    //contrainte avec deux lignes noires
    if (capt1 == 1 && capt2 == 1 && capt3 == 1 && capt4 == 1 && capt5 == 1) {
      avancer();
      delay(200);
      Serial.println("dans le noir");
      //contrainte virage faux trait noir

      lecteur();
      arreter();
      //ce n'est pas un double noir
      if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
      rotation_g();
      delay(250);
      Serial.println("dans le blanc");
      lecteur();
        if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
        arreter();
        Serial.println("dans le blanc");
        }
      }
    } 
    else {
      avancer();
      delay(150);
      rotation_g();
      delay(100);
      Serial.println("virage");
    }
  } 
  else if (capt1 == 1 && capt2 == 1 && capt3 == 1 && capt4 == 0 && capt5 == 0) {
    avancer();
    delay(70);

    lecteur();
    arreter();
    //contrainte avec deux lignes noires
    if (capt1 == 1 && capt2 == 1 && capt3 == 1 && capt4 == 1 && capt5 == 1) {
      avancer();
      delay(200);
      Serial.println("dans le noir");
      lecteur();
      arreter();

      //ce n'est pas un double noir
      if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
      rotation_g();
      delay(250);
      Serial.println("dans le blanc");
      lecteur();
        if (capt1 == 0 && capt2 == 0 && capt3 == 0 && capt4 == 0 && capt5 == 0) {
        arreter();
        Serial.println("dans le blanc");
        }
      }
    } 
    else {
      avancer();
      delay(150);
      rotation_g();
      delay(100);
      Serial.println("virage");
    }
  } 
  else if (capt1 == 0 && capt2 == 0 && capt3 == 1 && capt4 == 0 && capt5 == 1) {  //5/5
    avancer();
    delay(150);
    rotation_d();
    delay(400);
  }
  }



  //else
  //else{
  // arreter();
  //}

