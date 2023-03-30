#include "Fraction.h"

Fraction::Fraction()
{
  numerator = 1;
  denominator = 1;
}

Fraction::Fraction(int n, int d)
{
  setNumerator(n);
  setDenominator(d);
}

Fraction::~Fraction()
{

}

Fraction::Fraction(const Fraction& other)
{
  setNumerator(other.numerator);
	setDenominator(other.denominator);
}

void Fraction::setNumerator(int n)
{
  if(n > 0) numerator = n;
  else numerator = 0;
}

void Fraction::setDenominator(int d)
{
  if(d > 0) denominator = d;
  else denominator = 0;
}

int Fraction::getNumerator()
{
  return numerator;
}

int Fraction::getDenominator()
{
  return denominator;
}

string Fraction::toString()
{
  return (to_string(numerator) + "/" + to_string(denominator));
}
