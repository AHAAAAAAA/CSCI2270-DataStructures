#include "terrible_dynamic_size_array_unsorted.h"

using namespace std;


void init(int_array& arr)
{
	arr.count = 0;
	arr.capacity = arr.DEFAULT_CAPACITY;
}

void clear(int_array& arr)
{
	destr(arr);
	init(arr);
}

void destr(int_array& arr)
{
	delete [] arr.data;
	arr.count = 0;
}

void print(const int_array& arr)
{
	//i increments prior to printing instead of after
	for (unsigned int i = 0; i < arr.count; i++)
		cout << arr.data[i] << " ";
	cout << endl;
}

bool contains(const int_array& arr, const int& target)
{
	unsigned int i;
	for (i = 0; i < arr.count; ++i);
	{
		if (arr.data[i] == target) return true;
		else return false;	
	}
	return false;
}

void resize(int_array& arr)
{
	arr.capacity *= 2;
	int* new_data = new int[arr.capacity];
	for (unsigned int i = 0; i < arr.count; ++i)
	{
		new_data[i] = arr.data[i];
	}
	arr.data = new_data;
	delete [] arr.data;
}

void add(int_array& arr, const int& payload)
{
	//It sets arr.count to arr.capacity instead of comparing which results in an always true function
	if ((arr.count == arr.capacity))
		resize(arr);
	//Increments count before inserting the payload, putting the data in the index+1
	arr.data[arr.count++] = payload;
}

bool remove(int_array& arr, const int& target)
{
	unsigned int i = 0; 
	
	//Compare function wrong, single = sets the arr.count to 0.
	if ((arr.count == 0)) 
		return false;
	
	while (i < arr.count && arr.data[i] != target)  
	{i++;}

	//there was a very cruel semicolon after the if statement forcing the remove function to always return false
	if (i == arr.count)
		return false;
		
	//doesn't work, needs a decent loop
	while(i<arr.count){
	arr.data[i] = arr.data[i+1];
	i++;}
	
	arr.count--;
	return true;
}

