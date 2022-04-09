#include<stdio.h>

int main()
{
    int arr[5], n = 3;
    printf("%p",&arr);
    PrintArray(arr,n);
    InitArray(&arr[0],n);
    PrintArray(arr,n);

    return 0;
}

//making of the functions-->