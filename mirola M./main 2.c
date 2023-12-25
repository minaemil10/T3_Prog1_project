#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added for string functions
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

user accounts[MAX_ACCOUNTS]; // accounts data
int count = 0;               // accounts number

int main() {
    char acc[30];
    int index;
    printf("Enter the account number: ");
    scanf("%s", acc);


    char w[30];
    printf("Enter the amount to be withdrawn (10,000$ maximum): ");
    scanf("%s", w);

    int flag_;
    do {
        flag_ = 1;
        for (int i = 0; w[i] != '\0'; i++) {
            if (!(w[i] >= '0' && w[i] <= '9')) {
                printf("Error: Re-enter the amount to be withdrawn (integers only): ");
                scanf("%s", w);
                flag_ = 1;
                break;
            }
        }

    double withdr = atof(w);
    int flag2 = 1;
    do {
        if (withdr > 10000) {
            printf("Error: The transaction was unsuccessful. Maximum withdrawal limit is 10,000$. Please re-enter the amount: ");
            scanf("%s", w);
            withdr = atof(w);
            flag2 = 0;
        }
    } while (!flag2);
    } while (!flag_);
    accounts[index].balance -= withdr;
    printf("The transaction succeeded.\n");


    FILE *file = fopen("accounts.txt", "a");
    if (file == NULL) {
        printf("Error opening file 'accounts.txt'\n");
        return 0;
    }
    fprintf(file, "%lf\n", accounts[index].balance);
    fclose(file);

    return 0;
}
