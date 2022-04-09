// coded by:- Aditya Biswal
// Register number:- 2147207
// Program:- Implementing stack using linked list

// including the header files:-->
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct linked_list
{
    struct node *head;
    struct node *top;
} stack;

// to make a new node:-->
node *new_node(int data)
{
    node *z;
    z = malloc(sizeof(struct node));
    z->data = data;
    z->next = NULL;

    return z;
}

// to make a new stack-->
stack *new_stack()
{
    stack *s = malloc(sizeof(stack));
    s->head = NULL;
    s->top = NULL;

    return s;
}

void traversal(stack *s)
{
    node *temp = s->head; // temporary pointer to point to the head

    while (temp != NULL) // iterating over stack
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int is_empty(stack *s)
{
    if (s->top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *s, node *n)
{
    if (is_empty(s))
    {
        s->head = n;
        s->top = n;
    }
    else
    {
        s->top->next = n;
        s->top = n;
    }
}

// function to delete:-->
int pop(stack *s)
{
    if (is_empty(s))
    {
        printf("\nStack underflow\t");
        return -1000;
    }
    else
    {
        int x = s->top->data;
        if (s->top == s->head)
        { // only one node
            free(s->top);
            s->top = NULL;
            s->head = NULL;
        }
        else
        {
            node *temp = s->head;
            while (temp->next != s->top) // iterating to the last element
            {
                temp = temp->next;
            }
            temp->next = NULL;
            free(s->top);
            s->top = temp;
        }
        return x;
    }
}

// making of the main function:-->

int main()
{
    stack *s = new_stack();
    node *a, *b, *c;
    a = new_node(10);
    b = new_node(20);
    c = new_node(30);

    //pop(s);
    push(s, a);
    push(s, b);
    push(s, c);

    traversal(s);
    pop(s);
    traversal(s);

    return 0;
}
