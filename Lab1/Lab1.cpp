// Ahmed AlMutawa

#include <string>
#include <iostream>
using namespace std;
string thething;
int shift;

int main()
{
	//UI
	cout<<"Word to be ciphered? (no symbols please)"<<endl;
	getline (cin,thething);
	cout<<"Shift by?"<<endl;
	cin>>shift;

	//Ignoring case sensitivity
	for(int x=0;x<thething.length();x++)
		thething[x]=tolower(thething[x]);

	//Shifting and ad-hoc cases
	for (int i=0; i<thething.size();i++)
	{
		if (thething[i]<122)
		{	
			thething[i]=thething[i]+shift;
			if (thething[i]>122)
				thething[i]=thething[i]-26;
		}
		else
		thething[i]=(thething[i])%122+(96+shift);
	}

	//Display
	cout <<"Your cipher is "<< thething <<endl;
	system("pause");

	return 0;
}
