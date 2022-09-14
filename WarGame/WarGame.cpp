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
#include <sstream>
using namespace std;

//PLAYER CLASS
class Player
{
  public:
  int playerNumber;
  string playerName;
};

//FUNCTION DECLARATION
void playerInformation();
void deckMaker(string deck[]);
void deckRandomizer(string deck[]);
void deckDistributor(string deck[]);
void cardCount();
void cardRearrange(string player);
void mapMaker();
void cardCompare(int index);
vector <int> cardReader(string str);

//GLOBAL VARIABLES
//player objects
Player player1;
Player player2;
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
  mapMaker();
  playerInformation();
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
//function to personalize player data
void playerInformation()
{
  player1.playerNumber = 1;
  player2.playerNumber = 2;
  
  cout << "Player 1, enter your username: ";
  cin >> player1.playerName;

  cout << "Player 2, enter your username: ";
  cin >> player2.playerName;
}

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

  cout << player1.playerName << ": " << deckSizeP1 << " Cards" << endl;
  cout << player2.playerName << ": " << deckSizeP2 << " Cards" << endl;
  cout << endl;
}

//TODO - Make this function less lines by passing in deckP1 or deckP2 depending on the player you want to rearrange
//function to allow the player to rearrange their hand before playing
void cardRearrange(string player)
{
  if(player == "Player 1")
  {
    cout << player1.playerName << "'s Turn" << endl;
    cout << player1.playerName << "'s Hand: \n";
  }
  
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
  if(player == "Player 1")
  {
    cout << player1.playerName << ", please enter the order you would like to play your hand. Ex: 1 2 3 4"  << endl;
    cout << "Hand Order: ";
  }
  else
  {
    cout << player2.playerName << ", please enter the order you would like to play your hand. Ex: 1 2 3 4"  << endl;
    cout << "Hand Order: ";
  }
  

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
    cout << "\033[2J\033[0;0H";
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
    cout << "\033[2J\033[0;0H";
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
The cardCompare() function will call the cardReader() function to turn each card into an vector consisting of the number, as well as the class
[number, class]

The cardReader() will then hash the vectors to make them possible to read as an integer. These integers will be compared, such that the player owning the higher integer will be awarded a point.

In the exception that the numbers are the same for both Player 1 and Player 2's card, the program will repeat the above process with the class variable as a tiebreaker.
*/
void cardCompare(int index)
{
  string cardP1 = deckP1[index];
  string cardP2 = deckP2[index];
  //vectors to store int[number, class]
  vector <int> cardVectorP1(2);
  vector <int> cardVectorP2(2);

  //puttings the cards to compare in a [number, class] vector
  cardVectorP1 = cardReader(cardP1);
  cardVectorP2 = cardReader(cardP2);

  //printing the cards being played
  cout << "Round " << index + 1 << endl;
  cout << player1.playerName << " played a " << cardP1 << "!" << endl;
  cout << player2.playerName << " played a " << cardP2 << "!" << endl;

  //comparing the card numbers
  if(cardVectorP1.at(0) > cardVectorP2.at(0))
  {
    cout << player1.playerName << " has won the round!"<< endl;
  }
  else if(cardVectorP2.at(0) > cardVectorP1.at(0))
  {
    cout << player2.playerName << " has won the round!"<< endl;
  }
  else
  {
    if(cardVectorP1.at(1) > cardVectorP2.at(1))
    {
      cout << player1.playerName << " has won the round!"<< endl;
    }
    else if(cardVectorP2.at(1) > cardVectorP1.at(1))
    {
      cout << player2.playerName << " has won the round!"<< endl;
    }
  }
  cout << endl;
}

//function to split a string into a vector and return a vector
vector <int> cardReader(string str)
{
  //reading the string into a string vector
  vector <string> vectorStr(3);
  
  int vectorIndex = 0;
  for(int i = 0; i < str.length(); i++)
  {
    if(str[i] != ' ')
    {
      vectorStr[vectorIndex].push_back(str[i]);
    }
    else
    {
      vectorIndex++;
    }
  }

  //popping the second element("of") out as it s not needed
  int ofIndex = 1;
  vectorStr.erase(vectorStr.begin() + 1);

  //hashing the string vector into an int vector
  vector <int> vectorInt(2);
  //converting the number into an int
  vectorInt.at(0) = ((numberTranslator.at(vectorStr.at(0))));
  //converting the class into an int
  vectorInt.at(1) = ((classTranslator.at(vectorStr.at(1))));
  
  return vectorInt;
}
