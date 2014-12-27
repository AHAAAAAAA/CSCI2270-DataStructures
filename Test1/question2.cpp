#include "singly_linked_list.h"

using namespace std;
unsigned int freq_globe = 0;

bool check_list(const node*& head_ptr)
{
	for (const node*& cursor = head_ptr; 
		cursor != nullptr && cursor->next != nullptr;
		cursor = cursor->next)
		if (cursor->data > cursor->next->data) return false;
	return true;
}

unsigned int freq_iterative(const node*& head_ptr, const int& target)
{
	unsigned int freq = 0;

	while (head_ptr!=nullptr)
	{
		if (head_ptr->data==target)
		{
			freq++;
		}
		head_ptr=head_ptr->next;
	}


	return freq;
}

unsigned int freq_recursive(const node*& head_ptr, const int& target)
{
	if (head_ptr=nullptr)
	{
		return freq_globe;
	}
	else
	{
		if (head_ptr->data==target)
		{
			freq_globe++;
		}
		head_ptr=head_ptr->next;
		freq_recursive(head_ptr,target);
	}

}

int main()
{
	node* head_ptr1 = nullptr;      // This will be the list 1 head
	const node* const_head_ptr1;	
	int target = 9;
	
	const_head_ptr1 = head_ptr1;
	cout << "Here is your list: " << endl;
	print_list(const_head_ptr1);
	cout << "Frequency of " << target << " is " << 
		freq_iterative(const_head_ptr1, target) << endl;
	
	for (unsigned int k = 0; k < 10; ++k)
	{
		add_node(head_ptr1, target);	// add a number to the list
		const_head_ptr1 = head_ptr1;
		cout << "Here is your list: " << endl;
		print_list(const_head_ptr1);
	/*	cout << "Frequency of " << target << " is " << 
			freq_iterative(const_head_ptr1, target) << endl;*/
	}
	
	target = 9;
	cout << "Here is your list: " << endl;
	print_list(const_head_ptr1);
	cout << "Frequency of " << target << " is " << 
		freq_recursive(const_head_ptr1, target) << endl;
	clear_list(head_ptr1);				// destroy list 1
	

}
