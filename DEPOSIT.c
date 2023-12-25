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
void DEPOSIT()
{
    int i,flag=0;
    char depositAmount[100],accountNumber[MAX_ACCOUNT_LENGTH];
     do
    {
        printf("Enter the Account Number: ");
        scanf("%s", accountNumber);
         while(!checkNumber(accountNumber))
        {
       printf("Enter the Account Number: ");
        scanf("%s", accountNumber);
        }
        for(i=0; i<count; i++)
        {
            if(!strcmp(accountNumber,accounts[i].account_no))
               {
                   flag=1;
                   break;
                    printf("Enter");
               }
               else continue;
        }
        if (!flag)
        {
            printf("Error: Account Number doesn't exist\n");
        }
    }
    while (!flag); //validate for existing of the account
 do
    {
        printf("Enter the amount to be deposited (max $10,000): ");
        scanf("%s", depositAmount);
        while(!checkNumber(depositAmount))
        {
            printf("Enter the amount to be deposited (max $10,000): ");
            scanf("%s", depositAmount);
        }

        if (atoi(depositAmount) > 10000)
        {
            printf("Error: Max deposit limit is $10,000\n");
        }
    } while (atoi(depositAmount) > 10000); //validate for enterred amount
    accounts[i].balance+=atof(depositAmount);
    printf("Deposit successful\nNew balance: %f\n",accounts[i].balance);
        double deposit=atof(depositAmount);
FILE* file = fopen(strcat(accountNumber,".txt"), "a");
    if (file == NULL)
    {
        printf("Error opening file");
    }
    fprintf(file, "Deposit amount: %f\n", deposit));
    fclose(file);
    //MENU();
}
int main()
{
    DEPOSIT();
    return 0;
}

