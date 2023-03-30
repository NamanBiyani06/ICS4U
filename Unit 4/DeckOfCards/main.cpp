#include "Card.h"
#include "DeckOfCards.h"

int main()
{
  Card * handOne[52];
  Card * handTwo[26];

  DeckOfCards deck = DeckOfCards();

  deck.shuffle();

  for(int i = 0; (i < 52) & deck.moreCards(); i++)
  {
    handOne[i] = deck.dealCard();
  }

  for(int i = 0; i < 52; i++)
  {
    cout << handOne[i] << endl;
  }
}