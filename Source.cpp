#include <iostream>
#include "linkedList.h"
#include "unorderedLinkedList.h"

using namespace std;

//E//xtend the class linkedListType by adding the following operations :

//a.Find and delete the node with the smallest info in the list. (Deleteonly the first occurrence and traverse the list only once.)

//b.Find and delete all occurrences of a given info from the list. (Traverse the list only once.)	

//Add these as abstract functions in the class linkedListType and provide the definitions of these functions in the class unorderedLinkedList. Also, write a program to test these functions.

int main() {
	unorderedLinkedList<int> list1;
	for (int i = 0; i < 10; i++)
		list1.insertLast(i);
	list1.insertLast(-5);
	for (int i = 9; i >= 0; i--)
		list1.insertLast(i);

	list1.insertLast(3);
	
	if (list1.deleteSmallestElement())
		cout << "Smallest Element Removed" << endl;

	else
		cout << "No Smallest Element Found" << endl;

	if (list1.deleteElement(3))
		cout << "All 3's have been removed" << endl;

	else
		cout << "No 3's in List detected" << endl;
	return 0;
}