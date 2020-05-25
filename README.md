Linked Data Structures
------------------------------------------------------------------------------------------------------------------------------
Project Objectives:

The goal of this project is to implement a data structure that stores a finite list of n (zero or more) in an increasing order. 

If there are zero elements in the list, the list is said to be empty.

Each element is stored in an instance of the Single_node<Type> class. If the list is empty, the head and tail pointers are assigned to nullptr. Otherwise, the head pointer points to the first node, the tail pointer points to the nth node, the next pointer of the ith node (1 ≤ i < n) points to the (i +1)th node, and the next pointer of the nth is assigned nullptr.

Project Implementation:

This project will implement two classes: (i) Singly linked nodes: Single_node and
(2) Sorted singly linked lists: Sorted_single_list.

1 Single_node

This class implements each of the nodes in the linked list.

Member Variables:

This class has two member variables:
• A Type referred to as the element of the node, and
• A pointer to a Single_node object referred to as the next pointer

*Runtime indicated in parenthesis

Constructor:

Single_node( Type const &, Single_node * ) – This constructor takes two parameters: a
constant reference to a Type (by default, a new instance of the type Type) and a pointer
to a Single_node (by default nullptr). These are assigned to the member variables,
respectively. (O(1))

Destructor:

~Single_node() – This class uses the default destructor.

Accessors:

This class has two accessors:
• Type retrieve() const – Return the element of the node. (O(1))
• Single_node *next() const - Return the next pointer. (O(1))

Mutators:

This class has no mutators.

2 Sorted_single_list:

This class uses the single_node class to define the operations of the linked list

Member Variables

This class two member variables:
• Two pointers to Single_node<Type> objects, referred to as the head pointer and
tail pointer, respectively, and
• An integer referred to as the list size which equals the number of elements in the
list.

Constructor

Sorted_single_list() - Set all member variables to 0 or nullptr, as appropriate. (O(1))

Destructor

~Sorted_single_list() - Delete each of the nodes in the linked list. (O(n))

Accessors

This class has seven accessors:

• int size() const – Return the number of items in the list. (O(1))
• bool empty() const – Return true if the list is empty, false otherwise. (O(1))
• Type front() const - Retrieve the object stored in the node pointed to by the head
pointer. This function throws an underflow if the list is empty. (O(1))
• Type back() const – Retrieve the object stored in the node pointed to by the tail
pointer. This function throws an underflow if the list is empty. (O(1))
• Single_node<Type> *head() const - Return the head pointer. (O(1))
• Single_node<Type> *tail() const - Return the tail pointer. (O(1))
• int count( Type const & ) const - Return the number of nodes in the linked list
storing a value equal to the argument. (O(n))

Mutators

This class has three mutators:

• void insert( Type const & ) - Create a new Single_node<Type> storing the
argument, placing it into the correct location in the linked list such that the
element in the previous node (if any) is less than or equal to the element stored in
the current node, and that element is less than or equal to the element stored in
the next node. The head and tail pointers may have to be updated if the new node
is placed at the head or tail of the linked list. (O(n))

• Type pop_front() – Delete the node at the front of the linked list and, as
necessary, update the head and tail pointers. Return the object stored in the node
being popped. Throw an underflow exception if the list is empty. (O(1))

• int erase( Type const & ) - Delete all nodes in the linked list that contains the
object equal to the argument (use == to test for equality with the retrieved
element). As necessary, update the head and tail pointers and the next pointer of
any other node within the list. Return the number of nodes that were deleted.
(O(n))
