#include "dynamic_size_array_sorted.h"

using namespace std;


//Initializer
void init(int_array& arr){
	arr.capacity=arr.DEFAULT_CAPACITY;
	arr.data= new int[arr.DEFAULT_CAPACITY];
	arr.count=0;
}

//Crude clearer
void clear(int_array& arr){
destr(arr);
init(arr);
}

//Crude destroyer
void destr(int_array& arr){
	delete [] arr.data;
	arr.count=0;
}

//printer
void print(const int_array& arr){
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
	cout << endl;
}

//checks if an array contains a target
bool contains(const int_array& arr, const int& target){
	for (unsigned int i=0; i<arr.count;i++){
		if (arr.data[i]==target)
			return true;
		}
	return false;
}

//resizes an array by creating a new array and assigning it to the original array
//shoddy implementation, but works
void resize(int_array& arr){
	int* antiarr;
	arr.capacity*=2;
	antiarr=new int[arr.capacity];

	for (unsigned int i=0;i<arr.capacity;i++)
		antiarr[i]=arr.data[i];

	delete [] arr.data;
	arr.data=antiarr;
}

//adding a payload to an array
void add(int_array& arr, const int& payload){
	if (arr.count==arr.capacity) //checks if at capacity, then resizes
		resize(arr);
	arr.data[arr.count]=payload; //adds to end
	++arr.count;
	
	//sorts entire array after addition, could be done more efficiently
	for (unsigned int i=0;i<arr.count;i++){
		for (unsigned int j=0;j<arr.count;j++){
			if (arr.data[i]<arr.data[j]){
				int temp;
				temp=arr.data[j];
				arr.data[j]=arr.data[i];
				arr.data[i]=temp;
			}
		}
	}	
}
//removes a target and shifts everything down by 1
bool remove(int_array& arr, const int& target){
	if (contains(arr,target)){
	for (unsigned int i=0; i<arr.count;i++){
		if (arr.data[i]==target){
			unsigned int j=i;
			while (j<arr.count){
				arr.data[j]=arr.data[j+1];
				j++;	
				}
			arr.count=arr.count-1;
			}
		}
		
	}
	return true;
}

