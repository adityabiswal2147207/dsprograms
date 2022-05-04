
//including the header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining the max size of the arrays
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
    struct std_info* next;
};

typedef struct std_info std;

//declaring the main function
void display(std *ln);
int usr_fr_ins(std **ln);

//making of the main function
int main()
{

    // n- defines total number of elements
    // arr - defines an array
    int n = 0;
    std *ln = NULL;
    int option = 1;

    while(option){
    printf("\nSelect options from below");
    printf("\n0. Press 0 To exit");
    printf("\n1. Enter values manually");
    printf("\n2. Display the contents");
    scanf("%d", &option);

    switch (option)
    {

    case 0:
        printf("\nExiting from the Application...");
        break;
    case 1:
        n = usr_fr_ins(&ln);
        break;
    case 2:
        display(ln);
        break;
    

    default:
        printf("\nInvalid option!!");
        printf("\nEnter a valid option");
        break;
    }

    
    }
    return 0;
}


//displaying the details in table form
void display(std *ln){

    char *prt_det[] = {"Age", "Gender", "Area Code"};
    char *und[] = {"______", "_______", "_________"};
    int i=0;
    std *tmp = ln;

    if(ln == NULL){
        printf("\nList empty. Enter data first\n");
        return;
    }
      
    printf("\n\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    printf("\n\t%*s | %*s | %*s\n", -3, prt_det[0], -MAX, prt_det[1], MAX, prt_det[2]);
    printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);

    while(tmp != NULL){

          printf("\n\t%*d | %*s | %*d\n", -3, tmp->age, -MAX, tmp->gender, MAX, tmp->area_code);
          tmp = tmp->next;

    }

}

//getting input from user and inserting it at the front of the linked list:-->
int usr_fr_ins(std **ln)
{

    int i = 1, j=0;
    int cnt = 1;
    std *tmp = NULL;

    while(cnt){

        	
		tmp = (std *) malloc (sizeof(std));

        if(tmp == NULL){
            printf("\nOops Something went wrong!!!!\n");
            break;
        }

        printf("\nLinked List %d:", i );
        printf("\n_________________\n");

        printf("\nEnter your Age:\t");
        scanf("%d", &tmp->age);

        // To remove newline from input stream, 
        while(getchar()!= '\n');

        printf("\nEnter your Gender\t");
        fgets(tmp->gender, gen_len, stdin);

        // to remove new line in the gen

        while(tmp->gender[j] != '\n'){
            j+=1;
        }
        tmp->gender[j] = '\0';
        // reset to 0, so for nxt iteration it'll from 00
        j=0;
        
        printf("\nEnter your Area code:\t");
        scanf("%d", &tmp->area_code);

        //pushlink(ln, age, gender, area_code);
        i += 1;

        tmp->next = *ln;
        *ln = tmp;


        printf("\n\nPress 0 to exit:\t");
        scanf("%d", &cnt);
    }

    
    display(*ln);
    return i;
}