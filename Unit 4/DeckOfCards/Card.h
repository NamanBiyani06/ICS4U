#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <time.h>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card 
{
  private:
    int face, suit;
    bool availableCard;

  public:
    // constructors
    Card();
    Card(int f, int s);
    Card(Card &c);
    // destructor
    ~Card();
    // overloaded equals operator
    void operator=(Card &c);
    // static arrays
    static const string faceTranslate[13];
    static const string suitTranslate[4];
    // overloaded stream insertion operator
    friend ostream & operator << (ostream &out, Card &c);
    // getters and setters
    int getFace();
    int getSuit();
    void setFace(int);
    void setSuit(int);
    bool isAvailable();
    void disable();
};


// static members 
const string Card::faceTranslate[13] = {
  "Two",
  "Three",
  "Four",
  "Five",
  "Six",
  "Seven",
  "Eight",
  "Nine",
  "Ten",
  "Jack",
  "Queen",
  "King",
  "Ace"
};

const string Card::suitTranslate[4] = {
  "Clubs",
  "Diamonds",
  "Hearts",
  "Spades"
};

Card::Card()
{
  face = 0;
  suit = 0;
  availableCard = true;
}

Card::Card(int f, int s)
{
  face = f;
  suit = s;
}

Card::Card(Card &c)
{
  face = c.getFace();
  suit = c.getSuit();
}

Card::~Card()
{
  // there is no memory needed to be deleted
}

void Card::operator=(Card &c)
{
  c.setFace(face);
  c.setSuit(suit);
}

ostream & operator << (ostream &out, Card &c)
{
  out << Card::faceTranslate[c.getFace()] << " of " << Card::suitTranslate[c.getSuit()];
  return out;
}

int Card::getFace()
{
  return face;
}

int Card::getSuit()
{
  return suit;
}

void Card::setFace(int face)
{
  this->face = face;
}

void Card::setSuit(int suit)
{
  this->suit = suit;
}

#endif