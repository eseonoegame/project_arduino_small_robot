#include "C:\Users\noega\Documents\Arduino\libraries\Keyboard.h"

#include "stratKeyboard.h" // INCLURE LA STRATEGIE


// ---- Définition des variables. ----
#define IN1 4 // carte pilote | carte arduino
#define IN2 5
#define IN3 6
#define IN4 7

// variables pour capteur de distance
const int trigPin = 11; // Trigger (émission)
const int echoPin = 12; // Echo (réception)
long duree;    // durée de l'echo
int distance;  // distance

const int periodeD = 2000;
unsigned long debut = 0;

// ---- Définition des fonctions. ----

void setup() // initalise les broches de la carte en entré ou sortie.
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trigPin, OUTPUT);   // Configuration du port du Trigger comme une SORTIE
  pinMode(echoPin, INPUT);    // Configuration du port de l'Echo comme une ENTREE
  Serial.begin(9600);         // Démarrage de la communication série
}

int getDistance() // retourne la distance déterminé par le capteur.
{
  int d;
  // Émission d'un signal de durée 10 microsecondes
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Écoute de l'écho
  duree = pulseIn(echoPin, HIGH);
  // Calcul de la distance
  d = duree * 0.034 / 2; //distance = 1/2 vitesse du son fois la durée 
  // Affichage de la distance dans le Moniteur Série
  return d;
}

void testDistance(int t) // test distance tout les t secondes.
{
  if ((millis()-debut) > t)
  {
    distance = getDistance();
    Serial.print(distance);
    Serial.print("\n");
    debut = millis();
  }
}

void setSpeed(int speed) // permet de régler la vitesse.
{
  Serial.print("rien");
}

void rightRotor(int state, int speed) // met à l'etat 0,1,2 (éteint, avant, arrière) le moteur droit à la vitesse speed.
{
  switch (state)
  {
    case 0:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

    case 1:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
  }
}

void leftRotor(int state, int speed) // met à l'etat 0,1,2 (éteint, avant, arrière) le moteur gauche à la vitesse speed.
{
  switch (state)
  {
    case 0:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

    case 1:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
  }
}

void stratAutonome() // stratégie du robot
{
  if (getDistance() > 30)
  {
    //tourner de 90 degré à droite
  }
  else
  {
    //avancer 
  }
}



// ---- MAIN ----

void loop() 
{
  stratKeyboard();
}










