#include <stdio.h>
#include <stdlib.h>

int main()
{
    #include <stdio.h>
#include <stdlib.h>
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_ACCOUNTS 100

typedef struct {
    int month;
    int year;
} date;

typedef struct {
    char account_no[30];
    char name[100];
    char mail[100];
    double balance;
    char mobile[15];
    date d_open;
} user;

user accounts[MAX_ACCOUNTS];
int count = 0;

void delete(){

    char acc[30];
    int index;
    printf("Enter the account number: ");
    scanf("%s", acc);





    if(accounts[i].balance!=0){
        printf("account cannot be deleted");
    }

    if (flag==1){accounts[i]=accounts[i+1];
    count--;
    printf("the account has been deleted");

LE*file=fopen("accounts.txt","w");
if(file==NULL){printf("error openning file'accounts.txt'");
               return(0);}
  fprintf(file, "%s,%s,%s,%s,%s,%d-%d\n", accounts[i].account_no, accounts[i].name, accounts[i].mail, accounts[i].balance, accounts[i].mobile, accounts[i].d_open.month, accounts[i].d_open.year);
    fclose(file);
    }

    int main(){
    withdraw();
    return 0;
    }
