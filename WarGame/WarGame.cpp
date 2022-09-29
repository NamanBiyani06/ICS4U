//ICS4U
//War Game Assignment
//Naman Biyani
//July 26, 2022

/*
INSTRUCTIONS

Welcome to War! War is a simple card game where player's each draw cards, with the value of the cards dictatinf the winner. Every turn, each player will draw four cards and choose the order to play them in. After the rearrangement process has been completed by both players, the cards will be played in the order you've chosen, and the winner of the round is dictated by the value of the cards.

Card value is first determined by the number on the card, with Two being the lowest and Ace being the highest. In the case that the card numbers are the same, the game ranks the cards based on their class.

The class system ranks classes as the following:
1. Clubs
2. Diamonds
3. Hearts
4. Spades

Enjoy the Game!
*/



#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <map>
#include <sstream>
#include <limits>
#include <chrono>
#include <thread>

using namespace std;

//PLAYER CLASS
class Player
{
  public:
  int playerNumber;
  string playerName;
};

//FUNCTION DECLARATION
void instructions();
void playerInformation();
void deckMaker(string deck[]);
void deckRandomizer(string deck[]);
void deckDistributor(string deck[]);
string cardCount();
void cardRearrange(Player player, vector <string> &deck);
void pressEnterToContinue();
void mapMaker();
void cardCompare(int index);
vector <int> cardReader(string str);
void discardInsert(vector <string> &playerDeck, vector <string> &playerDiscard, Player player);
void eraseFromDeck(int n);
void clear();

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

//array to make for loop
const char letters[4] = {'a', 'b', 'c', 'd'};

/*
global hashmaps which will act as translation guides when converting strings to integers. 
this will be used to make comparing two card values more efficient (maps are constant time). 
the maps will be initialized in a helper function. 
*/
map <string, int> numberTranslator;
map <string, int> classTranslator;

//global gameplay loop bool
bool gameplayLoop = true;

//MAIN
int main()
{
  //current time is passed as seed to srand() so seed is never repeated
  srand(time(0));

  //standard deck of cards
  string deck[52];
  
  //clears the terminal
  clear();

  //function calls to init game
  instructions();
  mapMaker();
  playerInformation();
  deckMaker(deck);
  deckRandomizer(deck);
  deckDistributor(deck);

  //function calls to begin game
  cardCount();

  while(gameplayLoop)
  {
    //function that allows the user to rearrange their cards
    cardRearrange(player1, deckP1);    
    cardRearrange(player2, deckP2);

    for(int i = 0; i < 4; i++)
    {
      cardCompare(i);
    }
    eraseFromDeck(4);

    discardInsert(deckP1, discardP1, player1);
    discardInsert(deckP2, discardP2, player2);

    string game = cardCount();
    //in most cases, goto statements are messy but using goto to break out of multiple loops is a strong usage
    if(game == "GameOver") goto GameOver;

    pressEnterToContinue();
  }

  GameOver: return 0;
}

void instructions()
{
  string instructions1 = "--INSTRUCTIONS--\n\n";
  string instructions2 = "Welcome to War! War is a simple card game where player's each draw cards, with the value of the cards dictatinf the winner. Every turn, each player will draw four cards and choose the order to play them in. After the rearrangement process has been completed by both players, the cards will be played in the order you've chosen, and the winner of the round is dictated by the value of the cards.\n\n";
  string instructions3 = "Card value is first determined by the number on the card, with Two being the lowest and Ace being the highest. In the case that the card numbers are the same, the game ranks the cards based on their class.\n\n";
  string instructions4 = "The class system ranks classes as the following:\n1. Clubs\n2. Diamonds\n3. Hearts\n4. Spades\n\nEnjoy the Game!";

  cout << instructions1;



  for (int i = 0; i < instructions2.size(); i++)
  {cout << instructions2[i];
  //usleep(5000);
  //std::this_thread::sleep_for(std::chrono::milliseconds(30));
  }

  for (int i = 0; i < instructions3.size(); i++)
  {cout << instructions3[i];
  //usleep(50000);
  //std::this_thread::sleep_for(std::chrono::milliseconds(30));
  }

  for (int i = 0; i < instructions3.size(); i++)
  {cout << instructions4[i];
  //usleep(50000);
  // std::this_thread::sleep_for(std::chrono::milliseconds(30));
  }
  cout << endl;

  cout << "Press Enter to Continue\n";
  cin.ignore();
  clear();
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
string cardCount()
{
  int cardCountP1 = deckP1.size() + discardP1.size();
  int cardCountP2 = deckP2.size() + discardP2.size();

  cout << player1.playerName << ": \n" ;
  cout << "Hand: " << deckP1.size() << endl;
  cout << "Discard: " << discardP1.size() << endl;

  cout << player2.playerName << ": \n";
  cout << "Hand: " << deckP2.size() << endl;
  cout << "Discard: " << discardP2.size() << endl;

  //checking if a player has less cards than the four card threshold
  if(cardCountP1 < 4)
  {
    gameplayLoop = false;
    cout << endl;
    cout << player1.playerName << " has ran out of cards!\n\n";
    cout << player2.playerName << " won the game!";
    return "GameOver";
  }
  else if(cardCountP2 < 4)
  {
    gameplayLoop = false;
    cout << endl;
    cout << player2.playerName << " has ran out of cards!\n\n";
    cout << player1.playerName << " won the game!";
    return "GameOver";
  }



  cout << endl;
  return "ContinueGame";
}

//prompting the user to press enter to continue the game
void pressEnterToContinue()
{
  cout << "Press Enter to Continue\n";
  cin.ignore();
  cin.ignore();
  clear();
}

//TODO - Make this function less lines by passing in deckP1 or deckP2 depending on the player you want to rearrange
//function to allow the player to rearrange their hand before playing
void cardRearrange(Player player, vector <string> &deck)
{
  cout << player.playerName << "'s Turn" << endl;
  cout << player.playerName << "'s Hand: \n";
  
  //outputing the default starting hand
  for (int i = 0; i < 4; i++)
  {
    cout << letters[i] << ". " << deck.at(i) << endl;
  }
  cout << endl;

  //getting hand order input from user
  cout << "Enter the hand order\nFor Example \"a b c d\""  << endl;
  cout << "Hand Order: ";
  
  char handOrderChar[4];
  int handOrder[4];
  for(int i = 0; i < 4; i++)
  {
    cin >> handOrderChar[i];

    if(handOrderChar[i] == 'a') handOrder[i] = 0;
    else if(handOrderChar[i] == 'b') handOrder[i] = 1;
    else if(handOrderChar[i] == 'c') handOrder[i] = 2;
    else if(handOrderChar[i] == 'd') handOrder[i] = 3;
  }

  //changing player hand to their order preference
  /*
  creating a copy of the players hand to aid in rearranging. This deck will be unchanged throughout the rearranging.
  */
  string handConst[4];
  for(int i = 0; i < 4; i++)
  {
    handConst[i] = deck[i];
  }
  
  for (int i = 0; i < 4; i++)
  {
    deck[i] = handConst[handOrder[i]];
  }
  
  //clearing the screen for the next player
  clear();
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
  int roundWinner;
  string cardP1 = deckP1.at(index);
  string cardP2 = deckP2.at(index);

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

  //loading animation to build suspense
  for (int i = 0; i < 3; i++)
  {
    usleep(500000);
    cout << "." << flush;
  }
  usleep(500000);
  cout << "\b\b\b" << flush;
  
  //comparing the card numbers
  if(cardVectorP1.at(0) > cardVectorP2.at(0))
  {
    cout << player1.playerName << " has won the round!"<< endl;
    roundWinner = 1;
  }
  else if(cardVectorP2.at(0) > cardVectorP1.at(0))
  {
    cout << player2.playerName << " has won the round!"<< endl;
    roundWinner = 2;
  }
  else
  {
    if(cardVectorP1.at(1) > cardVectorP2.at(1))
    {
      cout << player1.playerName << " has won the round!"<< endl;
      roundWinner = 1;
    }
    else if(cardVectorP2.at(1) > cardVectorP1.at(1))
    {
      cout << player2.playerName << " has won the round!"<< endl;
      roundWinner = 2;
    }
  }

  //adding the played cards to the winners discard pile
  switch(roundWinner)
  {
    case 1:
    discardP1.push_back(cardP1);
    discardP1.push_back(cardP2);
    //cout << player1.playerName << " recieved 2 cards" << endl;
    break;

    case 2:
    discardP2.push_back(cardP1);
    discardP2.push_back(cardP2);
    //cout << player2.playerName << " recieved 2 cards" << endl;
    break;
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

//function to randomize the players discard pile and insert it into the players main deck if their main deck < 4
void discardInsert(vector <string> &playerDeck, vector <string> &playerDiscard, Player player)
{
  if(playerDeck.size() < 4)
  {
    cout << player.playerName << "\'s discard pile has been reshuffled and redistributed!" << endl;
    int len = playerDiscard.size();
    //randomizing the discard deck
    for(int i = 0; i < len; i++)
    {
      int randomIndex = rand() % len;
      string temp = playerDiscard[i];
      playerDiscard[i] = playerDiscard[randomIndex];
      playerDiscard[randomIndex] = temp;
    }

    //inserting the discard deck at the back of the player hand
    for (int i = 0; i < len; i++)
    {
      playerDeck.push_back(playerDiscard.at(i));
    }

    playerDiscard.clear();
  }
}

//function to remove the played cards from the users deck
void eraseFromDeck(int n)
{
  deckP1.erase(next(deckP1.begin(), 0), next(deckP1.begin(), 4));
  deckP2.erase(next(deckP2.begin(), 0), next(deckP2.begin(), 4));
}

void clear() {cout << "\033[2J\033[0;0H";}
