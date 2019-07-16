// Iterative C++ program to reverse 
// a linked list 
#include<stdio.h> 
#include<stdlib.h>

/* Link list node */
typedef struct __Node 
{ 
	int data; 
	struct __Node* next; 
	
} Node; 

void reverse(struct Node** head_node){
    Node* current = *head_node;    
    Node* prev = NULL;
    Node* next = NULL;    
    while(current != NULL) {                               
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;        
    }
    *head_node = prev;
}

void print(Node* node){
    Node* head = node;
    while(head){
        printf("%d ", head->data );
        head = head->next;
    }
}

void push(Node** node, int value){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = value;
    head->next = (*node);
    (*node) = head;  
    
}

int main() 
{ 
    Node* nodeList = NULL; 
    push(&nodeList, 20);
    push(&nodeList, 4);
    push(&nodeList, 15);
    push(&nodeList, 85);

    printf("Given linked list\n");
	print(nodeList);	
    reverse(&nodeList);	
    printf("\nReversed Linked list \n");	
    print(nodeList);
	return 0; 
} 
