/***************************************************************************************************
 ** Name:- Aditya Biswal
 ** Class:- 3 MCA B
 ** Register number:- 2147207
 ** Program:- To implement binary search tree
 ***************************************************************************************************/



//including the necessary header files first:-
#include<stdio.h>
#include<stdlib.h>

//creating a structure node
struct node
{
    //This will store an integer
    int data;
    //This will act as a right child
    struct node *right_child;
    //This will act as a left child 
    struct node *left_child;
};

struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{
    /*checking if the current root node is empty
    if it is empty then making a node else checking the condition if the value is greater than the node value
    append the value to the right of the node
    else append to left of the code */
    if(root==NULL)
        return new_node(x);
    else if(x>root->data)
        root->right_child = insert(root->right_child,x);
    else
        root->left_child = insert(root->left_child,x);
    
    return root;
}


/*function to have minimum value
in a node */
struct node* find_min(struct node *root)
{
    if(root == NULL)
        return NULL;
    //node with minimum value will have no left_child
    else if(root->left_child != NULL)
        //left most element will be minimum according to inorder
        return find_min(root->left_child);
    return root;
}

void inorder(struct node *root)
{
    //to check if the root node is not null
    if(root!=NULL)
    {
        //visiting the left_child
        inorder(root->left_child);
        //printing the data at root
        printf(" %d ", root->data);
        //visiting the right_child
        inorder(root->right_child);
    }
}

void postorder(struct node *root)
{
    //to check if the root node is not null
    if(root != NULL)
    {
        //visiting the left child
        postorder(root->left_child);
        //visiting the right child
        postorder(root->right_child);
        //printing the data at the root
        printf(" %d ", root->data);
    }
}

void treeorder(struct node *root)
{
    //to check if the root node is not null
    if(root!= NULL)
    {
        //printing the data at the root
        printf(" %d ",root->data);
        //visting the left child
        treeorder(root->left_child);
        //visiting the right child
        treeorder(root->right_child);
    }
}


//making the main driver code :-->

int main()
{
    struct node *root;
    root = new_node(70);
    insert(root,14);
    insert(root,23);
    insert(root,7);
    insert(root,10);
    insert(root,33);
    insert(root,56);
    insert(root,80);
    insert(root,66);
    insert(root,44);
    insert(root,50);

    //using the inorder method
    printf("\nUsing the inorder method");
    inorder(root);
    printf("\n");

    //using the postorder method
    printf("\nUsing the postorder method");
    postorder(root);
    printf("\n");

    //using the treeorder method
    printf("\nUsing the treeorder method");
    treeorder(root);
    printf("\n");
}