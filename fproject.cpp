/*
name : Connor Willett
class: CSC 203
HW#  : Final
date : 12_16_2023
This program is desinged to help people calculate prbability of drawing cards 
based on the gamestate. This Program is desined for Magic the Gathering
Which is a trading card game but this program can be used for other games aswell.
NOTE some terms used in the program are Magic specific.
Library = deck
Graveyard = discard pile
Mill = put cards from your Deck to graveyard
Regrown = put cards from your graveyard to your hand
*/



#include <iostream>
using namespace std;

// this is a class that makes the blueprint for the deck
class deck
{
  // the private data members
  private:
    int maxSize;
    int curentSize;
  public:
    // publick name
    string deckName;

    // constructor and destructor starts with a stander size for a magic the gathering deck
    deck(int = 60,string = "Sample deck");
    ~deck();

    // method prototypes
    int getDeckSize();
    int subCardsD(int);
    void addCardsD(int);
};

// constructor 
deck::deck(int size, string name)
{
  cout << "Deck created" << endl;
  maxSize = size;
  curentSize = maxSize; 
  deckName = name;
}

// destructor
deck::~deck(){}


// method that will get size of deck
int deck::getDeckSize()
{
  return curentSize;
}

// method that will subtract cards from your deck
int deck::subCardsD(int sub)
{
  if(sub > curentSize)
  {
    cout << "not Enough cards in deck" << endl;
    return 1;
  }
  curentSize -= sub;
  return 0;
}
// method that will add cards to your deck
void deck::addCardsD(int add)
{
  curentSize += add;
}

// this is a class that makes the blueprint for your hand 
class hand
{
  private:
    int handSize;
  public:
    
    hand(int=0);
    ~hand(); 
    int getHandSize();
    void addCardsH(int);
    int subCardsH(int);

};

// constructor
hand::hand(int num)
{
  handSize = num;
}
// destructor
hand::~hand(){}


// method that will get the number of cards in hand
int hand::getHandSize()
{
  return handSize;
}

// method that adds cards to your hand
void hand::addCardsH(int add)
{
  handSize += add;
}
// method that subtracts cards from your hand
int hand::subCardsH(int sub)
{
  if(sub > handSize)
  {
    cout << "not Enough cards in hand" << endl;
    return 1;
  }
  handSize -= sub;
  return 0;
}

// this is a class that makes the blueprint for your graveyard 
class discard
{
  private: 
    int discardSize = 0;
  public:
    int getdiscardSize();
    void addCardsG(int);
    int subCardsG(int);

};
// gets the size of your discard pile
int discard::getdiscardSize()
{
  return discardSize;
}
// labeled as G cuz deck is D and some games like MTG use the term graveyard
// method that adds cards to your graveyard
void discard::addCardsG(int add)
{
  discardSize += add;
}
// method that subtract cards from your graveyard
int discard::subCardsG(int sub)
{
  if(sub > discardSize)
  {
    cout << "not Enough cards in discard" << endl;
    return 1;
  }
  discardSize -= sub;
  return 0;
}

// a class that combinds all the other classes into one class we can work with
class player: public deck, public hand, public discard
{
  public:
    int inplay = 0;
    void draw();
    void draw(int);
    void discard(int);
    void mill(int);
    void shufflein(int);
    void regrow(int);
    void putback(int);
    void play(int);
    void die(int);

    float prob(int,float);
};

// polymorphism method to draw a card
void player::draw()
{
  if(subCardsD(1) == 0)
  {
    addCardsH(1);
  }
}
// drawing cards by adding cards to your hand and subtracting cards from your deck
void player::draw(int num)
{
  if(subCardsD(num) == 0)
  {
    addCardsH(num);
  }
}
// discarding cards by adding cards to your discard and subtracting cards from your hand
void player::discard(int num)
{
  if(subCardsH(num) == 0)
  {
    addCardsG(num);
  }
}
// milling cards by adding cards to your discard and subtracting cards from your deck
void player::mill(int num)
{
  if(subCardsD(num) == 0)
  {
    addCardsG(num);
  }
}
// shuffleing cards from your discard back into your deck
void player::shufflein(int num)
{
  if(subCardsG(num) == 0)
  {
    addCardsD(num);
  }
}
// puting cards from your discard back into your hand
void player::regrow(int num)
{
  if(subCardsG(num) == 0)
  {
    addCardsH(num);
  }
}
// puting cards from your hand back into your deck
void player::putback(int num)
{
  if(subCardsH(num) == 0)
  {
    addCardsD(num);
  }
}
// moving cards to play from your hand
void player::play(int num)
{
  if(subCardsH(num) == 0);
  {
    inplay += num;
  }
}
// cards dying and going to the graveyard
void player::die(int num)
{
  if(num > inplay)
  {
    cout << "not enough cards in play" << endl;
  }
  else
  {
    addCardsG(num);
    inplay -= num;
  }
}

// find the probability of drawing sertian cards
float player::prob(int trys,float desired)
{
  float prob = 1;
  if(trys == 1)
  {
    prob = desired / getDeckSize();
    return prob * 100;
  }
  else if(trys > 1)
  {
    int temp = getDeckSize();
    for(int i = 0; i < trys; i++)
    {
      prob *= (temp - desired)/temp;
      temp--;
      if(temp == 0)
        break;
    }
    return (1 - prob) * 100;
  }
  else
  {
    cout << "must be a positive number" << endl;
    return 0;
  }
}



// the main function
int main()
{
// make an object
  player me;

// introduction and instructions
  cout << "Welcome to You trusty MTG card counter\nName your deck : ";
  cin >> me.deckName; 
  
  cout << "This program will help you keep track of things in game" << endl;
  cout << "Also will calculate probability" << endl;
  cout << "Q = quit, c = commands" << endl;
  cout << endl;

  char input; 

// a loop that asks for inputs and calls funtions based on the inputs to operate the program
  while(input != 'q' && input != 'Q')
  {
    int num;
    cout << "enter command :";
    cin >> input;

    if(input == 'C' || input == 'c')
    {
      cout << endl;
      cout << "0 = draw 1 card" << endl;
      cout << "1 = draw n cards" << endl;
      cout << "2 = discard" << endl;
      cout << "3 = put cards from deck into you graveyard" << endl;
      cout << "4 = shuffle in cards from the graveyard" << endl;
      cout << "5 = regrow card from the graceyard" << endl;
      cout << "6 = shuffle cards from your hand to your deck" << endl;
      cout << "7 = play a card" << endl;
      cout << "8 = put a card from the bord to your graveyard" << endl;
      cout << "P = find the probability of drawing a certain card" << endl;
      cout << "D = see the number of cards in your deck" << endl;
      cout << "H = see the number of cards in your hand" << endl;
      cout << "G = see the number of cards in your graveyard" << endl;
      cout << "B = see the number of cards in the battlefield / in play" << endl;
    }
    else if(input == '0')
    {
      cout << "draw 1 card" << endl;
      me.draw();
    }
    else if(input == '1')
    {
      cout << "how many cards : ";
      cin >> num;
      me.draw(num);
    }
    else if(input == '2')
    {
      cout << "how many cards : ";
      cin >> num;
      me.mill(num);
    }
    else if(input == '3')
    {
      cout << "how many cards : ";
      cin >> num;
      me.discard(num);
    }
    else if(input == '4')
    { 
      cout << "how many cards : ";
      cin >> num;
      me.shufflein(num);
    }
    else if(input == '5')
    {
      cout << "how many cards : ";
      cin >> num;
      me.regrow(num);
    }
    else if(input == '6')
    {
      cout << "how many cards : ";
      cin >> num;
      me.putback(num);
    }
    else if(input == '7')
    {
      cout << "how many cards : ";
      cin >> num;
      me.play(num);
    }
    else if(input == '8')
    {
      cout << "how many cards : ";
      cin >> num;
      me.die(num);
    }
    else if(input == 'P' || input == 'p')
    {
      int trys;
      float desired;
      cout << "how many draws : "; 
      cin >> trys;
      cout << "how many copies of the card are left in your deck : ";
      cin >> desired;
      cout << "you have a " << me.prob(trys,desired) << "\% chance of drawing the desired card" << endl;
    }
    else if(input == 'D' || input == 'd')
    {
      cout << me.getDeckSize() << " cards left in " << me.deckName << endl;
    }
    else if(input == 'H' || input == 'h')
    {
      cout << me.getHandSize() << " cards in hand" << endl;
    }
    else if(input == 'G' || input == 'g')
    {
      cout << me.getdiscardSize() << " cards in your graveyard" << endl;
    }
    else if(input == 'B' || input == 'b')
    {
      cout << me.inplay << " cards on the battlefield / in play" << endl;
    }
    else if(input == 'Q' || input == 'q')
    {
      break;
    }
    else
    {
      cout << "invalid command try again" << endl;
    }
    cout << endl; 
  }


  return 0;
}


