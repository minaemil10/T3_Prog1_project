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
int count = 6;                      //accounts number

void declare()
{
    //0
    strcpy(accounts[0].account_no,"9780136019");
    strcpy(accounts[0].name,"Mohamed Ali") ;
    strcpy(accounts[0].mail,"m.ali@gmail.com") ;
    accounts[0].balance = 10000.54;
    strcpy(accounts[0].mobile,"01254698321") ;
    accounts[0].d_open.month = 12;
    accounts[0].d_open.year = 2008;
    //1
    strcpy(accounts[1].account_no,"9780135102");
    strcpy(accounts[1].name,"Ahmed Ashraf") ;
    strcpy(accounts[1].mail,"a.ashraf@gmail.com") ;
    accounts[1].balance = 800.93;
    strcpy(accounts[1].mobile,"01054698321") ;
    accounts[1].d_open.month = 10;
    accounts[1].d_open.year = 2009;
    //2
    strcpy(accounts[2].account_no,"9780136498");
    strcpy(accounts[2].name,"Belal Ahmed") ;
    strcpy(accounts[2].mail,"b.ahmed@gmail.com") ;
    accounts[2].balance = 50000.16;
    strcpy(accounts[2].mobile,"01154698321") ;
    accounts[2].d_open.month = 8;
    accounts[2].d_open.year = 2010;
    //3
    strcpy(accounts[3].account_no,"9780138871");
    strcpy(accounts[3].name,"Chris Ali") ;
    strcpy(accounts[3].mail,"c.ali@gmail.com") ;
    accounts[3].balance = 123.8;
    strcpy(accounts[3].mobile,"01554698321") ;
    accounts[3].d_open.month = 6;
    accounts[3].d_open.year = 2010;
    //4
    strcpy(accounts[4].account_no,"9780131619");
    strcpy(accounts[4].name,"Fady Mohamed") ;
    strcpy(accounts[4].mail,"f.mohamed@gmail.com") ;
    accounts[4].balance = 6922.47;
    strcpy(accounts[4].mobile,"03254698321") ;
    accounts[4].d_open.month = 3;
    accounts[4].d_open.year = 2012;
    //5
    strcpy(accounts[5].account_no,"9780131111");
    strcpy(accounts[5].name,"Fady Young") ;
    strcpy(accounts[5].mail,"f.young@gmail.com") ;
    accounts[5].balance = 0.99;
    strcpy(accounts[5].mobile,"01254961321") ;
    accounts[5].d_open.month = 12;
    accounts[5].d_open.year = 2008;
}
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
char* validateAccountNumber(char *printvalue,int *i)
{
    int flag=0;
    char accountNumber[MAX_ACCOUNT_LENGTH];
    do
    {
        printf("%s",printvalue);
        scanf("%s", accountNumber);
        while(!checkNumber(accountNumber))
        {
            printf("%s",printvalue);
            scanf("%s", accountNumber);
        }
        for(*i=0; *i<count; (*i)++)
        {
            if(!strcmp(accountNumber,accounts[*i].account_no))
            {
                flag=1;
                break;
            }
            else continue;
        }
        if (!flag)
        {
            printf("Error: Account Number doesn't exist\n");
        }
    }
    while (!flag);
    return accountNumber;
}
char* validateDuplication(char *printvalue,int *i)
{
    int flag=0;
    char accountNumber[MAX_ACCOUNT_LENGTH];
    do
    {
        flag=0;
        printf("%s",printvalue);
        scanf("%s", accountNumber);
        while(!checkNumber(accountNumber))
        {
            printf("%s",printvalue);
            scanf("%s", accountNumber);
        }
        for(*i=0; *i<count; (*i)++)
        {
            if(!strcmp(accountNumber,accounts[*i].account_no))
            {
                flag=1;
                break;
            }
            else continue;
        }
        if (flag)
        {
            printf("Error: Account Number already exist\n");
        }
    }
    while (flag);
    return accountNumber;
}


char* validationName()
{
    int flag ;
    char name[100];
    do
    {
         printf("Enter your name:");
         gets(name);
        for (int i=0; i<strlen(name); i++)
        {
            flag = 1;
            if (!((name[i]>='a'&& name[i]<= 'z')||(name[i] >='A'&& name[i] <='Z')||(name[i] == ' ')))
            {
                printf("Error: Name must only consist of characters\n");
                flag = 0;
                break;
            }
        }
    }
    while (!flag);
    return name;
}

char* validateEmail()
{
    char email[100];
    int flag_mail=0;
    do
    {
        printf("Please enter your email:");
        scanf("%s",email);
        for (int i = 0; email[i] != '\0'; i++)
        {
            flag_mail=0;
            if (email[i] == '@')
            {
                flag_mail = 1;
                break;
            }
        }

        if (!flag_mail)
        {
            printf("Error: Email must contain @\n");
        }
    }
    while (!flag_mail);
    return email;
}


char* validateBalance()
{
    char balance[100];
    do
    {
        printf("Please enter your balance:");
        scanf("%s", balance);
    }
    while (!checkNumber(balance));
    return balance;
}
char* validateMobile()
{
    char mobileNumber[15];
    int flag=0;
    do
    {
        flag=0;
        printf("Enter the mobile number: ");
        scanf("%s", mobileNumber);
        while(!checkNumber(mobileNumber))
        {
            printf("Enter the mobile number: ");
            scanf("%s", mobileNumber);
        }
        if(strlen(mobileNumber)!=11)
        {
            printf("Error: Mobile number must consist of 11 numbers\n");
            flag=1;
        }
    }
    while(flag);
  return mobileNumber;
}
int main()
{
    declare();
    char print[100]="Enter the account number: ";
    //validateDuplication(print);
    //validateAccountNumber(print);
    //validationName();
    //validateBalance();
    //validateEmail();
}

