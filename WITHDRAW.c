#include <stdio.h>
#include <stdlib.h>
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_ACCOUNTS 100
#define MAX_ACCOUNT_LENGTH  12

typedef struct
{
    int month;
    int year;
} date;

typedef struct
{
    char account_no[MAX_ACCOUNT_LENGTH];
    char name[100];
    char mail[100];
    double balance;
    char mobile[15];
    date d_open;
} user;

user accounts[MAX_ACCOUNTS]; // accounts data
int count = 0;               // accounts number
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
void WITHDRAW()
{
    char accountNumber[MAX_ACCOUNT_LENGTH],withdrawnAmount [100];;
    int i,flag1=0,flag2;
    do
    {
        printf("Enter the Account Number: ");
        scanf("%s", accountNumber);
         while(!checkNumber(accountNumber))
        {
       printf("Enter the Account Number to transfer money from: ");
        scanf("%s", accountNumber);
        }
        for(i=0; i<count; i++)
        {
            if(!strcmp(accountNumber,accounts[i].account_no))
               {
                   flag1=1;
                   break;
               }
               else continue;
        }
        if (!flag1)
        {
            printf("Error: Account Number doesn't exist\n");
        }
    }
    while (!flag1); //validate for existing of the account
     do
    {
        printf("Enter the amount to be withdrawn (max $10,000): ");
        scanf("%s", withdrawnAmount);
        while(!checkNumber(withdrawnAmount))
        {
            printf("Enter the amount to be withdrawn (max $10,000): ");
            scanf("%s", withdrawnAmount);
        }
        if (atoi(withdrawnAmount) > 10000)
        {
            printf("Error: Max withdrawn limit is $10,000\n");
        }
        if(atof(withdrawnAmount)>accounts[i].balance)
        {
            printf("Error: You don't have enough balance to withdraw\nYour balance: %f\n",accounts[i].balance);
            flag2=0;
        }
        else flag2=1;
    }
    while (atoi(withdrawnAmount) > 10000||!flag2);

    accounts[i].balance-=atof(withdrawnAmount);
    printf("Transaction succeded\nNew Balance:%f\n",accounts[i].balance);
    double withdraw=atof(withdrawnAmount);
        FILE* file = fopen(strcat(accountNumber,".txt"), "a");
    if (file == NULL)
    {
        printf("Error opening file");
        return 0;
    }
 fprintf(file, "Withdrawn amount from the account: %f New Balance: %f\n",withdraw,accounts[i].balance);

    fclose(file);
   // MENU();
}
int main()
{
    WITHDRAW();
}
