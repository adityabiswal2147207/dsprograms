//including the header files
#include<stdio.h>
#include<stdlib.h>

//defining the size of the array
#define max_ele 60
//#define reg_len 7

#ifndef MAX
#define MAX 10
#endif

//creating a structure
struct student
{
    char name[70];
    int reg_no;
    char performance[30];
};
typedef struct student std;

int get_details(std arr[]);
void display(std *arr, int arr_size);

//making the main function
int main()
{
    //n -> defines the total number of elements
    //arr -> defines the array

    int n = 0;

    std arr[max_ele];
    int option = 0;
    printf("\nSelect an option from below");
    printf("\nPress 0 To exit");
    printf("\n1. Enter values manually");
    printf("\n2. Display the contents");

    scanf("%d",&option);

    switch (option)
    {
    case 0:
        printf("\nExiting from the application");
        break;

    case 1:
        n = get_details(arr);
        break;

    case 2:
        display(arr,n);
        break;

    default:
        printf("\nInvalid Option");
        printf("\nEnter a valid entry");
        break;
    }

    return 0;
}


int get_details(std arr[])
{
    int i, arr_size, j=0;

    printf("\nPlease input the array size: ");
    scanf("%d",&arr_size);

    for(i=0;i<arr_size;i+=1)
    {
        printf("\nArray[%d]:",(i+1));
        printf("\n_________________________________\n");

        printf("\nEnter the register number: ");
        scanf("%d",&arr[i].reg_no);

        printf("\nEnter the name: ");
        scanf("%s",&arr[i].name);

        printf("\nEnter the performance: ");
        scanf("%s",&arr[i].performance);
    }

    display(arr, arr_size);
    return arr_size;
}


void display(std *arr, int arr_size)
{
    char *prt_det[] = {"Register number", "Name", "Performance"};
    char *und[] = {"____________", "____________", "_______________"};
    int i=0;

    if(arr_size == 0){
        printf("\nThe Array is Empty, enter something and try again\n");
        return;
    }
      
    //printf("\n\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    printf("\n\t%*s | %*s | %*s\n", -3, prt_det[0], -MAX, prt_det[1], MAX, prt_det[2]);
    //printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);


    for(i=0; i<arr_size; i+=1){
        printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
        printf("\n\t%*d | %*s | %*s\n", -3, arr[i].reg_no, -MAX, arr[i].name, MAX, arr[i].performance);
        printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    }
}