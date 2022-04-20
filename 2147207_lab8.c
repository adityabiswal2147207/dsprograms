//Name:- Aditya Biswal
//Register number:- 2147207
//Program:- Pattern Matching using naive matching algorithm


//including the header files-->
#include<stdio.h>
#include<string.h>

//making a function that will search for a specific pattern
void find(char* pattern, char* text)
{
    int M = strlen(pattern);
    int N = strlen(text);

    //implementing a loop to slide the pattern one by one-->
    for(int i=0;i<=N;i++){
        int j;

        //for the current index, we will search for the pattern
        for(j=0;j<M;j++)
            if(text[i+j]!= pattern[j])
                break;
        //if pattern is found        
        if(j==M)
            printf("Pattern found at index %d\n",i);
    }
}

//making the main function-->
int main()
{
    char text[] = "abacaaabaccabacabaa";
    char pattern[] = "abacab";
    //calling the function to search for the pattern from the text
    find(pattern,text);
    //returning back the value
    return 0;
}