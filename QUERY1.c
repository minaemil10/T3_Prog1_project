#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_ACCOUNTS        100
#define MAX_ACCOUNT_LENGTH  12

typedef struct
{
    int month;
    int year;
} date;
typedef struct
{
    char account_no[MAX_ACCOUNT_LENGTH];/*the data size is large*/
    char name[100];
    char mail[100];
    double balance;
    char mobile[15];
    date d_open;
} user;

user accounts[MAX_ACCOUNTS];        //accounts data
int count = 0;                      //accounts number
int checkNumber(char* number)
{

    while(*number!='\0')
    {
        if(!(*number>='0'&& *number<='9'))
        {
            printf("Error: Invalid Input\n");
            return 0;
        }
        else number++;
    }
    return 1;
}
void QUERY()
{
    char accountNumber[MAX_ACCOUNT_LENGTH];
    int flag=0;
    const char* months[]= {" ","January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"
                          };   //array to get the month as a word not a number to be printed as in the given example
    do{
            printf("Enter the account number: ");
           scanf("%s",accountNumber);
    while(!checkNumber(accountNumber))
    {
        printf("Enter the account number: ");
        scanf("%s",accountNumber);
    }

    for(int i=0; i<count; i++)
    {
        if(!strcmp(accountNumber,accounts[i].account_no))
        {
            printf("Account Number : %s\n",accounts[i].account_no);
            printf("Name: %s\n",accounts[i].name);
            printf("E-mail : %s\n",accounts[i].mail);
            printf("Mobile: %s\n",accounts[i].mobile);
            printf("Date Opened: %s %d\n",months[accounts[i].d_open.month],accounts[i].d_open.year);
            flag=1;
            break;
        }
        else continue;
    }
    if(!flag) printf("Error: Account number doesn't exist\n");  //validate for existing of the account
    }
    while(!flag);
    //MENU();

}
int main()
{
    QUERY();
    return 0;
}
