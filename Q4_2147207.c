#include<stdio.h>
#include<stdlib.h>


//defining the maximum size of arrays
#define max_ele 60

#ifndef MAX
#define MAX 10
#endif

struct student
{
    char name[70];
    int reg_no;
    char performance[30];
    struct std_info* next;
};
typedef struct student std;

int get_details(std **ln);
void display(std *ln);

int main()
{
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
        printf("\nExiting from the application");
        break;
    
    case 1:
        n = get_details(&ln);
        break;

    case 2:
        display(ln);
        break;

    default:
        printf("\nYou entered an invalid option...")
        break;
    }

    return 0;
}
}

void display(std *ln)
{
    char *prt_det[] = {"Register_no", "Name", "Performance"};
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

          printf("\n\t%*d | %*s | %*s\n", -3, tmp->reg_no, -MAX, tmp->name, MAX, tmp->performance);
          tmp = tmp->next;

    }
}

int get_details(**ln)
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

        printf("\nEnter your reg_no:\t");
        scanf("%d", &tmp->reg_no);

        printf("\nEnter your name\t");
        scanf("%s",&tmp->name);
        
        printf("\nEnter the performance:\t");
        scanf("%s", &tmp->performance);

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