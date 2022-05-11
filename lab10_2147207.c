/***************************************************************************************************
 ** Name:- Aditya Biswal
 ** Class:- 3 MCA B
 ** Register number:- 2147207
 ** Program:- To implement binary search tree
 ***************************************************************************************************/

// including the necessary header files first:-
#include <stdio.h>
#include <stdlib.h>

// creating a structure node
struct node
{
    // This will store an integer
    int data;
    // This will act as a right child
    struct node *right_child;
    // This will act as a left child
    struct node *left_child;
};

struct node *new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node *insert(struct node *root, int x)
{
    /*checking if the current root node is empty
    if it is empty then making a node else checking the condition if the value is greater than the node value
    append the value to the right of the node
    else append to left of the code */
    if (root == NULL)
        return new_node(x);
    else if (x > root->data)
        root->right_child = insert(root->right_child, x);
    else
        root->left_child = insert(root->left_child, x);

    return root;
}

/*function to have minimum value
in a node */
struct node *find_minn(struct node *root)
{
    if (root == NULL)
        return NULL;
    // node with minimum value will have no left_child
    else if (root->left_child != NULL)
        // left most element will be minimum according to inorder
        return find_minn(root->left_child);
    return root;
}

/*function to
delete a node from the
tree */
struct node *delete (struct node *root, int x)
{
    // first searching for the item that has to be deleted from the tree
    if (root == NULL)
        return NULL;
    if (x > root->data)
        root->right_child = delete (root->right_child, x);
    else if (x < root->data)
        root->left_child = delete (root->left_child, x);
    else
    {

        // if there are no children

        if (root->left_child == NULL && root->right_child == NULL)
        {
            free(root);
            return NULL;
        }

        // if there is only child

        else if (root->left_child == NULL || root->right_child == NULL)
        {
            struct node *temp;
            if (root->left_child == NULL)
                temp = root->left_child;
            else
                temp = root->right_child;
            free(root);
            return temp;
        }

        // if there are two children for the root node

        else
        {
            struct node *temp = find_minn(root->right_child);
            root->data = temp->data;
            root->right_child = delete (root->right_child, temp->data);
        }
    }
    return root;
}

// function to arrange the items using inorder pattern
void inorder(struct node *root)
{
    // to check if the root node is not null
    if (root != NULL)
    {
        // visiting the left_child
        inorder(root->left_child);
        // printing the data at root
        printf(" %d ", root->data);
        // visiting the right_child
        inorder(root->right_child);
    }
}

// function to arrange the items using postorder pattern
void postorder(struct node *root)
{
    // to check if the root node is not null
    if (root != NULL)
    {
        // visiting the left child
        postorder(root->left_child);
        // visiting the right child
        postorder(root->right_child);
        // printing the data at the root
        printf(" %d ", root->data);
    }
}

// function to arrange the items using treeorder pattern
void treeorder(struct node *root)
{
    // to check if the root node is not null
    if (root != NULL)
    {
        // printing the data at the root
        printf(" %d ", root->data);
        // visting the left child
        treeorder(root->left_child);
        // visiting the right child
        treeorder(root->right_child);
    }
}

// making the main driver code :-->

int main()
{
    struct node *root;
    root = new_node(70);
    insert(root, 14);
    insert(root, 23);
    insert(root, 7);
    insert(root, 10);
    insert(root, 33);
    insert(root, 56);
    insert(root, 80);
    insert(root, 66);
    insert(root, 44);
    insert(root, 50);
    insert(root, 85);
    insert(root, 60);
    insert(root, 90);

    // using the inorder method
    printf("\nUsing the inorder method");
    inorder(root);
    printf("\n");

    // using the postorder method
    printf("\nUsing the postorder method");
    postorder(root);
    printf("\n");

    // using the treeorder method
    printf("\nUsing the treeorder method");
    treeorder(root);
    printf("\n");

    /*inserting new node values for the second part of the
    quetion*/
    // printf("\nsecond part");
    // root = new_node(70);
    // insert(root,60);
    // insert(root,80);
    // insert(root,50);
    // insert(root,65);
    // insert(root,45);
    // insert(root,55);
    // insert(root,75);
    // insert(root,85);
    // insert(root,90);

    // treeorder(root);
    // deleting two nodes from the tree-->
    printf("\n\n\n\n");
    printf("\nAfter deleting the node values 85 and 60\n\n");
    root = delete (root, 85);
    root = delete (root, 60);

    /*Again arranging it in
    treeorder
    inorder
    postorder to see the
    arrangement of the tree*/

    printf("Using Inorder Method:-> ");
    inorder(root);
    printf("\n");
    printf("\nUsing Postorder Method:->");
    postorder(root);
    printf("\n");
    printf("\nUsing Treeorder Method:->");
    treeorder(root);
    printf("\n");
}