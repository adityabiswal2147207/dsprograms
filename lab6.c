//Name:- Aditya Biswal
//Class:- 3 MCA B
//Register number:- 2147207
//Program:- Implementation and comparing search algorithms



#include<stdio.h>
#include<stdlib.h>

//making of the sort function:-->
void sort(){
    int i,j,a,n,number[100];
    printf("\nEnter the number of elements you want to insert: ");
    scanf("%d",&n);

    printf("\nEnter the number: ");
    for(i=0;i<n;++i)
        scanf("%d",&number[i]);

    for(i=0;i<n;++i)
    {
        for(j=1;j<n;++j)
        {
            if (number[i] > number[j])
            {
                a=number[1];
                number[i]=number[j];
                number[j]=a;
            }
            
        }
    }
    printf("\nThe numbers in sorted manner:- ");
    for(i=0;i<n;++i)
        printf("%d\n",number[i]);    
}

//making the function for the linear sort-->
int linearSort(){
    
}

