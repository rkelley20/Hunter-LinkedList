#ifndef H_unorderedLinkedList
#define H_unorderedLinkedList

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type>{

public:
	bool deleteSmallestElement(); 
	bool deleteElement( int item );
	bool search(const Type& searchItem) const;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the 
	//               list, otherwise the value false is 
	//               returned.

	void insertFirst(const Type& newItem);
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first points to the new list, newItem is
	//               inserted at the beginning of the list,
	//               last points to the last node in the  
	//               list, and count is incremented by 1.

	void insertLast(const Type& newItem);
	//Function to insert newItem at the end of the list.
	//Postcondition: first points to the new list, newItem 
	//               is inserted at the end of the list,
	//               last points to the last node in the 
	//               list, and count is incremented by 1.

	void deleteNode(const Type& deleteItem);
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing 
	//               deleteItem is deleted from the list.
	//               first points to the first node, last
	//               points to the last node of the updated 
	//               list, and count is decremented by 1.

	bool isEmptyList() {
		linkedListType::isEmptyList();
	}

	Type front() {
		return linkedListType::front();
	}

	void destroyList() {
		linkedListType::destroyList();
	}
};

template <class Type>
bool unorderedLinkedList<Type>::deleteSmallestElement() {
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;
	nodeType<Type> *min;
	nodeType<Type> *trailMin;
	
	if (isEmptyList()) {
		return false;
	}
	current = front();

	if (current->next == nullptr) {
		destroyList();
		return true;
	}
	else{
		while (current->next != nullptr) {
			if (current->next-> info < min->info) {
				min = current->next;
				trailMin = current;
			}
			trailCurrent = current;
			current = current->next;
		}
		if (min = linkedListType.front()) {
			linkedListType::first = min->next;
		}
		else {
			trailMin->next = min->next;
		}
	}
	return true;
}

template <class Type>
bool unorderedLinkedList<Type>::deleteElement(int item) {
	bool found = false;

	nodeType<Type> *previous;
	nodeType<Type> *current = front();
	if (isEmptyList()) {
		return false;
	}
	if (front()->info == item) {
		current = current->next;
		found = true;
	}
	while (current != nullptr) {
		if (current->info == item) {
			previous->next = current->next;
			current = previous;
			found = true;
		}
		previous = current;
		current = current->next;
	}

	return found;
}


template <class Type>
bool unorderedLinkedList<Type>::
search(const Type& searchItem) const
{
	nodeType<Type> *current; //pointer to traverse the list
	bool found = false;

	current = linkedListType::first; //set current to point to the first 
					 //node in the list

	while (current != nullptr && !found)    //search the list
		if (current->info == searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //make current point to
									 //the next node
	return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;    //store the new item in the node
	newNode->link = linkedListType::first;      //insert newNode before first
	linkedListType::first = newNode;            //make first point to the
								//actual first node
	linkedListType::count++;                    //increment count

	if (linkedListType::last == nullptr)   //if the list was empty, newNode is also 
						//the last node in the list
		linkedListType::last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;  //store the new item in the node
	newNode->link = nullptr;     //set the link field of newNode
							  //to nullptr

	if (linkedListType::first == nullptr)  //if the list is empty, newNode is 
						//both the first and last node
	{
		linkedListType::first = newNode;
		linkedListType::last = newNode;
		linkedListType::count++;        //increment count
	}
	else    //the list is not empty, insert newNode after last
	{
		linkedListType::last->link = newNode; //insert newNode after last
		linkedListType::last = newNode; //make last point to the actual 
						//last node in the list
		linkedListType::count++;        //increment count
	}
}



template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;

	if (linkedListType::first == nullptr)    //Case 1; the list is empty. 
		cout << "Cannot delete from an empty list."
		<< endl;
	else
	{
		if (linkedListType::first->info == deleteItem) //Case 2 
		{
			current = linkedListType::first;
			linkedListType::first = linkedListType::first->link;
			linkedListType::count--;
			if (linkedListType::first == nullptr)    //the list has only one node
				linkedListType::last = nullptr;
			delete current;
		}
		else //search the list for the node with the given info
		{
			found = false;
			trailCurrent = linkedListType::first;  //set trailCurrent to point
								   //to the first node
			current = linkedListType::first->link; //set current to point to 
								   //the second node

			while (current != nullptr && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}//end while

			if (found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;
				linkedListType::count--;

				if (linkedListType::last == current)   //node to be deleted 
									   //was the last node
					linkedListType::last = trailCurrent; //update the value 
										 //of last
				delete current;  //delete the node from the list
			}
			else
				cout << "The item to be deleted is not in "
				<< "the list." << endl;
		}//end else
	}//end else
}


#endif