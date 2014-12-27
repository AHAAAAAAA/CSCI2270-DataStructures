#include <cctype>          // Provides toupper
#include <iostream>        // Provides cout and cin
#include <cstdlib>         // Provides EXIT_SUCCESS
#include <string>
using namespace std;
unsigned int t=0; //for 2nd half
unsigned int y=0; //for 2nd half
unsigned int z=0; //to take us through
// PROTOTYPES for functions used by this test program:
void pattern(ostream& outs, unsigned int n, unsigned int i);

int main()
{
int i1=0;
  int i2;
  cout << "Enter an integer (a power of 2) for asteriks: ";
  cin >> i2;
  cout << "Enter an integer (a power of 3) for spaces: ";
  cin >>i1;
  cout<<"-------------";
  pattern(cout, i2, i1);
  cout<<"-------------";

  return (EXIT_SUCCESS);
}

// i is the offset
// n is the asterisks
void pattern(ostream& outs, unsigned int n, unsigned int i)
{
	
	if (z<5) {
		//first half
		if (z!=0){
			for (unsigned int k = 0; k < ((i%4)+z); k++) outs << " ";
			for (unsigned int k = 0; k < (1+n%3); k++) outs << "*";}
		outs <<endl;
		t=i;
		y=n;
		n++;
		i++;
		z++;
		pattern(outs,n,i);
		}
	else if (z>5&&z<=9) {
		//second half
		for (unsigned int k = 0; k < ((t%4)+(z-2)); k++) outs << " ";
		for (unsigned int k = 0; k < (1+y%3); k++) outs << "*";
			t++;
			y--;
			outs <<endl;
			i++;
			z++;
			pattern(outs,n,i);}
	else if (z==5){ 
		//centre
		for (unsigned int k = 0; k < i+3; k++) outs << "*";
		outs<<endl;
		i++;
		z++;
		pattern(outs,n,i);
		}
	
			
			
}

