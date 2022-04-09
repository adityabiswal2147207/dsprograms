//declaring the header files
#include<stdio.h>
#include<stdlib.h>
#define size 200  //defining the maximum size of an array
int main()  //main function
{
    //initializing  or declaring the variables
    char choice;

    while (1)
    {
        
        //Giving the options to the users to choose from by displaying them onto the console
        printf("Press 1 to create an empty array\n");
        printf("Press 2 to create a random array\n");
        printf("Press 3 to create a matrix array\n");
        printf("Press 4 to find max of an array\n");
        printf("Press 5 to find max position of an array element\n");
        printf("Press 6 to find the min of an array\n");
        printf("Press 7 to find the min position of an array element\n");
        printf("Press 8 to swap the array elements\n");
        printf("Press 9 to shift right the array element\n");
        printf("Press 10 to shift left the array element\n");
        printf("Press 11 to copy the array\n");
        printf("Press 12 to find an element in an array\n");

        printf("\n\nEnter your choice:- ");
        scanf("%c",&choice);


        switch(choice)
        {
            case '1':
                printf("Progran to create an empty matrix");
                char name[size];
                printf("Enter your name christite: ");
                gets(name);
                printf("Welcome to christ demmed to be university %s",name);
                break;

            case '2':
                unsigned short i, j, n;

                printf("Enter the dimension of the matrix: ");
                scanf("%hu", &n);

                for(i = 0; i < n;i++) {
    	            for(j = 0; j < n;j++) {

    		            printf("%d ", rand()%100);
    	            }
    	            printf("\n");
                }
                break;

            case '3':
                int a[2][3],i,j;
	            printf("\nENTER VALUES FOR THE MATRIX:\n");
	            for(i=0;i<2;i++)
		            for(j=0;j<3;j++)
			            scanf("%d",&a[i][j]);
	            printf("\nTHE VALUES OF THE MATRIX ARE:\n");
	            for(i=0;i<2;i++)
            	{
		            for(j=0;j<3;j++)
			            printf("%5d",a[i][j]);
  		            printf("\n");
	            }
                break;
            default:
                printf("\nInvalid Operation");
        }
    }
    return 0;
}