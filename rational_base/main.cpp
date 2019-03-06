#include "rational.h"
#include <iostream>
using namespace std;

namespace
{ // alle 4 Operationen für a und b
  void druckeTestfall(Rational a, Rational b)
  {
    Rational erg;
    cout << "a = ";
    ausgabe(a);
    cout << "b = ";
    ausgabe(b);
    erg = add(a, b);
    cout << "+  : ";
    ausgabe(erg);
    erg = sub(a, b);
    cout << "-  : ";
    ausgabe(erg);
    erg = mult(a, b);
    cout << "*  : ";
    ausgabe(erg);
    erg = div(a, b);
    cout << "/  : ";
    ausgabe(erg);
    cout << '\n';
  }
}

int main()
{
  cout << "Bitte Zähler und Nenner der 1. Zahl eingeben:";
  Rational a;
  eingabe(a);
  cout << "Bitte Zähler und Nenner der 2. Zahl eingeben:";
  Rational b;
  eingabe(b);
  druckeTestfall(a, b);

  cout << "\n Test mit verschiedenen Vorzeichen\n";
  a.set(3, 7);
  b.set(6, 13);
  druckeTestfall(a, b);
  a.set(3, -7);
  druckeTestfall(a, b);
  //..undso weiter
  cout << "\n Test mit gemischten Datentypen\n";
  a.set(2301, 77777);
  druckeTestfall(a, 17);
  druckeTestfall(17, a);

  cout << "\n Test mit Nullwerten\n";
  a.set(0, 7);
  b.set(6, 13);
  druckeTestfall(a, b);
  cout << "Bei einem Nenner = 0 wird ein Fehler provoziert!\n";
  a.set(3, 0);
  druckeTestfall(a, b);
}
