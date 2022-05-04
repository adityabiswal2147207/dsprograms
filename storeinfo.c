//including the header files:-->
#include<stdio.h>
#include<stdlib.h>

//creating a structure named student:-->
struct student
{
    char firstname[30];
    char lastname[30];
    int mobile;
    char marks;
}s[5];

//making of the main function:-->
int main()
{
    int i;
    printf("Enter the information for the user:--> ");

    //trying to store the information:-->
    for(i=0;i<5;i++)
    {
        s[i].mobile = i + 1;
        printf("\nFor the mobile number: %d\n",s[i].mobile); 
        printf("Enter the first name for the student:-  ");
        scanf("%s",s[i].firstname);
        printf("\nEnter the last name for the student:-  ");
        scanf("%s",s[i].lastname);
        printf("\nEnter the marks for the student:-  ");
        scanf("%d",&s[i].marks);
    }

    //now displaying the information:->
    for(i=0;i<5;++i)
    {
        printf("\nMobile number: %d/n",i+1);
        printf("Firstname: \t\t Lastname:  \t\t Marks: ");
        puts(s[i].firstname, "\t\t", s[i].lastname, "\t\t", s[i].marks);
    }
    return 0;
}
