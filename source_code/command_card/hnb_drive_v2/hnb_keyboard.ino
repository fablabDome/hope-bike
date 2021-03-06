// Etat possible des boutons
#define PAS_APPUYE      0
#define APPUYE          1
#define APPUYE_LONG     2
#define RELACHE         3
// pin des boutons
#define BUTTON_GAUCHE   12 
#define BUTTON_MILIEU   14
#define BUTTON_DROIT    27
// type de boutons
#define NORMALLY_ON     0
#define NORMALLY_OFF    1

byte             u8BoutonGauche=PAS_APPUYE;          // Est ce que le bouton gauche est enfoncé 
byte             u8BoutonDroit=PAS_APPUYE;           //droit 
byte             u8BoutonMilieu=PAS_APPUYE;          // milieu

unsigned long TEMPS_ANTI_REBOND = 50;    // the debounce time; increase if the output flickers
unsigned long TEMPS_APPUI_LONG=2000;
unsigned long TEMPS_ATTENTE=2000;

unsigned long tempsGauche=0;
unsigned long tempsDroit=0;
unsigned long tempsMilieu=0;

// type NORMALLY_ON   

//int lectureGaucheAvant=HIGH;
//int lectureDroitAvant=HIGH;
//int lectureMilieuAvant=HIGH;

// type NORMALLY_OFF  

int lectureGaucheAvant=LOW;
int lectureDroitAvant=LOW;
int lectureMilieuAvant=LOW;

//****************************************************************************
// GESTION DU CLAVIER DE COMMANDE
//****************************************************************************

void setup_keyboard(){
  pinMode(BUTTON_GAUCHE, INPUT);
  pinMode(BUTTON_DROIT, INPUT);
  pinMode(BUTTON_MILIEU, INPUT);
  
}

// type NORMALLY_ON ou NORMALLY_OFF  

void gestionClavierMilieu(int type) {
  int lectureMilieu=digitalRead(BUTTON_MILIEU);
  
  if (type==NORMALLY_OFF) {
    if ((lectureMilieu==HIGH)&&(lectureMilieuAvant==LOW)&&(u8BoutonMilieu==PAS_APPUYE))tempsMilieu=millis();
    else if (((millis()-tempsMilieu)>TEMPS_ANTI_REBOND) && (lectureMilieu==HIGH) &&(u8BoutonMilieu==PAS_APPUYE))u8BoutonMilieu=APPUYE;
    else if (((millis()-tempsMilieu)>TEMPS_APPUI_LONG) && (lectureMilieu==HIGH) &&(u8BoutonMilieu==APPUYE)) {u8BoutonMilieu=APPUYE_LONG;tempsMilieu=millis();}
    else if (((millis()-tempsMilieu)>TEMPS_ANTI_REBOND) && (lectureMilieu==LOW)&&(u8BoutonMilieu==APPUYE))u8BoutonMilieu=RELACHE;
  } else if (type==NORMALLY_ON) {
    if ((lectureMilieu==LOW)&&(lectureMilieuAvant==HIGH)&&(u8BoutonMilieu==PAS_APPUYE))tempsMilieu=millis();
    else if (((millis()-tempsMilieu)>TEMPS_ANTI_REBOND) && (lectureMilieu==LOW) &&(u8BoutonMilieu==PAS_APPUYE))u8BoutonMilieu=APPUYE;
    else if (((millis()-tempsMilieu)>TEMPS_APPUI_LONG) && (lectureMilieu==LOW) &&(u8BoutonMilieu==APPUYE)) {u8BoutonMilieu=APPUYE_LONG;tempsMilieu=millis();}
    else if (((millis()-tempsMilieu)>TEMPS_ANTI_REBOND) && (lectureMilieu==HIGH)&&(u8BoutonMilieu==APPUYE))u8BoutonMilieu=RELACHE;
  }
  
  lectureMilieuAvant=lectureMilieu;
  
}

void gestionClavierDroit(int type) {
  //lecture=HIGH lorsqu'on appuit
  int lectureDroit=digitalRead(BUTTON_DROIT);
  
  if (type==NORMALLY_OFF) { 
    if ((lectureDroit==HIGH)&&(lectureDroitAvant==LOW)&&(u8BoutonDroit==PAS_APPUYE))tempsDroit=millis();
    else if (((millis()-tempsDroit)>TEMPS_ANTI_REBOND) && (lectureDroit==HIGH) &&(u8BoutonDroit==PAS_APPUYE))u8BoutonDroit=APPUYE;
    else if (((millis()-tempsDroit)>TEMPS_APPUI_LONG) && (lectureDroit==HIGH) &&(u8BoutonDroit==APPUYE)) {u8BoutonDroit=APPUYE_LONG;tempsDroit=millis();}
    else if (((millis()-tempsDroit)>TEMPS_ANTI_REBOND) && (lectureDroit==LOW)&&(u8BoutonDroit==APPUYE))u8BoutonDroit=RELACHE;
  } else if (type==NORMALLY_ON) { 
    if ((lectureDroit==LOW)&&(lectureDroitAvant==HIGH)&&(u8BoutonDroit==PAS_APPUYE))tempsDroit=millis();
    else if (((millis()-tempsDroit)>TEMPS_ANTI_REBOND) && (lectureDroit==LOW) &&(u8BoutonDroit==PAS_APPUYE))u8BoutonDroit=APPUYE;
    else if (((millis()-tempsDroit)>TEMPS_APPUI_LONG) && (lectureDroit==LOW) &&(u8BoutonDroit==APPUYE)) {u8BoutonDroit=APPUYE_LONG;tempsDroit=millis();}
    else if (((millis()-tempsDroit)>TEMPS_ANTI_REBOND) && (lectureDroit==HIGH)&&(u8BoutonDroit==APPUYE))u8BoutonDroit=RELACHE;
  }  
  lectureDroitAvant=lectureDroit;
}

void gestionClavierGauche(int type) {
  int lectureGauche=digitalRead(BUTTON_GAUCHE);
    if (type==NORMALLY_OFF) { 
      if ((lectureGauche==HIGH)&&(lectureGaucheAvant==LOW)&&(u8BoutonGauche==PAS_APPUYE))tempsGauche=millis();
      else if (((millis()-tempsGauche)>TEMPS_ANTI_REBOND) && (lectureGauche==HIGH) &&(u8BoutonGauche==PAS_APPUYE))u8BoutonGauche=APPUYE;
      else if (((millis()-tempsGauche)>TEMPS_APPUI_LONG) && (lectureGauche==HIGH) &&(u8BoutonGauche==APPUYE)) {u8BoutonGauche=APPUYE_LONG;tempsGauche=millis();}
      else if (((millis()-tempsGauche)>TEMPS_ANTI_REBOND) && (lectureGauche==LOW)&&(u8BoutonGauche==APPUYE))u8BoutonGauche=RELACHE;
    } else if (type==NORMALLY_ON) { 
      if ((lectureGauche==LOW)&&(lectureGaucheAvant==HIGH)&&(u8BoutonGauche==PAS_APPUYE))tempsGauche=millis();
      else if (((millis()-tempsGauche)>TEMPS_ANTI_REBOND) && (lectureGauche==LOW) &&(u8BoutonGauche==PAS_APPUYE))u8BoutonGauche=APPUYE;
      else if (((millis()-tempsGauche)>TEMPS_APPUI_LONG) && (lectureGauche==LOW) &&(u8BoutonGauche==APPUYE)) {u8BoutonGauche=APPUYE_LONG;tempsGauche=millis();}
      else if (((millis()-tempsGauche)>TEMPS_ANTI_REBOND) && (lectureGauche==HIGH)&&(u8BoutonGauche==APPUYE))u8BoutonGauche=RELACHE;
    }  
  lectureGaucheAvant=lectureGauche;

}

void gestionClavier(){
  gestionClavierDroit(NORMALLY_OFF);
  gestionClavierGauche(NORMALLY_OFF);
  gestionClavierMilieu(NORMALLY_OFF);

  // appui long sur le bouton gauche pour affichage detaille
  if (u8BoutonMilieu==APPUYE_LONG) {
    
    switch(MODE){
      case 0 : MODE=1;break;
      case 1 : MODE=3; break;
      case 3 : MODE=0;break;
    }
    u8BoutonMilieu=PAS_APPUYE;
  }
  if ((MODE==0)||(MODE==1)) {
  // gestion de la vitesse
  if ((u8BoutonGauche==RELACHE)&&(speedLevel>=1)) {speedLevel--;u8BoutonGauche=PAS_APPUYE;}
  else if (u8BoutonGauche==APPUYE_LONG) {speedLevel=0; u8BoutonGauche=PAS_APPUYE;}
  if ((u8BoutonDroit==RELACHE)&&(speedLevel<=3)) {speedLevel++;u8BoutonDroit=PAS_APPUYE;}
  else if (u8BoutonDroit==APPUYE_LONG) {speedLevel=3; u8BoutonDroit=PAS_APPUYE;}
  
  if (u8BoutonMilieu==RELACHE) {if (MODE==1)MODE=0; else if (MODE==0)MODE=1;u8BoutonMilieu=PAS_APPUYE;}
  else if (u8BoutonMilieu==APPUYE_LONG) {MODE=3;u8BoutonMilieu=PAS_APPUYE;}
  
  // Fonction speciale
  // appui long sur le bouton du milieu pour passer en mode commande par PWM
  //if (u8BoutonMilieu==APPUYE_LONG) {MODE=3;u8BoutonMilieu=PAS_APPUYE;}
  // appui long sur le bouton droit pour affichage normal
  //if 
  //
  
  
  } else if (MODE==3){ 
  // gestion du PWM
      if (u8BoutonGauche==RELACHE) {i16PWM=i16PWM-50;u8BoutonGauche=PAS_APPUYE;}
      else if (u8BoutonGauche==APPUYE_LONG) u8BoutonGauche=PAS_APPUYE;
      if (u8BoutonDroit==RELACHE)  {i16PWM=i16PWM+50;u8BoutonDroit =PAS_APPUYE;}
      else if (u8BoutonDroit==APPUYE_LONG) u8BoutonDroit=PAS_APPUYE;
      if (u8BoutonMilieu==RELACHE) {u8BoutonMilieu=PAS_APPUYE;}
      else if (u8BoutonMilieu==APPUYE_LONG) {MODE=1;u8BoutonMilieu=PAS_APPUYE;}
     
  }
  
  
  
}
