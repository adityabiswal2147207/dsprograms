//Name:- Aditya Biswal
//Class:- 3 MCA B
//Register number:- 2147207
//Program:- Implementing Hashed List Search

//including the header files or libraries->
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//creating a structure with global declarations
typedef struct{
    char name[31];
    char phone[16];
}LISTING;

//creating a global variable which will be constant and of integer type
const int cMAX_SIZE = 53;

//making the function declarations->
void buildList(LISTING phonelist[], int* last);
void hashSearch(LISTING* phonelist, int last);
int hashKey(char* key, int last);
int collision(int last, int location);

//making the main function->
int main(void)
{
    //local definitions
    LISTING phoneList[cMAX_SIZE];
    int last;

    //statements 
    printf("\nBegin Phone listing\n");
    last = cMAX_SIZE - 1;
    buildList(phoneList,&last);
    hashSearch(phoneList, last);

    printf("\nEnding the phone listing now\n");
    return 0;
}

//buildlist method making-->
void buildList(LISTING phoneList[], int* last)
{
    //local declarations
    FILE* fpPhoneNums;
    LISTING aListing;
    int location;
    int cntCol;
    int end;

    //statements
    fpPhoneNums = fopen("phone.txt","r");
    if(!fpPhoneNums)
    {
        printf("Can't open file\a\n");
        exit(100);
    }

    //setting the keys to null
    for(int i=0;i<=*last; i++)
        phoneList[i].name[0] = '\0';
    
    while(!feof(fpPhoneNums))
    {
        fscanf(fpPhoneNums, "%30[^;]%c %[^;]%*c",aListing.name,aListing.phone);
        location = hashKey(aListing.name, *last);

        if(phoneList[location].name[0]!='/0')
        {
            //collision
            end = *last;
            cntCol = 0;

            while(phoneList[location].name[0]!= '\0' && cntCol++ <= *last)
                location = collision(*last,location);

            if(phoneList[location].name[0]!='\0')
            {
                printf("List full. Not all read.\n");
                return;
            }//is full list
        }//if collision
    phoneList[location] = aListing;
    }//while
return;
}

//making of the hashkey function:- 
int hashKey(char* key, int last)
{
    //local declarations
    int addr;
    int keylen;


    //statements
    keylen = strlen(key);
    addr =0;

    for(int i=0;i<keylen;i++)
        if(key[i]!=' ')
            addr += key[i];
    return (addr % last + 1);
}

//making the collision method
int collision(int last, int location)
{
    //statements
    return location < last ? ++location : 0;
}

//making the method hashsearch
void hashSearch(LISTING* phoneList, int last)
{
    //local definitions
    char srchName[31];
    char more;
    int location;
    int maxSrch;
    int cntCol;

    //statements
    do
    {
        printf("Enter name: ");
        scanf("%s",srchName);

        location = hashKey(srchName,last);
        if(strcmp(srchName,phoneList[location].name) != 0)
        {
            //treat as collision
            maxSrch = last;
            cntCol = 0;
            while(strcmp(srchName,phoneList[location].name)!= 0 && cntCol++ <= maxSrch)
                location = collision(last,location);
        }

        //test for success
        if(strcmp(srchName,phoneList[location].name)==0)
            printf("%-32s(%02d) %-15s\n",phoneList[location].name,location,phoneList[location].phone);
        else
            printf("%s not found\n",srchName);

        printf("\nLook for another number <Y/N>?");
        scanf("%c",&more);
    }while(more=='Y'||more=='y');
}
