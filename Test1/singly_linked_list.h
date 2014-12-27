include <iostream>

struct node {
	int data;
	node* next;
};

void add_node(node*& head_ptr, const int& payload);

bool remove_node(node*& head_ptr, const int& target);

void print_list(const node*& head_ptr);

void print_list2(const node*& head_ptr);

bool find_list(const node*& head_ptr, const int& target);

void clear_list(node*& head_ptr);

void clear_list2(node*& head_ptr);

void copy_list(const node*& source_ptr, node*& dest_ptr);

void copy_list2(const node*& source_ptr, node*& dest_ptr);

void copy_list3(const node*& source_ptr, node*& dest_ptr);

void copy_list4(const node*& source_ptr, node*& dest_ptr);

int count_list(const node*& head_ptr, const int& target);

int count_list2(const node*& head_ptr, const int& target);

