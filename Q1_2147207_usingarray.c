//defining the header files
#include <stdio.h>
#include <stdlib.h>

//defineing the size of the array
#define max_ele 50
#define gen_len 8


#ifndef MAX
#define MAX 10
#endif

//creating a structure
struct std_info
{

    int age;
    char gender[gen_len];
    int area_code;
};
typedef struct std_info std;


//declaring a function:-->
int get_arr_usr(std arr[]);
void display_arr(std *arr, int arr_size);

//making the main function:-->
int main()
{

    // n- defines the total number of elements
    // arr - defines array
    int n = 0;
    std arr[max_ele];
    int option = 0;
    printf("\nSelect an option from below");
    printf("\nPress 0 To exit");
    printf("\n1. Enter values manually");
    printf("\n2. Display the contents");

    scanf("%d", &option);

    switch (option)
    {

    case 0:
        printf("\nExiting From The Application ...");
        break;

    case 1:
        n = get_arr_usr(arr);
        break;
    case 2:
        display_arr(arr, n);
        break;

    default:
        printf("\nInvalid option!!");
        printf("Enter a valid option");
        break;
    }

    return 0;
}


//getting the input from the user
int get_arr_usr(std arr[])
{

    int i, arr_size, j=0;

    printf("\n\nEnter the size of the Array Size:\t");
    scanf("%d", &arr_size);

    for (i = 0; i < arr_size; i += 1)
    {

        printf("\nArray[%d]:", (i + 1));
        printf("\n_________________\n");

        printf("\nEnter your Age:\t");
        scanf("%d", &arr[i].age);

        //removing newline from the input stream, 
        while(getchar()!= '\n');

        printf("\nEnter your Gender\t");
        fgets(arr[i].gender, gen_len, stdin);

        //removing new line in the gender
        while(arr[i].gender[j] != '\n'){
            j+=1;
        }
        arr[i].gender[j] = '\0';
        // reset to 0, so for nxt iteration so starting again from 00
        j=0;

        printf("\nEnter your Area code:\t");
        scanf("%d", &arr[i].area_code);
    }

    display_arr(arr, arr_size);
    return arr_size;
}


//display the content in table format:-->
void display_arr(std *arr, int arr_size){

    char *prt_det[] = {"Age", "Gender", "Area Code"};
    char *und[] = {"______", "_______", "_________"};
    int i=0;

    if(arr_size == 0){
        printf("\nThe Array is Empty, enter something and try again\n");
        return;
    }
      
    printf("\n\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    printf("\n\t%*s | %*s | %*s\n", -3, prt_det[0], -MAX, prt_det[1], MAX, prt_det[2]);
    printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    //printf("\t__________________________________\n\n");

    for(i=0; i<arr_size; i+=1){
        //printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
        printf("\n\t%*d | %*s | %*d\n", -3, arr[i].age, -MAX, arr[i].gender, MAX, arr[i].area_code);
        //printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    }
    
}
