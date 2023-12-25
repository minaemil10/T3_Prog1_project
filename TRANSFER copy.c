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
int count = 0;                    //accounts number
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
void TRANSFER()
{
    char transferredAmount[100],accountNumber1[MAX_ACCOUNT_LENGTH],accountNumber2[MAX_ACCOUNT_LENGTH];
    int i,j,flag1=0,flag2=0;
    do
    {
        printf("Enter the amount to be transferred (max $10,000): ");
        scanf("%s", transferredAmount);
        while(!checkNumber(transferredAmount))
        {
            printf("Enter the amount to be transferred (max $10,000): ");
            scanf("%s", transferredAmount);
        }
        if (atoi(transferredAmount) > 10000)
        {
            printf("Error: Max transferred limit is $10,000\n");
        }
    }
    while (atoi(transferredAmount) > 10000);  //validate for enterred amount
    do
    {
        printf("Enter the Account Number to transfer money from: ");
        scanf("%s", accountNumber1);
         while(!checkNumber(accountNumber1))
        {
            printf("Enter the Account Number to transfer money from: ");
        scanf("%s", accountNumber1);
        }
        for(i=0; i<count; i++)
        {
            if(!strcmp(accountNumber1,accounts[i].account_no))
                flag1=1;
        }
        if (!flag1)
        {
            printf("Error: Account Number doesn't exist\n");
        }
    }
    while (!flag1);  //validate for existing of the account
    do
    {
        printf("Enter the Account Number to transfer money to: ");
        scanf("%s", accountNumber2);
         while(!checkNumber(accountNumber2))
        {
            printf("Enter the Account Number to transfer money to: ");
        scanf("%s", accountNumber2);
        }
        for(j=0; j<count; j++)
        {
            if(!strcmp(accountNumber2,accounts[j].account_no))
                flag2=1;
        }
        if (!flag2)
        {
            printf("Error: Account Number doesn't exist\n");
        }
    }
    while (!flag2);//validate for existing of the account
    accounts[i].balance-=atoll(transferredAmount);
    accounts[j].balance+=atoll(transferredAmount);  // Update the balances of the source and destination accounts
    printf("Transfer Successful\nNew balance of The source account: %f\nNew balance of The destination account: %f\n",accounts[i].balance,accounts[j].balance);
   /* FILE* file = fopen("accounts.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file 'accounts.txt'");
        return 0;
    }
    fprintf(file, "%f\n", accounts[i].balance);
        fprintf(file, "%f\n", accounts[j].balance);

    fclose(file);*/
   //MENU();

}
int main()
{
    TRANSFER();
    return 0;
}
