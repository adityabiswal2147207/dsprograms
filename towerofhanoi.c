//Coded by:- Aditya Biswal
//Register number:- 2147207
//Program:- Tower of hanoi problem using recursion


//including te header files:-
#include<stdio.h>

void towers(int, char, char, char);    //declaring the function


//making the main function:-->
int main()
{

    //declaring the variables:->
    int num;
    printf("\nEnter the number of disks:- ");
    scanf("%d",&num);
    printf("\nThe sequence of moves invloved in solving the tower of hanoi are: \n");
    towers(num, 'A','C','B');
    return 0;
}


//defining the towers function:-->

void towers(int num, char fromline, char toline, char auxline)
{

    //if the number is 1 then only 1 step is required
    if(num==1){
        printf("\nMove disk 1 from peg %c to peg %c",fromline, toline);
        return;
    }
    towers(num - 1,fromline,auxline,toline);
    printf("\n Move disk %d from line %c to line %c",num, fromline, toline);
    towers(num - 1, auxline, toline, fromline);
}