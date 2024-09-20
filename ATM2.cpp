/*
name : Connor Willett
class: CSC 203
HW#  : 13
QN#  : 1
*/


#include <iostream>
#include <iomanip>
using namespace std;

// a class that contains the user 
class User{
  private:
    int ID;
    float amount;
// datamembers

  public:
// constructor destructor
  User(int = 1234, float = 0);
  ~User();

// prototypes
  int checkID();
  void balance();
  void withdrawal(float);
  void deposit();
};

// constructor
User::User(int pin, float start)
{
  ID = pin;
  amount = start;
}

// destructer
User::~User()
{
}

// method to check ID
int User::checkID()
{
  int pin;
  cout << "enter pin: ";
  cin >> pin;
// this will give a 1 if its wrong and a 0 if its right
  if(pin == ID)
    return 0;
  else
    return 1;  

}

// method to check balance
void User::balance()
{
  cout << "your balence is " << fixed << setprecision(2) << amount << endl;
}

// method to take money out
void User::withdrawal(float withdrawal)
{
// if you try to take more then you have in the banke it will not let you
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

// method that deposits money
void User::deposit()
{
  float temp;
  cout << "enter amount: ";
  cin >> temp;
  amount += temp;
}

// class thats for controlling the program
class ui
{
  public:
    char input; 
    void setinput();
};

// this will ask for your input 
void ui::setinput()
{
  cout << "enter what you would like to do" << endl;
  cout << "(W) withdrawl, (B) balence, (D) deposit, (Q) quit" << endl;
  cout << ": ";
  cin >> input;
}

// main
int main(void)
{
  // create objects
  User me;
  ui myinput;

  // ask for the ID and if its wrong try again if its wrong 3 times you get locked out
  int trys = 0;
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

  // will loop through and depending on the input will call diforent functions
  myinput.setinput();
  while(myinput.input != 'q' && myinput.input != 'Q')
  {
    if(myinput.input == 'b' || myinput.input == 'B')
      me.balance();
    else if( myinput.input == 'w' || myinput.input == 'W')
    {
      float temp;
      cout << "withdrawal amount: ";
      cin >> temp; 
      me.withdrawal(temp);
    }
    else if( myinput.input == 'd' || myinput.input == 'D')
    {
      me.deposit();
    }
    else
    {
      cout << "\ninvalid command" << endl;
    }
    cout << endl;
    myinput.setinput();
  }

  return 0;
}




