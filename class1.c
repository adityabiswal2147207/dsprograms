//declaring the header files
#include<stdio.h>
#include<string.h> 
 
int main()
{
    int data[5];
    int i;

    printf("\nEnter the elements of the array");
    for(i=0;i<5;++i)
    {
        scanf("%d", data+i);
    }
    printf("\nYou entered: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(data + i));
    }
    return 0;
}