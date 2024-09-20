/*
name : Connor Willett
class: CSC 203
HW#  : 14
QN#  : 1
*/


#include <iostream>
#include <iomanip>
using namespace std;

// one of the parent classes that check the ID 
class IDparent
{
  private:
    int ID;

  public:
  IDparent(int = 1234);
  ~IDparent();

  int checkID();
};

// constructor
IDparent::IDparent(int pin)
{
  ID = pin;
}

// destructor
IDparent::~IDparent()
{
}


// function for checking ID
int IDparent::checkID()
{
  int pin;
  cout << "enter pin: ";
  cin >> pin;
  if(pin == ID)
    return 0;
  else
    return 1;  
}

// another parent class for the creating and checking the balence
class balance
{
  public:
    float amount = 0;
    void checkbalance();
};

// function that checks the balence
void balance::checkbalance()
{
  cout << "your balence is " << fixed << setprecision(2) << amount << endl;
}

// another parent class that enables you to do deposits and withdrawals 
class transact:public balance
{
  public:
    void withdrawal(float);
    void deposit();

};

// withdral funtion
void transact::withdrawal(float withdrawal)
{
  if(withdrawal > amount)
	{
    cout << "not enough to withdrawal" << endl;
    return;   
  }
  else
  {
    amount -= withdrawal; 
    cout << "you withdrew " <<  fixed << setprecision(2) << withdrawal << " dolers" << endl;
  }
}

// funtion for deposits
void transact::deposit()
{
  float temp;
  cout << "enter amount: ";
  cin >> temp;
  amount += temp;
}

// class for interface
class ui
{
  public:
    char input; 
    void setinput();
};

// function for getting inputs
void ui::setinput()
{
  cout << "enter what you would like to do" << endl;
  cout << "(W) withdrawl, (B) balence, (D) deposit, (Q) quit" << endl;
  cout << ": ";
  cin >> input;
}


// chiled class that takes all the other classes
class User:public IDparent,public transact ,public ui
{
};

// main
int main(void)
{
  User me;
  int trys = 0;
  // loop to take pin if you guess wrong 3 times it will lock the sistem
  while(me.checkID() != 0)
  {
    cout << "wrong pin try again" << endl;
    trys++;
    if(trys >= 3)
    {
      cout << "sistem locked" << endl;
      exit(0);
    }
  }

  // loop that takes inputs and calls funtions based on the input
  me.setinput();
  while(me.input != 'q' && me.input != 'Q')
  {
    if(me.input == 'b' || me.input == 'B')
      me.checkbalance();
    else if( me.input == 'w' || me.input == 'W')
    {
      float temp;
      cout << "withdrawal amount: ";
      cin >> temp;
      me.withdrawal(temp);
    }
    else if( me.input == 'd' || me.input == 'D')
    {
      me.deposit();
    }
    else
    {
      cout << "\ninvalid command" << endl;
    }
    cout << endl;
    me.setinput();

  }

  return 0;
}




