#include <iostream>
using namespace std;

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
  private:
    int numerator, denominator;

  public:
    Fraction();
    Fraction(int, int);
    Fraction(const Fraction&);
    ~Fraction();
    int getNumerator();
    int getDenominator();
    void setNumerator(int);
    void setDenominator(int);
    string toString();
};

#endif