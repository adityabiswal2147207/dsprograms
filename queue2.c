//Name:- Aditya Biswal
//Class:- 3 MCA B
//Register number:- 2147207
//Program:- To remove multiples of 10 in a queue.



//including the header files:-
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear;

//function declaration
void enqueue();
void dequeue();
void display();

//making the main function for the program:==>

int main()
{
    int ch;
    while(ch!=4)
    {
        printf("\nProgram to remove the multiples of 10 from the queue");
        printf("\n\tProgram Menu");
        printf('\n1.Add elements');
        printf("\n2.Remove element");
        printf("\n3.Display the queue");
        printf("\n4.Exit");
        printf("\nEnter your preffered choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        
        default:
            printf("\nInvalid Entry request, Please check your response again");
            break;
        }
    }
}


//defining the function for enqueue:-->
void enqueue()
{
    struct node *ptr;
    int item;

    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOverflow");
        return;
    }
    else
    {
        printf("\nEnter value:\t ");
        scanf("%d",&item);
        ptr ->data = item;
        if (front==NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else{
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }   
    }
}

void dequeue()
{
    struct node *ptr;
    if(front==NULL)
    {
        printf("\nUnderflow");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}




void display()
{
     struct node *ptr=NULL;
    ptr = front;
    if(front==NULL)
    {
        printf("\nEmpty queue\n");
    }
    else{
        printf("\nPrinting the values......\n");
        while(ptr!=NULL)
        {
            printf("\n%d\n",ptr->data);
            ptr = ptr->next;
        }
    }
}
