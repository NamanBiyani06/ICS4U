//ICS4U
//War Game Assignment
//Naman Biyani
//July 26, 2022

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>
#include <map>
using namespace std;

//FUNCTION DECLARATION
void deckMaker(string deck[]);
void deckRandomizer(string deck[]);
void deckDistributor(string deck[]);
void cardCount();
void cardRearrange(string player);
void mapMaker();
void cardCompare(int index);
vector <string> stringToVector(string str, vector <string> &vec);
vector <int> cardHash(vector <string> & vec);

//GLOBAL VARIABLES
//vectors to act as player decks
//vectors are a contiguous and dynamic/resizable structure for simulating a hand of cards
vector <string> deckP1;
vector <string> deckP2;

//vectors to act as each player's discard pile
vector <string> discardP1;
vector <string> discardP2;

//arrays to automate deck creation as well as help compare cards
const string cardNumbers[13] = {"Two", "Three", "Four", "Five", "Six", "Seven",
"Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
const string cardClasses[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};

/*
global hashmaps which will act as translation guides when converting strings to integers. 
this will be used to make comparing two card values more efficient (maps are constant time). 
the maps will be initialized in a helper function. 
*/
map <string, int> numberTranslator;
map <string, int> classTranslator;


//MAIN
int main()
{
  //standard deck of cards
  string deck[52];
  
  //clears the terminal
  cout << "\033[2J\033[0;0H";

  //function calls to init game
  deckMaker(deck);
  deckRandomizer(deck);
  deckDistributor(deck);

  //function calls to begin game
  cardCount();

  //function that allows the user to rearrange their cards
  cardRearrange("Player 1");
  cardRearrange("Player 2");

  for(int i = 0; i < 4; i++)
  {
    cardCompare(i);   
  }
  
  return 0;
}

//FUNCTIONS
//function to make a deck of 52 cards
void deckMaker(string deck[])
{
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
void deckRandomizer(string deck[])
{
  //current time is passed as seed to srand() so seed is never repeated
  srand(time(0));
  //finding number of bytes in an array/number of bytes in data type
  int len = 52;
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
void deckDistributor(string deck[])
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

//function to allow the player to rearrange their hand before playing
void cardRearrange(string player)
{
  cout << player << "'s Turn" << endl;
  cout << player << "'s Hand: \n";

  //TODO - Make this function less lines by combining the two if statements
  //outputing the default starting hand
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

  //getting hand order input from user
  cout << player << ", please enter the order you would like to play your hand. Ex: 1 2 3 4"  << endl;
  cout << "Hand Order: ";

  int handOrder[4];
  for(int i = 0; i < 4; i++)
  {
    cin >> handOrder[i];
    handOrder[i]--;
  }

  //changing player hand to their order preference
  if (player == "Player 1")
  {
    /*
    creating a copy of the players hand to 
    aid in rearranging.
    This deck will be unchanged throughout 
    the rearranging.
    */
    string handConst[4];
    for(int i = 0; i < 4; i++)
    {
      handConst[i] = deckP1[i];
    }
    
    for (int i = 0; i < 4; i++)
    {
      deckP1[i] = handConst[handOrder[i]];
    }

    //clearing the screen for the next player
    //NOTE - Uncomment for submission
    //cout << "\033[2J\033[0;0H";
  }
  
  if (player == "Player 2")
  {
    /*
    creating a copy of the players hand to aid in rearranging.
    This deck will be unchanged throughout the rearranging.
    */
    string handConst[4];
    for(int i = 0; i < 4; i++)
    {
      handConst[i] = deckP2[i];
    }
    
    for (int i = 0; i < 4; i++)
    {
      deckP2[i] = handConst[handOrder[i]];
    }

    //clearing the screen for the next player
    //NOTE - Uncomment for submission
    //cout << "\033[2J\033[0;0H";
  }
}

//function to initialize maps to use for string to value translation
void mapMaker()
{
  //{("Two", 2), ("Three", 3), ...}
  for(int i = 0; i < 13; i++)
  {
    numberTranslator.insert(pair <string, int> (cardNumbers[i], (i + 2)));
  }
  //{("Spades", 1), ("Hearts", 2), ...}
  for(int i = 0; i < 4; i++)
  {
    classTranslator.insert(pair <string, int> (cardClasses[i], (i + 1)));
  }
}

//function to take a index parameter and compare the players hands
/*
The cardCompare() function will get the split each card into an vector consisting of the number, as well as the class
[number, class]

The function will then hash the vectors to make them possible to read as an integer. These integers will be compared, such that the player owning the higher integer will be awarded a point.

In the exception that the numbers are the same for both Player 1 and Player 2's card, the program will repeat the above process with the class variable as a tiebreaker.
*/
void cardCompare(int index)
{
  string cardP1 = deckP1[index];
  string cardP2 = deckP2[index];
  vector <string> cardVectorP1(3);
  vector <string> cardVectorP2(3);

  //puttings the cards to compare in a [number, class] vector
  cardVectorP1 = stringToVector(cardP1, cardVectorP1);
  cardVectorP2 = stringToVector(cardP2, cardVectorP2);

  
}

//function to split a string into a vector and return a vector
vector <string> stringToVector(string str, vector <string> &vec)
{
  vector <string> vector;
  for(int i = 0; i < vec.size(); i++)
  {
    vector.push_back(vec.at(i));
  }

  int vectorIndex = 0;
  for(int i = 0; i < str.length(); i++)
  {
    if(str[i] != ' ')
    {
      vector[vectorIndex].push_back(str[i]);
    }
    else
    {
      vectorIndex++;
    }
  }

  //popping the second element("of") out as it s not needed
  int ofIndex = 1;
  vector.erase(vector.begin() + 1);
  return vector;
}

//function to hash a vector
vector <int> cardHash(vector <string> &vec)
{
  vector <string> vector;
  for(int i = 0; i < vec.size(); i++)
  {
    vector.push_back(vec.at(i));
  }
  
}
