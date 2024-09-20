#include <iostream>
using namespace std;

class myclass
{
  float amount = 11.5;  
	public:
    float annual(float,float,float);
    float annual(float,float);
    float annual(float);

};


float myclass::annual(float ir1, float ir2, float ir3)
{
  float irf = ir1 + ir2 + ir3;
  return (irf * amount)/100;
}

float myclass::annual(float ir1, float ir2)
{
  float irf = ir1 + ir2;
  return (irf * amount)/100;
}

float myclass::annual(float ir1)
{
  float irf = ir1;
  return (irf * amount)/100;
}


int main()
{
  float ir1 = 1.1; 
  float ir2 = 2.2; 
  float ir3 = 3.3; 


  myclass myobj;

  cout << "A " << myobj.annual(ir1) << endl;
  cout << "B " << myobj.annual(ir1,ir3) << endl;
  cout << "C " << myobj.annual(ir1,ir2,ir3) << endl;

  return 0;
}

