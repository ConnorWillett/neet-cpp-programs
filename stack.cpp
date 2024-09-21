#include <iostream>
using namespace std;

#define n 100

class stack{
  int *arr;
  int top;

  public:
    stack()
    {
      arr = new int[n];
      top = -1;
    }

    void push(int x)
    {
      if(top == n-1)
      {
        cout << "stack overflow" << endl;
        return;
      }
      top++;
      arr[top] = x;
    }
    
    void pop()
    {
      if(top == -1)
      {
        cout << "no element to pop" << endl;
        return;
      }
      top--;
    }

    int Top()
    {
      if(top == -1)
      {
        cout << "no element in stack" << endl;
        return -1;
      }
      return arr[top];

    }
  
    bool empty()
    {
      return top = -1;
    }
    
    int ordered()
    {
      int temp = Top();
      int len = top;

      for(int i = 0; i < len; i++)
      {
        if(Top() > temp)
        {
          top = len;
          return 1;
        }
        top--;
      }
      top = len;
      return 0;
    }

    void sort()
    {
      int count = 0;
      int steps;
     	int len = top;
      int max = 0;
      int temp;
      for(int i = 1; i < 5; i++)
      {
        for(int j = 0; j < i; j++)
        {
          top = i;
          
          temp = Top();
     	    top--;
					if(Top() > temp)
					{
		 				max = Top();
						pop();
						push(temp);
 	          top = i-1;
						push(max);
            count++;
            cout << "swaps = " << count << endl;

					} 
          for(int k = i-1; k > 0; k--)
          {
            top = k;
            temp = Top();
       	    top--;
			  		if(Top() > temp)
			  		{
		 	  			max = Top();
				  		pop();
				  		push(temp);
 	            top = k-1;
					  	push(max);
              count++;
              cout << "swaps = " << count << endl;
				  	}
          steps++;
          cout << "steps = " << steps << endl;
          }
        }
      }
      top = len;
    }

};     

int main()
{
  stack st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(2);
  st.push(1);

  st.sort();



  cout << st.Top() << endl;
  st.pop();
  cout << st.Top() << endl;
  st.pop();
  cout << st.Top() << endl;
  st.pop();
  cout << st.Top() << endl;
  st.pop();
  cout << st.Top() << endl;
  st.pop();

  return 0;
}
