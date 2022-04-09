#include<stdio.h>
#include<stdlib.h>

void swap(int *xp,int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[],int n)
{
    int i, j, min_idx;

    //one by one move boundary of unsorted array
    for(i=0;i<n-1;i++)
    {
        //find the minimum element in unsorted array
        min_idx = 1;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min_idx])
                min_idx = j;
        
        //swap the found minimum element with the first element 
        swap(&arr[min_idx],&arr[i]);
    }
}


//function for printing the array:-->
void printArray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d",arr[i]);
    printf("\n");
}


//function to do quicksort
void quickSort(int number[25], int first, int last)
{
    int i,j,pivot,temp;
    if(first<last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i<j)
        {
            while(number[i]<=number[pivot]&&i<last)
                i++;
            while(number[j]<=number[pivot])
                j--;
            if(i<j){
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quickSort(number,first,j-1);
        quickSort(number,j+1,last);
    }
}


//making of the main function:-->
int main()
{
    int ch,arr[30],number[25];
    int i, count;
    int n;

    printf("\n1. Press 1 to perform selection sort program");
    printf("\n2. Press 2 to perform quicksort program");
    printf("\n0. Press 0 to exit");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        printf("\nHow many elements you want to enter: ");
        scanf("%d",&count);
        printf("\nEnter the elements: ",count);
        for(i=0;i<=count;i++)
            scanf("%d",arr[i]);

        n = sizeof(arr)/sizeof(arr[0]);
        selectionSort(arr,n);
        printf("Sorted array: \n");
        printArray(arr,n);
        return 0;
        break;

    case 2:
        printf("\nHow many elements you want to enter: ");
        scanf("%d",&count);
        printf("\nEnter the elements: ",count);
        for(i=0;i<count;i++)
            scanf("%d",&number[i]);

        quickSort(number,0,count-1);

        printf("\nOrder of sorted elements: ");
        for(i=0;i<count;i++)
            printf("%d",number[i]);
        return 0;
    
    default:
        exit(0);
        break;
    }
}