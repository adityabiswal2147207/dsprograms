//coded by:- Aditya Biswal
//Register number:- 2147207
//Program:- Implementing stack using array


//including header files:-->

#include<stdio.h>

#define size 5

int S[size+1];
int top = 0;



//making of the empty condition function:-->
int is_empty(){
    if(top==0)
    {
        return 1;
    }
    else{
        return 0;
    }
}


//making of the push function:-->
void push(int x){
    top = top + 1;
    if(top>size){
        printf("\nstack overflow");
    }
    else{
        S[top] = x;
    }
}


//making of the pop function:-->

int pop(){
    if(is_empty()){
        printf("Stack underflow\n");
        return -1000;
    }
    else{
        top = top-1;
        return S[top+1];
    }
}


//starting the main function:-->

int main(){
    //pop();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    //push(110);

    pop();

    int i;
    for(i=1;i<=size;i++){
        printf("%d\n",S[i]);
    }
    return 0;
}

