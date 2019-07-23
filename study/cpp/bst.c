// C program to demonstrate insert operation in binary search tree
#define MAX(a,b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a > _b ? _a : _b; })  
  
#define MIN(a,b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a < _b ? _a : _b; })  

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct __node
{
    int key;
    struct __node *left, *right;
} node;

// A utility function to create a new BST node
node *newNode(int item)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* Given a non-empty binary search tree, return the node with minimum 
   key value found in that tree. Note that the entire tree does not 
   need to be searched. */
node *minValueNode(node *parentnode)
{
    node *current = parentnode;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
node *deleteNode(node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp; // return right child
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp; // return left child
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

/* Using recursion
A utility function to insert a new node with given key in BST */

// node* insert(node* node, int key)
// {
// 	/* If the tree is empty, return a new node */
// 	if (node == NULL) return newNode(key);

// 	/* Otherwise, recur down the tree */
// 	if (key < node->key)
// 		node->left = insert(node->left, key);
// 	else if (key > node->key)
// 		node->right = insert(node->right, key);

// 	/* return the (unchanged) node pointer */
// 	return node;
// }

/*
Using an iterative approach, insert a value into a BST  
*/
node *insert(node *root, int key)
{
    node *newnode = newNode(key);

    node *end = root;
    node *trailing = NULL;

    while (end != NULL)
    {
        trailing = end;
        if (key < end->key)
            end = end->left;
        else
            end = end->right;
    }
    if (trailing == NULL)
        trailing = newnode;
    else if (key < trailing->key)
        trailing->left = newnode;
    else
        trailing->right = newnode;

    return trailing;
}

bool is_between(node *node, int min, int max)
{
    if (node == NULL)
        return true;
    return node->key > min && node->key < max && is_between(node->left, min, node->key) && is_between(node->right, node->key, max);
}

//Write a method is_binary_search_tree that returns true if a given tree is a BST (use helper function).
bool is_bst(node *node)
{
    if (node == NULL)
        return true;
    return is_between(node, -(__INT_MAX__), __INT_MAX__);
}

//Using an iterative approach, write a function find_node(bst_node* root, int target) that returns the node with the given target value in a BST.
// node *find_node(node *node, int key)
// {
//     while (node != NULL & node->key != key)
//     {
//         if (key < node->key)
//             node = node->left;
//         else
//             node = node->right;
//     }
//     return node;
// }
// Using an recursive approach, write a function: find_node(bst_node* node, int value) that returns the node with the given target value in a BST.
node *find_node(node *node, int key)
{
    if(node == NULL) return NULL;
    if(key < node->key)
        return find_node(node->left, key);
    else if(key > node->key)
        return find_node(node->right, key);        
    else
        return node;
}

int get_height(node *node){
    if(node == NULL) return 0;
    return 1+MAX(get_height(node->left), get_height(node->right));
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("BST height is  %d \n", get_height(root));

    printf("Delete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("is BST? %d \n", is_bst(root));

    printf("find node  %d \n", find_node(root, 80)->key);

    printf("BST height is  %d \n", get_height(root));
    return 0;
}
