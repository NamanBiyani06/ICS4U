//ICS4U
//War Game Assignment
//Naman Biyani
//July 26, 2022

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;

//FUNCTION DECLARATION
void deckMaker();
void deckRandomizer();
void deckDistributor();
void cardCount();
void cardRearrange(string player);
string removeSpace(string str);

//GLOBAL VARIABLES
//standard deck of cards
string deck[52];
//vectors to act as player decks
//vectors are a contiguous and dynamic/resizable structure for simulating a hand of cards
vector <string> deckP1;
vector <string> deckP2;
//vectors to act as each player's discard pile
vector <string> discardP1;
vector <string> discardP2;

//MAIN
int main()
{
  //clears the terminal
  system("Clear");

  //function calls to init game
  deckMaker();
  deckRandomizer();
  deckDistributor();

  //function calls to begin game
  cardCount();

  cardRearrange("Player 1");
  cardRearrange("Player 2");

  return 0;
}

//FUNCTIONS
//function to make a deck of 52 cards
void deckMaker()
{
  //MOVE ACE TO TOP, ACE == 14
  string cardNumbers[13] = {"Ace", "Two", "Three", "Four", "Five",
  "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  string cardClasses[4] = {"♥️Hearts♥️", "♦️Diamonds♦️", "♣️Clubs♣️", "♠️Spades♠️"};

  for(int i = 0; i<52; i++)
  {
    //repeating through cardNumbers
    int cardNumber = i;
    while(cardNumber >= 13)
    {
      cardNumber -= 13;
    }
    //repeating through cardClasses
    int cardClass = i;
    while(cardClass >= 4)
    {
      cardClass -= 4;
    }
    //concatinating values and adding to deck array
    deck[i] = cardNumbers[cardNumber] + " of " + cardClasses[cardClass];
  }
}

//function to randomize a deck of 52 cards
void deckRandomizer()
{
  //current time is passed as seed to srand() so seed is never repeated
  srand(time(0));
  //finding number of bytes in an array/number of bytes in data type
  int len = sizeof(deck)/sizeof(string);
  //randomizing deck[]
  for(int i = 0; i < len; i++)
  {
    int randomIndex = rand() % len;
    string temp = deck[i];
    deck[i] = deck[randomIndex];
    deck[randomIndex] = temp;
  }
}

//function to distribute cards evenly between two players
void deckDistributor()
{
  for (int i = 0; i < 52; i++)
  {
    //distributing the deck
    //if index is even -> card given to P1
    //else -> card given to P2
    if(i % 2 == 0)
    {
      deckP1.push_back(deck[i]);
    }
    else
    {
      deckP2.push_back(deck[i]);
    }
  }
}

//function to count the cards in each player's hand
void cardCount()
{
  int deckSizeP1 = deckP1.size();
  int deckSizeP2 = deckP2.size();

  cout << "Player 1: " << deckSizeP1 << " Cards" << endl;
  cout << "Player 2: " << deckSizeP2 << " Cards" << endl;
  cout << endl;
}

void cardRearrange(string player)
{
  cout << player << "'s Turn" << endl;
  cout << player << "'s Hand: \n";
  for (int i = 0; i < 4; i++)
  {
    if (player == "Player 1")
    {
      cout << (i+1) << ". " << deckP1.at(i) << endl;
    }
    else
    {
      cout << (i+1) << ". " << deckP2.at(i) << endl;
    }
  }
  cout << endl;
  cout << player << ", please enter the order you would like to play your hand. Ex: 1 2 3 4"  << endl;
  cout << "Hand Order: ";
  string handOrderInput;
  getline(cin, handOrderInput);
  string handOrder = removeSpace(handOrderInput);
  cout << handOrder << endl;
  if (player == "Player 1")
  {
    for (int i = 0; i < 4; i++)
    {
      //subtracting 48 due to it being the ASCII value of 0
      //subtracting 1 vectors use 0-based numbering
      cout << deckP1.at((int)handOrder[i] - 48 - 1) << endl;
      cout << deckP1.at(i) << endl;
      string temp = deckP1.at((int)handOrder[i] - 48 - 1);
      deckP1.at((int)handOrder[i]- 48 - 1) = deckP1.at(i);
      deckP1.at(i) = temp;
    }
  }
  // cout << player << "'s Hand: \n";
  // for (int i = 0; i < 4; i++)
  // {
  //   if (player == "Player 1")
  //   {
  //     cout << (i+1) << ". " << deckP1.at(i) << endl;
  //   }
  //   else
  //   {
  //     cout << (i+1) << ". " << deckP2.at(i) << endl;
  //   }
  // }
  // cout << endl;
}

//function to take a string and remove spaces
string removeSpace(string str)
{
  //iterates through string not appending spaces
  string noSpaces = "";
  for (int i = 0; i < str.length(); i++)
  {
    if(str[i] != ' ')
    {
      noSpaces += str[i];
    }
  }
  return noSpaces;
}


