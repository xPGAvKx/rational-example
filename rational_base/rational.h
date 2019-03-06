#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
  private:
    long zaehler, nenner;

  public:
    Rational(long z = 0, long n = 1); //allgemeiner Konstruktor

    //Abfragen
    long getZaehler() const;
    long getNenner() const;

    //arithmetische Methoden für += -= *= /=
    void add(Rational r);
    void sub(Rational r);
    void mult(Rational r);
    void div(Rational r);

    //weitere Methoden
    void set(long zaehler, long nenner);
    void kehrwert();
    void kuerzen();
};

// inline-Methoden
inline Rational::Rational(long z, long n) : zaehler{z}, nenner{n} {}
inline long Rational::getZaehler() const { return zaehler; }
inline long Rational::getNenner() const { return nenner; }

// Globale Funktionsprototypen
Rational add(Rational a, Rational b);
Rational sub(Rational a, Rational b);
Rational mult(Rational a, Rational b);
Rational div(Rational z, Rational n);

void eingabe(Rational& r);
void ausgabe(Rational r, std::ostream& = std::cout); // ostream(Ausgabe in eine Datei)

#endif
