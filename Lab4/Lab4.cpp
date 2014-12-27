#include "dynamic_size_array_sorted.h"

using namespace std;


void init(int_array& arr)
{
	arr.capacity=arr.DEFAULT_CAPACITY;
	arr.data= new int[arr.DEFAULT_CAPACITY];
	arr.count=0;
}

void clear(int_array& arr)
{
destr(arr);
init(arr);}

void destr(int_array& arr)
{
	delete [] arr.data;
	arr.count=0;
}

void print(const int_array& arr)
{
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
	cout << endl;
}

bool contains(const int_array& arr, const int& target)
{
	for (unsigned int i=0; i<arr.count;i++){
		if (arr.data[i]==target)
			return true;
		}
	return false;
}

void resize(int_array& arr)
{
	int* antiarr;
	arr.capacity*=2;
	antiarr=new int[arr.capacity];

	for (unsigned int i=0;i<arr.capacity;i++)
		antiarr[i]=arr.data[i];
	delete [] arr.data;
	arr.data=antiarr;
}

void add(int_array& arr, const int& payload)
{
	if (arr.count==arr.capacity)
		resize (arr);
	arr.data[arr.count]=payload;
	++arr.count;
	
	//sorts on the go
	
	for (unsigned int i=0;i<arr.count;i++)
	{
		for (unsigned int j=0;j<arr.count;j++)
		{
			if (arr.data[i]<arr.data[j])
			{
				int temp;
				temp=arr.data[j];
				arr.data[j]=arr.data[i];
				arr.data[i]=temp;
			}
		}
	}
	
	
}

bool remove(int_array& arr, const int& target)
{
	if (contains(arr,target)){
	for (unsigned int i=0; i<arr.count;i++)
	{
		if (arr.data[i]==target)
		{
			unsigned int j=i;
			while (j<arr.count)
			{
				arr.data[j]=arr.data[j+1];
				j++;	
			}
			arr.count=arr.count-1;
		}
		}
		
	}
	
	//since already sorted and test code doesn't require it, not including the sort code here
	return false;
}

