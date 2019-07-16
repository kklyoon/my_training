// Iterative C++ program to reverse 
// a linked list 
#include<iostream> 
using namespace std; 

struct Node {
    Node* next;
    int data;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

struct LinkedList{
    Node *head;
    LinkedList(){
        head = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;              
    }
    void print(){
        Node* start = head;
        while(start != NULL){
            cout << start->data << " ";
            start = start->next;
        }
    }
    void reverse(){
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	LinkedList ll; 
	ll.push(20); 
	ll.push(4); 
	ll.push(15); 
	ll.push(85); 

	cout << "Given linked list\n"; 
	ll.print(); 

	ll.reverse(); 

	cout << "\nReversed Linked list \n"; 
	ll.print(); 
	return 0; 
} 
