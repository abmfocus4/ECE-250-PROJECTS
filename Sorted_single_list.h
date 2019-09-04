/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  bmalapat @uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Winter) 2018
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Exception.h"
#include <iostream>

template <typename Type>
class Single_node {
		public:
			Type       element;
			Single_node *next_node;

			Single_node(Type const &e = Type(), Single_node *n = 0);
			Type retrieve() const;
			Single_node *next() const;
		};

template <typename Type>
class Sorted_single_list {
	public:

		Sorted_single_list();
		~Sorted_single_list();

		// Accessors

		int size() const;
		bool empty() const;

		Type front() const;
		Type back() const;

		Single_node<Type> *head() const;
		Single_node<Type> *tail() const;

		int count( Type const & ) const;

		// Mutators


		void insert( Type const & );

		Type pop_front();

		int erase( Type const & );

private:
	Single_node<Type> *list_head;
	Single_node<Type> *list_tail;
	int list_size;
};

template <typename Type>
Single_node<Type>::Single_node(Type const &e, Single_node<Type> *n) :
	element(e),
	next_node(n) {
	// empty constructor
}

template <typename Type>
Type Single_node<Type>::retrieve() const {
	//returning the element of the next node 
	return element;
}

template <typename Type>
Single_node<Type>* Single_node<Type>::next() const {
	//returning the element of the next pointer
	return next_node;
}

/////////////////////////////////////////////////////////////////////////
//                      Public member functions                        //
/////////////////////////////////////////////////////////////////////////
template <typename Type>
Sorted_single_list<Type>::Sorted_single_list() :
	list_head(nullptr),
	list_tail(nullptr),
	list_size(0) {
	// empty constructor
}



template <typename Type>
Sorted_single_list<Type>::~Sorted_single_list() {
	
	// removing the elements of the linked list until the list is empty
	
	//storing the return value of the pop member function temporarily in local variable trash 
	
	Type trash{};
	while(!empty())
		trash = pop_front();
	
}

template <typename Type>
int Sorted_single_list<Type>::size() const {
	// returning the size of the linked list
	return list_size;
}

template <typename Type>
bool Sorted_single_list<Type>::empty() const {
	
	return (list_size == 0);
	
}

template <typename Type>
Type Sorted_single_list<Type>::front() const {
	
	if( empty() )
		throw underflow();
	else	
		return list_head->retrieve();
	
}

template <typename Type>
Type Sorted_single_list<Type>::back() const {

	if(empty() == true)
		throw underflow();	
	else
		return list_tail->retrieve();
}

template <typename Type>
Single_node<Type> *Sorted_single_list<Type>::head() const {

	return list_head;
	
}

template <typename Type>
Single_node<Type> *Sorted_single_list<Type>::tail() const {

	return list_tail;
	
}

template <typename Type>
int Sorted_single_list<Type>::count(Type const &obj) const {
	
	
	// No. of times the value appears in the linked list
	int counter{0};
	
	// Initialization statement: Node tracker(p_Initial) == 1st node
	
	// Conditional expression: run the loop until we reach the end of the // list, i.e Node tracker points to nullptr
	
	// Incredental Statement: Incrementing Node tracker to the next node
	
	for(
		Single_node<Type> *p_Initial{list_head}; 
		(p_Initial != nullptr); 
		p_Initial = p_Initial->next()
		)
		{
			// if current node element is equal to the value of the argument 
			// increment the counter
			
			if(p_Initial->retrieve() == obj)
				++counter;
		}
		
		
	return counter;
}

template <typename Type>
void Sorted_single_list<Type>::insert(Type const &obj) {

if((list_size == 0) && empty())
	{	
		list_head = new Single_node<Type>{obj, list_head};	
		list_tail = list_head;
		++list_size;	
	}
	
	else if(obj <= list_head->retrieve())
	{

		list_head = new Single_node<Type>{obj, list_head};
		++list_size;
	}
	
	else if(obj >= list_tail->retrieve()){

		list_tail->next_node = new Single_node<Type>{obj, nullptr};
		list_tail = list_tail->next();
		++list_size;
	}
	
	else
	{
		for( Single_node<Type> *Node_selector{list_head};
			 Node_selector != nullptr;
			 Node_selector = Node_selector->next() )
			 {
			 
				Type previous_obj{Node_selector->retrieve()};
				Type after_previous_obj{Node_selector->next()->retrieve()};
			 
				if( 
				 (previous_obj <= obj) && (previous_obj <= after_previous_obj) 
				 )
				 {
										 
					Node_selector->next_node = new Single_node<Type>{obj,nullptr};
					Node_selector = Node_selector->next();

				 }
			 }
		++list_size;
	}


}

template <typename Type>
Type Sorted_single_list<Type>::pop_front() {
	
	// Variable used to store the return value or the object stored at the front of the linked list
	Type object{};

	if( empty() )
		throw underflow();
	else {
		
		//updating head
		Single_node<Type> *target_node{list_head};
		object = target_node->retrieve();
		list_head = list_head->next();
		
	// deleting the target node
		delete target_node;
		target_node = nullptr;
		
		list_size -=1;
	}
	
	//updating tail
	if( empty() == true)
		list_tail = nullptr;
	
	return object;
}

template <typename Type>
int Sorted_single_list<Type>::erase(Type const &obj) {
	
	int num_deleted_nodes{0};
	
	if(empty())
		return num_deleted_nodes;
	else{
		
		for( Single_node<Type> *Node_selector{list_head};
			 Node_selector != nullptr;
			 Node_selector = Node_selector->next() )
			 {
				 
				 if(Node_selector->retrieve() == obj)
				 {
					 Single_node<Type> *target_node{Node_selector};
					 Node_selector = Node_selector->next();
					 
					 delete target_node;
					 target_node = nullptr;
					 
					 --list_size;
					 ++num_deleted_nodes;
				 }
			 }
		
		if(empty())
			list_tail = nullptr;
		
	}
	
	return num_deleted_nodes;
	
}


#endif