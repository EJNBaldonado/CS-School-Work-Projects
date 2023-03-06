/**
 * UCR CS&E
 * CS014 Lab 1
 * List.cpp
 */

#include <iostream>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

/**
 * Constructor
 */
List::List()
{
	head = NULL;
	tail = NULL;
}

/**
 * Destructor
 */
List::~List()
{
	cout << "\nList Destructor called...\n";
	
	while(head)
	{
		Node* temp = head;
		head = head->get_next();
		cout << "Deleting.... " << temp->get_value() << endl;
		delete temp;
	}	
}

/**
 * push_back() inserts a new node at the tail
 * end of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_back(int value)
{
	Node* new_node = new Node(value);
	
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_prev(tail);
		tail->set_next(new_node);
		tail = new_node;
	}
}
/**
 * push_front() inserts a new node at the 
 * front of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_front(int value)
{
	Node* new_node = new Node(value);
		
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_next(head);
		head->set_prev(new_node);
		head = new_node;			
	}
}

/**
 * print()const prints the contents of 
 * the list to the console, starting
 * at the head of the list
 * @param none
 * @return none
 */
void List::print()const
{
	cout << "\nList contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return List's head Node pointer
 */
Node* List::get_head()const
{
	return head;
}

/**
 * get_tail()const  returns the tail
 * Node pointer which points to the
 * last element in the list
 * @param none
 * @return List's tail Node pointer
 */
Node* List::get_tail()const
{
	return tail;
}

/**
 * begin()const gets beginning postion of the list
 * @param none
 * @return an Iterator pointing to the beginning of the list
 */
Iterator List::begin()const
{
	Iterator iter;
	iter.set_curr_pos(get_head());
	iter.set_last_pos(get_tail());
	return iter;
}

/**
 * end()const gets past-the-end postion of the list
 * @param none
 * @return an Iterator pointing just past the end of the list
 */
Iterator List::end()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_tail());
	return iter;
}


void List::sorted_insert(int value) {
	int i = 0;
	if(!head){
		push_front(value);
	}
	else{
		for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()){
			if (iter.get_value() > value){
				insert_before(i, value);
				return;
			}
		++i;	
		}
		push_back(value);	
	}
}

Iterator List::rbegin()const
{
	Iterator iter;
	iter.set_curr_pos(get_tail());
	iter.set_last_pos(get_head());
	return iter;
}

Iterator List::rend()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_head());
	return iter;
}

void List::print_reverse() const {
	//for(Iterator itr = List->end(); itr != List->begin(); --itr){
	//	cout << itr.get_value() << ' ';
	//}
	
	if (!head) {
	 	cout << "List is empty" << endl;
	}
	
	for(Iterator iter = rbegin(); !iter.is_equal(rend()); iter.prev_pos()){
		cout << iter.get_value() << ", ";
	}
	cout << endl;
}



void List::insert_after(int i, int value) {
	Node* new_node = new Node(value);
	int size = 0;

	if (!head){
		head = new_node;
		tail = new_node;
		return;
	}
	
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		++size;
	}
	

	if (i < 0 || i > size - 1){
		cout << "Error, i is out of bounds" << endl;
		return;
	}
	else if (i == 0){
		new_node->set_prev(head);
		new_node->set_next(head->get_next());
		head->set_next(new_node);
		tail = new_node;
	}
	else if (i == size - 1){
		/*tail->set_next(new_node);
		new_node->set_prev(new_node);
		tail = new_node;
		*/
		push_back(value);
	}
	else {
		Node* posNode = head;
		for(int j = 0; j <= i; ++j){
			if (j == i){
				Node* nextNode = posNode->get_next();
				new_node->set_next(nextNode);
				new_node->set_prev(posNode);
				nextNode->set_prev(new_node);
				posNode->set_next(new_node);
				cout << "WORKS" << endl;
			}
			else {
			posNode = posNode->get_next();
			}
		}
	}
}

void List::insert_before(int i, int value){
	Node* new_node = new Node(value);
	int size = 0;

	if (!head){
		head = new_node;
		tail = new_node;
		return;
	}

	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		++size;
	}
	
//	cout << endl;
//	cout << size << endl;

	if (i < 0 || i > size - 1){
		cout << "Error, i is out of bounds" << endl;
		return;
	}

	else if (i == 0){
	/*	head->set_prev(new_node);
		new_node->set_next(head);
	//	tail = head;     MAYBE ISSUE WITH SETTING NEW TAIL AS HEAD?
		head = new_node; */
		push_front(value);
	}
	
	else if (i == size - 1){
	//	Node* newNode = new Node(value);
		Node* prevTail = tail->get_prev();
		new_node->set_next(tail);
		new_node->set_prev(prevTail);
		prevTail->set_next(new_node);
		tail->set_prev(new_node);
	}
	else {
		Node* posNode = head;
		for(int j = 0; j <= i; ++j){
			if (j == i){
				Node* prevNode = posNode->get_prev();
				new_node->set_prev(prevNode);
				new_node->set_next(posNode);
				prevNode->set_next(new_node);
				posNode->set_prev(new_node);
			}
			else {
			posNode = posNode->get_next();
			}
		}
	}
}

int List::count(int value) const {
//	int cnt = 0;
//	Node* temp;
//	for (temp = head; temp != nullptr; temp = temp->get_next()){
//		if (temp->get_value() == value){
//			++cnt;
//		}
//	}
//	return cnt;
	unsigned int cnt = 0;
	for (Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()){
		if (iter.get_value() == value){
			++cnt;
		}
	}
	return cnt;
}