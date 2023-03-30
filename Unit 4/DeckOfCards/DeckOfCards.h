#include "Card.h"

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

class DeckOfCards 
{
  private:
    const static int SIZE_OF_DECK = 52;

  public:
    Card * cards[SIZE_OF_DECK];
    int currentCard;
    // constructors
    DeckOfCards();
    // destructor
    ~DeckOfCards();
    //shuffle
    void shuffle();
    void swap(Card &a, Card &b);
    //dealCard
    Card * dealCard();
    //moreCards
    bool moreCards();
};

DeckOfCards::DeckOfCards()
{
  currentCard = 0;
  int cardIndex = 0;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 13; j++)
    {
      DeckOfCards::cards[cardIndex] = new Card(i ,j);
      cardIndex++;
    }
  }
}

DeckOfCards::~DeckOfCards()
{
  delete [] * cards;
}

void DeckOfCards::swap(Card &a, Card &b)
{
  Card c = a; a = b; b = c;
}

void DeckOfCards::shuffle()
{
  // implementation of the Fisher-Yates shuffle
  srand(time(0));

  for(int i = SIZE_OF_DECK - 1; i > 0; i--)
  {
    int j = rand() % (i + 1);

    DeckOfCards::swap(* cards[i], * cards[j]);
  }
}

Card * DeckOfCards::dealCard()
{
  Card * returnCard = * &cards[currentCard];
  cards[currentCard]->disable();
  currentCard++;
  return returnCard;
}

bool DeckOfCards::moreCards()
{
  if(currentCard <= 51) return true;
  else return false;
}

#endif