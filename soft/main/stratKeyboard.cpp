#include "C:\Users\noega\Documents\Arduino\libraries\Keyboard.h"

void stratKeyboard() // stratégie robot commandé via clavier.
{
  if (Keyboard.available())  // Si une touche a été appuyée sur le clavier
  {
    char key = Keyboard.read(); // Lis la touche appuyée
    if (key == 'a') 
    {
      Serial.print(key);
      // avancer 
    }
    else if (key == 'z') 
    {
      Serial.print(key);
      //reculer
    }
    else if (key == 'q') 
    {
      Serial.print(key);
      // gauche
    }
    else if (key == 'd') 
    {
      Serial.print(key);
      //droite
    }
  }
  else 
  {
    // ne pas avancer
  }
}
