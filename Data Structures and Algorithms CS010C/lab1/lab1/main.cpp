/**
 * UCR CS&E
 * CS014 Lab 1
 * main.cpp
 */

#include <iostream>
#include "List.h"
#include "Iterator.h"
#include "Node.h"

#define fibo_number 11

int fibonacci(int n);

using namespace std;

void test_count_zeros() {
	List list_test1;
	int value = 0;
	
	for (int i = 0; i < fibo_number; i++){
		list_test1.push_back(value);
		list_test1.print();
	}
	
	cout << "Counting zeros, should be, " << fibo_number << endl;
	cout << list_test1.count(value) << endl;
}

void test_count_one_middle() {
	List list_test1;
	int value = 1;
	
	for (int i = 0; i < fibo_number; i++){
		list_test1.push_back(0);
		list_test1.print();
	}
	
	list_test1.push_back(value);
	
	for (int i = 0; i < fibo_number; i++){
		list_test1.push_back(0);
		list_test1.print();
	}
	
	
	cout << "Counting ones at middle of the list, should be, " << value << endl;
	cout << list_test1.count(value) << endl;
}

void test_count_one_front() {
	List list_test1;
	int value = 1;
	
	list_test1.push_back(value);
	
		for (int i = 0; i < fibo_number; i++){
		list_test1.push_back(0);
		list_test1.print();
	}
	
	
	cout << "Counting ones at the front of the list, should be, " << value << endl;
	cout << list_test1.count(value) << endl;
}

void test_count_one_end() {
	List list_test1;
	int value = 1;
	
	
	for (int i = 0; i < fibo_number; i++){
		list_test1.push_back(0);
		list_test1.print();
	}
	
	list_test1.push_back(value);
	list_test1.print();
	
	cout << "Counting ones at the end of the list, should be, " << value << endl;
	cout << list_test1.count(value) << endl;
}

void test_count_one_front_middle_end() {
	List list_test1;
	int value = 1;
	
	list_test1.push_back(value);
	
	for (int i = 0; i < fibo_number; i++){
		list_test1.push_back(0);
		list_test1.print();
	}
	
	list_test1.push_back(value);
		
	for (int i = 0; i < fibo_number; i++){
		list_test1.push_back(0);
		list_test1.print();
	}
	
	list_test1.push_back(value);
	list_test1.print();

	cout << "Counting ones at the front, middle and end, should be, " << 3 << endl;
	cout << list_test1.count(value) << endl;
}

void test_insert_after_empty_list() {
	List list_test2;
	list_test2.insert_after(0, 1);
	list_test2.print();
	cout << "Expecting 1," << endl;
}

void test_insert_after_middle_list() {
	List list_test2;
	list_test2.insert_after(0, 1);
	list_test2.print();
	cout << "Expecting 1," << endl;
	list_test2.insert_after(0, 2);
	list_test2.print();
	cout << "Expecting 1, 2," << endl;
	list_test2.insert_after(1, 3);
	list_test2.print();
	cout << "Expecting 1, 2, 3," << endl;
}

void test_insert_after_end_list(){
	List list_test2;
	list_test2.insert_after(0, 1);
	list_test2.print();
	cout << "Expecting 1," << endl;
	list_test2.insert_after(0, 2);
	list_test2.print();
	cout << "Expecting 1, 2," << endl;
	list_test2.insert_after(1, 3);
	list_test2.print();
	cout << "Expecting 1, 2, 3," << endl;
	list_test2.insert_after(2, 4);
	list_test2.print();
	cout << "Expecting 1, 2, 3, 4," << endl;
}

void test_insert_after_invalid_i(){
	List list_test2;
	list_test2.insert_after(0, 1);
	list_test2.print();
	cout << "Expecting 1," << endl;
	list_test2.insert_after(0, 1);
	list_test2.print();
	cout << "Expecting 1, 1," << endl;
	list_test2.insert_after(3, 0);
	cout << "Expecting error msg" << endl;
	list_test2.insert_after(-2, 0);
	cout << "Expecting error msg" << endl;
}

void test_insert_before_empty_list() {
	List list_test3;
	list_test3.insert_before(0, 1);
	list_test3.print();
	cout << "Expecting 1," << endl;
}

void test_insert_before_middle_list() {
	List list_test3;
	list_test3.insert_before(0, 2);
	list_test3.print();
	cout << "Expecting 2," << endl;
	list_test3.insert_before(0, 1);
	list_test3.print();
	cout << "Expecting 1, 2," << endl;
	list_test3.insert_before(1, 0);
	list_test3.print();
	cout << "Expecting 1, 0, 2," << endl;
}

void test_insert_before_end_list(){
	List list_test3;
	list_test3.insert_before(0, 2);
	list_test3.print();
	cout << "Expecting 2," << endl;
	list_test3.insert_before(0, 1);
	list_test3.print();
	cout << "Expecting 1,2," << endl;
	list_test3.insert_before(1, 0);
	list_test3.print();
	cout << "Expecting 1, 0, 2," << endl;
	list_test3.insert_before(2, 3);
	list_test3.print();
	cout << "Expecting 1, 0, 3, 2," << endl;
}

void test_insert_before_invalid(){
	List list_test3;
	list_test3.insert_before(0, 1);
	list_test3.print();
	cout << "Expecting 1," << endl;
	list_test3.insert_before(0, 1);
	list_test3.print();
	cout << "Expecting 1,1," << endl;
	list_test3.insert_before(-2, 0);
	cout << "Expecting error msg" << endl;
	list_test3.insert_before(3, 0);
	cout << "Expecting error msg" << endl;
}

void test_sorted_insert_empty(){
	List list_test4;
	list_test4.sorted_insert(1);
	list_test4.print();
	cout << "Expecting 1," << endl;
}

void test_sorted_insert_middle(){
	List list_test4;
	list_test4.sorted_insert(1);
	list_test4.print();
	cout << "Expecting 1," << endl;	
	list_test4.sorted_insert(2);
	list_test4.print();
	cout << "Expecting 1, 2," << endl;
}

/*void test_sorted_inssert_lessthan(){
	List list_test4;
	list_test4.sorted_insert(1);
	list_test4.print();
	cout << "Expecting 1," << endl;	
	list_test4.sorted_insert(2);
	list_test4.print();
	cout << "Expecting 1, 2," << endl;
	list_test4.sorted_insert(0);
	cout << "Expecting 0, 1, 2," << endl;
} */

int main()
{
	/* Instantiate two Lists */
	List myList;
	List myList2;
	
	/* Try to print an empty List */
	cout << "\nTest printing an empty list:";
	myList.print();
	
	cout << "\nPushing back first " << fibo_number << " Fibonacci numbers:";
	for(int i = 0; i < fibo_number; i++)
	{
		myList.push_back(fibonacci(i));
		myList.print();
	}
	
	cout << endl;
	cout << "Testing Print reverse: " << endl;
	myList.print_reverse();			// PRINT REVERSE TEST
	
	cout << "\nReverse myList pushing front contents of myList into myList2:";
	for(Iterator iter = myList.begin(); !iter.is_equal(myList.end()); iter.next_pos())
	{
		myList2.push_front(iter.get_value());
		myList2.print();
	}
	
	test_count_zeros();
	test_count_one_middle();
	test_count_one_front();
	test_count_one_end();
	test_count_one_front_middle_end();
	
	test_insert_after_empty_list();
	test_insert_after_middle_list();
	test_insert_after_end_list();
	test_insert_after_invalid_i();
	
	test_insert_before_empty_list();
	test_insert_before_middle_list();
	test_insert_before_end_list();
	test_insert_before_invalid();
		
	test_sorted_insert_empty();
	test_sorted_insert_middle();
//	test_sorted_inssert_lessthan();

	cout << endl << endl << "LAB DEMO" << endl;
	List list4;
	list4.push_front(4);
	list4.push_front(3);
	list4.push_front(2);
	list4.push_front(1);
	list4.print();
	list4.print_reverse();
	list4.push_front(1);
	cout << "Testing count" << endl	<< list4.count(1) << endl;
	
	cout << endl << "Testing insert_after" << endl;
	list4.insert_after(2,7);
	
	list4.print();
	
	cout << endl << "Testing insert_before" << endl;
	list4.insert_before(2,9);
	
	list4.print();
	
	cout << endl << "Testing sorted_insert" << endl;
	list4.sorted_insert(8);
	list4.print();
	cout << "Expecting 1,1,8,9,2,7,3,4," << endl;
	
	cout << endl << "Testing sorted_insert" << endl;
	list4.sorted_insert(0);
	list4.print();
	cout << "Expecting 0,1,1,8,9,2,7,3,4," << endl;
	
	cout << endl << "Testing sorted_insert" << endl;
	list4.sorted_insert(10);
	list4.print();
	cout << "Expecting 0,1,1,8,9,2,7,3,4,10," << endl;
	
	
	return 0;
}

/**
 * Local Fibonacci function for filling and testing Lists 
 * @param n the Fibonacci number to calculate
 * @return fibonacci(n)
 */
int fibonacci(int n)
{
	if((n == 0) | (n == 1))
	{
		return n;
	}
	else
	{
		return fibonacci(n-2) + fibonacci(n-1);
	}
}
