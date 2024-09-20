/*
name : Connor Willett
class: CSC 203
HW#  : 5
QN#  : 1
*/

#include <iostream>
#include <cmath>
using namespace std;

void callDoc();
void checkolevel();
void checktemp();
void checkBpressore();
void checkBMI();
void checkECG();

int main(void)
{
  char chek;
  bool BMIcheck;
  while (true)
  { 
    // they check oxygen first in the ER
    checkolevel();

    // next they check temp
    checktemp();

    // next they check blood pressore
    checkBpressore();

    // next your bmi 
    // it will only check in the first itoration of the loop
    if(BMIcheck == false)
    {
      checkBMI();
      BMIcheck = true;
    }


    // then they hook you up to a ECG 
    checkECG();
    
    // will ask if you want to keep monitoring if no it will exit the program
    cout << "keep monitoring Y/N: ";
    cin >> chek;
    if(!(chek == 'Y' || chek == 'y'))
      exit(0);
  }
	return 0;
}

// a function that says call Doctor and will exit the program
void callDoc()
{
  cout << "call Doctor" << endl;
  exit(0);
}

// a function that askes and check if the oxygen level is normal
void checkolevel()
{
  int olevel;
  cout << "enter oxygen level: ";
  cin >> olevel;

  if (olevel < 80 )
    callDoc();
}

// function that check temp
void checktemp()
{
  float temp;
  cout << "enter temp: ";
  cin >> temp;
  if (temp > 99 || temp < 97 )
    callDoc();
}

// function that chekes blood pressore
void checkBpressore()
{
  float bpressore;
  cout << "enter blood pressore: ";
  cin >> bpressore;
  if (bpressore > 120 || bpressore < 80)
    callDoc();
}

// function that calculates bmi
void checkBMI()
{
  int weight, hight;
  float bmi;
  cout << "enter weight (lb): ";
  cin >> weight;
  cout << "enter hight (in): ";
  cin >> hight;
  
  bmi = (weight/pow(hight,2)) * 703;
  cout << "bmi " << bmi << endl;

  if (bmi < 18.5 || bmi > 24.9)
    callDoc();
}

// this function will ask for ECG readings 
// info frome
//https://www.cardiacdirect.com/how-to-read-an-ekg-strip-in-5-steps/#1631128231658-0bb2ae75-d343
void checkECG()
{
  float Pwavehight, Pwavelength, PRinterval, PRcalc, QRScomplex, QRcalc, rate;
  char rhythm;

  cout << "enter the hight of the P wave: ";
  cin >> Pwavehight;
  cout << "enter the length of the P wave (seconds): ";
  cin >> Pwavelength;
 
  if ( Pwavehight > 1 || Pwavehight < 0)
    callDoc();
  else if ( Pwavelength > 0.12 || Pwavelength <= 0.05 )
    callDoc(); 

  cout << "enter the distance between\nthe peek of the P wave and\nthe peek of the QRS complex\n: ";
  cin >> PRinterval;
  PRcalc = PRinterval * 0.04;
  if (PRcalc > 0.20 || PRcalc <= 0.11)
    callDoc();
 
  cout << "enter the size of the QRS complex: ";
  cin >> QRScomplex;
  QRcalc = QRScomplex / 0.04;

  if (QRcalc > 0.12 || QRcalc <= 0.05)
    callDoc();

  cout << "is the rhythm normal Y/N: "; 
  cin >> rhythm;

  if(!(rhythm == 'Y' || rhythm == 'y'))
    callDoc();

  cout << "enter heart rate: ";
  cin >> rate;

  if(rate > 100 || rate < 60)
    callDoc();

}
