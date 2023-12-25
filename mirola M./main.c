#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void modify() {
    char acc[30];
    int index=3;
    int x = 1;


    printf("Enter the account number: ");
    scanf("%s", acc);

    int flag_accountn;
    do {flag_accountn = 1;

        for (int i = 0; acc[i] != '\0'; i++) {
            if (!(acc[i] >= '0' && acc[i] <= '9')) {
                printf("Error: Re-enter your account number (integers only): ");
                scanf("%s", acc);
                flag_accountn = 0;
                break;};}


           int flag;
           { if(flag_accountn == 0)continue;
            flag = 0;
            for (int i=0; i<count;i++) {
                if (strcmp(acc,accounts[i].account_no) ==0) {
                    index = i;
                    flag = 1;
                    break;}}
            if (!flag) {
                printf("Account number not found.\nPlease re-enter the account number: ");
                scanf("%s", acc);
                }} while (!flag );
            } while (!flag_accountn);


    do{
    printf("what do you want to modify a)name\tb)mobile\tc)email\td)return to menu");
    char f;
    scanf("%c", &f);
    getchar();

    switch (f) {
        case 'a':
        case 'A': {
            printf("please enter your name: ");
            scanf("%s", accounts[index].name);
            int flag_name;
            do {flag_name = 1;
                for (int i = 0; accounts[index].name[i] != '\0'; i++) {
                    if (!((accounts[index].name[i] >= 'a' && accounts[index].name[i] <= 'z') ||
                          (accounts[index].name[i] >= 'A' && accounts[index].name[i] <= 'Z') ||
                          (accounts[index].name[i] == ' '))) {
                        printf("error: re-enter your name (characters only): ");
                        scanf("%s", accounts[index].name);
                        flag_name = 0;
                        break;}}} while (!flag_name);
                        break;}
        case 'b':
        case 'B': {
            printf("please enter your mobile: ");
            scanf("%s", accounts[index].mobile);
            int flag_mobile;
            do {flag_mobile = 1;
                for (int i = 0; accounts[index].mobile[i] != '\0'; i++) {
                    if (!(accounts[index].mobile[i] >= '0' && accounts[index].mobile[i] <= '9')) {
                        printf("error: re-enter your mobile (integers only): ");
                        scanf("%s", accounts[index].mobile);
                        flag_mobile = 0;
                        break;}}} while (!flag_mobile);
                        break;}
        case 'c':
        case 'C': {
            printf("please enter your email: ");
            int flag_mail;
                do {
                    scanf("%s", accounts[index].mail);
                    for (int i = 0; accounts[index].mail[i] != '\0'; i++) {
                        flag_mail = 1;
                        if (accounts[index].mail[i] =='@') flag_mail = 0;}
                    if (flag_mail == 1) printf("re-enter email (it must contain an @): ");
                    scanf("%s", accounts[index].mail);
                } while (!flag_mail);

            break;}
        case 'd':
        case 'D':
            // menu();
            break;
        default:
            printf("choice not found: please re-enter a character from 'a' to 'd'\n");
            x = 0;
    }}while(!x);

    FILE *file = fopen("accounts.txt", "w");
    if (file == NULL) {
        printf("error opening file 'accounts.txt'");
        exit(-1);
    }
    fprintf(file, "%s,%s,%s\n", accounts[index].name, accounts[index].mail, accounts[index].mobile);
    fclose(file);
}

int main() {
    modify();
    return 0;
}
