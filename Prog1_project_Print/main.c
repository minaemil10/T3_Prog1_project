#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_ACCOUNTS        100
typedef struct
{
    int month;
    int year;
} date;
typedef struct
{
    unsigned long long int account_no;/*the data size is large*/
    char name[100];
    char mail[100];
    double balance;
    char mobile[15];
    date d_open;
} user;

user accounts[MAX_ACCOUNTS];        //accounts data
void declare()
{
    //0
    accounts[0].account_no = 9780136019;
    strcpy(accounts[0].name,"Mohamed Ali") ;
    strcpy(accounts[0].mail,"m.ali@gmail.com") ;
    accounts[0].balance = 10000.54;
    strcpy(accounts[0].mobile,"01254698321") ;
    accounts[0].d_open.month = 12;
    accounts[0].d_open.year = 2008;
    //1
    accounts[1].account_no = 9780135102;
    strcpy(accounts[1].name,"Ahmed Ashraf") ;
    strcpy(accounts[1].mail,"a.ashraf@gmail.com") ;
    accounts[1].balance = 800.93;
    strcpy(accounts[1].mobile,"01054698321") ;
    accounts[1].d_open.month = 10;
    accounts[1].d_open.year = 2009;
    //2
    accounts[2].account_no = 9780136498;
    strcpy(accounts[2].name,"Belal Ahmed") ;
    strcpy(accounts[2].mail,"b.ahmed@gmail.com") ;
    accounts[2].balance = 50000.16;
    strcpy(accounts[2].mobile,"01154698321") ;
    accounts[2].d_open.month = 8;
    accounts[2].d_open.year = 2010;
    //3
    accounts[3].account_no = 9780138871;
    strcpy(accounts[3].name,"Chris Ali") ;
    strcpy(accounts[3].mail,"c.ali@gmail.com") ;
    accounts[3].balance = 123.8;
    strcpy(accounts[3].mobile,"01554698321") ;
    accounts[3].d_open.month = 6;
    accounts[3].d_open.year = 2011;
    //4
    accounts[4].account_no = 9780131619;
    strcpy(accounts[4].name,"Fady Mohamed") ;
    strcpy(accounts[4].mail,"f.mohamed@gmail.com") ;
    accounts[4].balance = 6922.47;
    strcpy(accounts[4].mobile,"03254698321") ;
    accounts[4].d_open.month = 3;
    accounts[4].d_open.year = 2012;
}
const char* monthName(int month)
{
    switch (month)
    {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;
    }

}
void prinetr(user a)
{
    printf("Account number: %llu\n",a.account_no);
    printf("Name: %s\n",a.name);
    printf("E-mail: %s\n",a.mail);
    printf("Balance: %.2lf $\n",a.balance);
    printf("Mobile: %s\n",a.mobile);
    printf("Date Opened: %s %d\n",monthName(a.d_open.month),a.d_open.year);
}


int main()
{
    declare();
    prinetr(accounts[2]);
    return 0;
}
