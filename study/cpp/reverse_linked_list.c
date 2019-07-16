// Iterative C++ program to reverse 
// a linked list 
#include<stdio.h> 
#include<stdlib.h>


/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
	
}; 
void reverse(struct Node** head_node){
    struct Node* current = *head_node;    
    struct Node* prev = NULL;
    struct Node* next = NULL;    
    while(current != NULL) {                        
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;        
    }
    *head_node = prev;
}

void print(struct Node* node){
    struct Node* head = node;
    while(head){
        printf("%d ", head->data );
        head = head->next;
    }
}

void push(struct Node** node, int value){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = (*node);
    (*node) = head;  
    
}

int main() 
{ 
    struct Node* nodeList = NULL; 
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
