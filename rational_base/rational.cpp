#include "rational.h"
#include <cassert>

namespace
{
  long ggt(long x, long y) // ggt wird zum kürzen verwendet - größter gemeinsamer Teiler
  {
    long rest;
    while(y > 0)
    {
      rest = x % y;
      x = y;
      y = rest;
    }
    return x;
  }
}

// Elementfunktionen

void Rational::add(Rational r)
{
  zaehler = zaehler * r.nenner + r.zaehler * nenner;
  nenner = nenner * r.nenner;
  kuerzen();
}

void Rational::sub(Rational r)
{
  zaehler = zaehler * r.nenner - r.zaehler * nenner;
  nenner = nenner * r.nenner;
  kuerzen();
}

void Rational::mult(Rational r)
{
  zaehler = zaehler * r.zaehler;
  nenner = nenner * r.nenner;
  kuerzen();
}

void Rational::div(Rational r)
{
  zaehler = zaehler * r.nenner;
  nenner = nenner * r.zaehler;
  kuerzen();
}

void Rational::set(long z, long n)
{
  zaehler = z;
  nenner = n;
  assert(nenner != 0);
  kuerzen();
}

void Rational::kehrwert()
{
  long temp = zaehler;
  zaehler = nenner;
  nenner = temp;
  assert(nenner != 0);
}

void Rational::kuerzen()
{
  int sign = 1;
  if (zaehler < 0) // Vorzeichen merken und Betrag bilden
  {
    sign = -sign;
    zaehler = -zaehler;
  }
  if (nenner < 0)
  {
    sign = -sign;
    nenner = -nenner;
  }
  long teiler = ggt(zaehler, nenner);
  zaehler = sign * zaehler / teiler; // Vorzeichen restaurieren
  nenner = nenner / teiler;
}

// Globalen arithmetischen Funktionen für die mit 2 Parametern (binäre Operationen)
Rational add(Rational a, Rational b) // Berechnung nicht wiederholen, nur a per Wert übergeben und daher eine Kopie erstellt und mit b addiert;
{
  a.add(b);
  return a;
}

Rational sub(Rational a, Rational b)
{
  a.sub(b);
  return a;
}

Rational mult(Rational a, Rational b)
{
  a.mult(b);
  return a;
}

Rational div(Rational z, Rational n)
{
  z.div(n);
  return z;
}

//Funktion für Ein- und ausgabe
void eingabe(Rational& r)
{
  long int z;
  long int n;
  std::cin >> z >> n;
  assert(n != 0);
  r.set(z, n);
  r.kuerzen();
}

void ausgabe(Rational r, std::ostream& os)
{
  os << r.getZaehler() << "/" << r.getNenner() << '\n';
}
