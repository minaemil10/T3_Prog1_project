#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_ACCOUNTS 100

typedef struct
{
    int month;
    int year;
} date;

typedef struct
{
    char account_no[30];
    char name[100];
    char mail[100];
    double balance;
    char mobile[15];
    date d_open;
} user;

user accounts[MAX_ACCOUNTS];
int count = 0;

void Duplicate(char acc[]){ ///test duplicate
int flag1;
    do
    {flag1=1;
        for (int i = 0; i < count; i++)
        {if (strcmp(acc,accounts[i].account_no)== 0)
            {printf("Error: Duplicate account number\nRe-enter the account number: ");
             scanf("%s", accounts[count].account_no);
             flag1 = 0;}}} while (!flag1);}

int noaccountValidation(char acc[],int num)
{int flag_accountn;
    do {
        flag_accountn = 1;
        for (int i = 0; acc[i] != '\0'; i++) {
            if (!(acc[i] >= '0' && acc[i] <= '9')) {
                printf("Error: Re-enter your account number (integers only): ");
                scanf("%s", acc);
                flag_accountn = 0;
                break;}}

            // else Searchacc_no(acc);
            } while (!flag_accountn);}

 void validationName(){
 int flag2 ;
    do
    {for (int i=0; i<strlen(accounts[count].name);i++)
        {flag2 = 1;
            if (!((accounts[count].name[i] >='a'&& accounts[count].name[i]<= 'z')||
                  (accounts[count].name[i] >='A'&&accounts[count].name[i] <='Z')||
                  (accounts[count].name[i] == ' ')))
            {printf("Error: Re-enter your name (characters and spaces only): ");
             scanf("%s", accounts[count].name);
             flag2 = 0;
                break;}}} while (!flag2);}

void validationEmail()
{int flag_mail;
        do {
            for (int i = 0; accounts[count].mail[i] != '\0'; i++) {
                    flag_mail=0;
                if (accounts[count].mail[i] == '@') {
                    flag_mail = 1;
                    break;}}

            if (!flag_mail) {
                printf("Re-enter email (it must contain an @): ");
                scanf("%s", accounts[count].mail);
            }} while (!flag_mail);}


 void validationBalance() {
     char bal[30];
    scanf("%s", bal);
    int flag_;
    do {
        flag_ = 1;
        for (int i = 0; bal[i] != '\0'; i++) {
            if (!(bal[i] >= '0' && bal[i] <= '9')) {
                printf("Error: Re-enter your balance(integers only): ");
                scanf("%s",bal);
                flag_ = 0;
                break;}}}while(!flag_);
                accounts[count].balance = atof(bal);
 }
void validationMobile(){//////fix fn
int flag4;
    do
    {for (int i = 0;i<strlen(accounts[count].mobile);i++)
        {flag4 = 1;
            if (!(accounts[count].mobile[i] >= '0' || accounts[count].mobile[i] <= '9'))
            {printf("Error: Re-enter your mobile (integers only): ");
             scanf("%s", accounts[count].mobile);
             flag4 = 0;
             break;}}

             int flag_mobile ;
             int n=strlen(accounts[count].mobile);
             do{ flag_mobile=1;
                 if(n!=11){
                flag_mobile=0;
                printf("re-enter the mobile number(it must contain 11 numbers):");
                scanf("%s", accounts[count].mobile);}
            } while(!flag_mobile);
    }while (!flag4);}

void addaccount(){

    int a=1;
    count++;
    char acc[30];

    printf("Enter the account number: ");
    scanf("%s", acc);

    int flag_accountn;
    do {
        flag_accountn = 1;
        for (int i = 0; acc[i] != '\0'; i++) {
            if (!(acc[i] >= '0' && acc[i] <= '9')) {
                printf("Error: Re-enter your account number (integers only): ");
                scanf("%s", acc);
                flag_accountn = 0;
                break;}}
            int flag1;
    do
    {flag1=1;
        for (int i = 0; i < count; i++)
        {if (strcmp(acc,accounts[i].account_no)== 0)
            {printf("Error: Duplicate account number\nRe-enter the account number: ");
             scanf("%s", accounts[count].account_no);
             flag1 = 0;}}} while (!flag1);
            } while (!flag_accountn);


    printf("Please enter your name:");
    scanf("%s", accounts[count].name);
    int flag2 ;
    do
    {for (int i=0; i<strlen(accounts[count].name);i++)
        {flag2 = 1;
            if (!((accounts[count].name[i] >='a'&& accounts[count].name[i]<= 'z')||
                  (accounts[count].name[i] >='A'&&accounts[count].name[i] <='Z')||
                  (accounts[count].name[i] == ' ')))
            {printf("Error: Re-enter your name (characters and spaces only): ");
             scanf("%s", accounts[count].name);
             flag2 = 0;
                break;}}} while (!flag2);


    printf("Please enter your email:");
    scanf("%s", accounts[count].mail);
     int flag_mail;
        do {
            for (int i = 0; accounts[count].mail[i] != '\0'; i++) {
                    flag_mail=0;
                if (accounts[count].mail[i] == '@') {
                    flag_mail = 1;
                    break;}}

            if (!flag_mail) {
                printf("Re-enter email (it must contain an @): ");
                scanf("%s", accounts[count].mail);
            }} while (!flag_mail);


    printf("Please enter your balance:");
     char bal[30];
    scanf("%s", bal);
    int flag_;
    do {
        flag_ = 1;
        for (int i = 0; bal[i] != '\0'; i++) {
            if (!(bal[i] >= '0' && bal[i] <= '9')) {
                printf("Error: Re-enter your balance(integers only): ");
                scanf("%s",bal);
                flag_ = 0;
                break;}}}while(!flag_);
                accounts[count].balance = atof(bal);


    printf("please enter your mobile");
     scanf("%s", accounts[count].mobile);
     int flag4;
    do
    {for (int i = 0;i<strlen(accounts[count].mobile);i++)
        {flag4 = 1;
            if (!(accounts[count].mobile[i] >= '0' || accounts[count].mobile[i] <= '9'))
            {printf("Error: Re-enter your mobile (integers only): ");
             scanf("%s", accounts[count].mobile);
             flag4 = 0;
             break;}}

             int flag_mobile ;
             int n=strlen(accounts[count].mobile);
             do{ flag_mobile=1;
                 if(n!=11){
                flag_mobile=0;
                printf("re-enter the mobile number(it must contain 11 numbers):");
                scanf("%s", accounts[count].mobile);}
            } while(!flag_mobile);
    }while (!flag4);

///afhm elfn aw ala2i 8irha
    time_t t;
    time(&t);
    struct tm *tm_info = localtime(&t);

    accounts[count].d_open.month = tm_info->tm_mon + 1;
    accounts[count].d_open.year = tm_info->tm_year + 1900;

    FILE*file =fopen("accounts.txt", "a");
    if(file == NULL)
        {printf("Error opening file 'accounts.txt'\n");
        exit(-1);}

    fseek(file,0,SEEK_SET);
    fprintf(file, "/n%s,%s,%s,%.2lf,%s,%d-%d\n", accounts[count].account_no, accounts[count].name,
            accounts[count].mail, accounts[count].balance, accounts[count].mobile,
            accounts[count].d_open.month, accounts[count].d_open.year);
    fclose(file);


   char filename[30] ;
   sprintf(filename,"%s.txt",accounts[count].account_no);
    FILE *file1=fopen(filename, "w");
    if (file1 == NULL)
    {printf("Error opening file 'accounts.txt'\n");
     exit(-1);}
    fclose(file1);
}

int main()
{
    addaccount();
    return 0;
}
