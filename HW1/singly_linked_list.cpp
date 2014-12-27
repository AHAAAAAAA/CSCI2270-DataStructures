#include "singly_linked_list.h"

using namespace std;

void add_node(node*& head_ptr, const int& payload)
{
	node banana;
	banana.data=payload;

	if (head_ptr=NULL) //if empty, add node to current location
	{
		banana.next=NULL;
		head_ptr=&banana;
	}
	else if (head_ptr!=NULL) //if not empty, add new node and link it to the first existing node
	{
		banana.next=head_ptr;
		head_ptr=&banana;
	}
}

bool remove_node(node*& head_ptr, const int& target)
{	
	if (head_ptr == nullptr) return false; //what doesn't exist, can't be destroyed
	
	node* removed_node_ptr = head_ptr;	
	if (removed_node_ptr->data == target) //if it's first in line, just shoot and don't waste time
	{
		head_ptr = head_ptr->next;
		delete removed_node_ptr;
		removed_node_ptr = nullptr;
		return true;
	}
	
	while (removed_node_ptr != nullptr && 
		removed_node_ptr->next != nullptr &&
		removed_node_ptr->next->data != target) //Locates target to be annihilated
		removed_node_ptr = removed_node_ptr->next; 
		
	if (removed_node_ptr != nullptr &&
		removed_node_ptr->next != nullptr){ //annihilates the node
		node* next_node_ptr = removed_node_ptr->next->next; 
		delete removed_node_ptr->next;
		removed_node_ptr->next = next_node_ptr;
		return true;
	}
		
	return false;	
}

bool find_list(const node*& head_ptr, const int& target)
{
	const node* cursor = head_ptr;
	while (cursor != nullptr)
	{
		if (cursor->data == target) //if the shoe matches the foot.. go fish!
			return true;
		cursor = cursor->next; //if not, run along to the next foot Prince Charming
	}
	return false;
}

void clear_list(node*& head_ptr)
{
	node* destroyed_node_ptr;
	while (head_ptr != nullptr) //goes through the list destroying things
	{
		destroyed_node_ptr = head_ptr;
		head_ptr = head_ptr->next;
		delete destroyed_node_ptr;
	}

}

void print_list(const node*& head_ptr)
{
	const node* cursor = head_ptr;
	while (cursor != NULL) // Runs through the list yelling
	{
		cout << cursor->data << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

void copy_list(const node*& source_ptr, node*& dest_ptr)
{
	clear_list(dest_ptr); //Just making sure we don't get jumbled lists
	if (source_ptr == nullptr) //uh, can't copy nothing
		return;
	dest_ptr = new node();
	dest_ptr->data = source_ptr->data;
	dest_ptr->next = nullptr;
	node* cursor = dest_ptr;
	while (source_ptr->next != nullptr) //copy machine
	{
		source_ptr =  source_ptr->next;
		cursor->next = new node();
		cursor->next->data = source_ptr->data;
		cursor->next->next = nullptr;
		cursor = cursor->next;
	}

}

