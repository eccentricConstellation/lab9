/************************************************************************
     This is the implementation file for the LList class which is a 
container based on a doubly linked list. The student is required to 
write the rearview function as well as the copy constructor. Note that 
the copy constructor will not be able to use the add function to produce 
a true copy because of the strange behavior of the add function, which 
treats all numbers divisible by five differently than other numbers.
	John Dolan		Ohio University		Spring 2018
************************************************************************/
#include<iostream>
#include "llist.h"
using namespace std;

void LList::frontview()const{
    node* cursor = head;
    while (cursor != NULL){
	cout<<cursor->data() <<"  ";
	cursor = cursor->next();
    }
}

// The student is required to write the implementation of this function
void LList::rearview()const{
	node* cursor = tail;
    while (cursor != NULL)
    {
		cout << cursor->data() << "  ";
		cursor = cursor->previous();
	}
}


void LList::add_item(int item){
    if(head == NULL){
	head=tail=new node(item);
	nodecount++;
    }
    else if(item%5 == 0 && nodecount > 3)
    {
		int i = 0;
		node* cursor=head;
		while(i < nodecount/2)
		{
		    cursor = cursor->next();
		    i++;
		}
		cursor->previous()->set_next(new node(item,cursor->previous(),cursor->next()));
		nodecount++;
    }
    else{
	tail->set_next(new node(item, tail));
	tail = tail->next();
	nodecount++;
    }
}

LList::~LList(){
   node* rmptr;
   while(head != NULL){
	rmptr=head;
	head = head->next();
	delete rmptr;
   }
}

LList::LList(const LList& other){
	if(other.head == other.tail)
	{
		if(other.head == NULL)
		{
			head = NULL;
			tail = NULL;
			return;
		}
		head= new node(other.head->data());
		tail = head;
		nodecount++;
	}
	else
	{	
		node* cursor = other.head;
		head = new node(cursor->data());
		tail = head;
		nodecount++;
		cursor = cursor->next();
		while(cursor!=NULL)
		{
			tail->set_next(new node(cursor->data(), tail));
			tail = tail->next();
			cursor = cursor->next();
			nodecount++;
	    }
	}
}
