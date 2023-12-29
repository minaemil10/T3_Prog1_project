#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LEN             400
#define MAX_LINES           100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_ACCOUNTS        100
#define MAX_ACCOUNT_LENGTH  50
#define MAX_Keyword         50
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

user accounts[MAX_ACCOUNTS];        //accounts data
int count = 0;                      //accounts number

int loadAccounts()
{
    count =0;
    const char* filename="accounts.txt";
    FILE* file = fopen(filename, "r+");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return 0;
    }
    char line[400];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        char* token;
        token = strtok(line, ",");
        if (token == NULL)
        {
            printf("Invalid file format: %s\n", filename);
            break;
        }
        strcpy(accounts[count].account_no,token);

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            printf("Invalid file format: %s\n", filename);
            break;
        }
        strcpy(accounts[count].name, token);

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            printf("Invalid file format: %s\n", filename);
            break;
        }
        strcpy(accounts[count].mail, token);

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            printf("Invalid file format: %s\n", filename);
            break;
        }
        accounts[count].balance = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            printf("Invalid file format: %s\n", filename);
            break;
        }
        strcpy(accounts[count].mobile, token);

        token = strtok(NULL, "-");
        if (token == NULL)
        {
            printf("Invalid file format: %s\n", filename);
            break;
        }

        accounts[count].d_open.month=atoi(token);
        token = strtok(NULL, " ");
        if (token == NULL)
        {
            printf("Invalid file format: %s\n", filename);
            break;
        }
        accounts[count].d_open.year = atoi(token);
        count++;
        if (count >= MAX_ACCOUNTS)
        {
            printf("Maximum account limit reached: %d\n", MAX_ACCOUNTS);
            break;
        }
    }

    fclose(file);
}
int login()
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    getchar();

    printf("Enter password: ");
    scanf("%s", password);
    getchar();

    FILE* file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file: users.txt\n");
        return 0;
    }

    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2];  // +2 for space and null

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char storedUsername[MAX_USERNAME_LENGTH];
        char storedPassword[MAX_PASSWORD_LENGTH];

        sscanf(line, "%s %s", storedUsername, storedPassword);

        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0)
        {
            fclose(file);
            system("cls");
            printf("Welcome to the system, %s\n",storedUsername);
            loadAccounts();
            return 1;  // Successful login
        }
    }

    fclose(file);
    return 0;
}
void quit()
{
    printf("Are you sure thet you want to exit?\n1)yes                  2)no\n");
    int val;
    scanf("%d",&val);
    if(val==1)
        exit(1);
}
int checkNumber(char* number)
{
    while(*number!='\0')
    {
        if(!(*number>='0'&& *number<='9'||*number=='.'))
        {
            printf("Error: Invalid Input number must consist of integers only\n");
            return 0;
        }
        else number++;
    }
    return 1;
}
char* validateAccountNumber(char *printvalue,int *i)
{
    int flag=0;
    char* accountNumber = (char*)malloc(MAX_ACCOUNT_LENGTH* sizeof(char));
    do
    {
        printf("%s",printvalue);
        scanf("%s", accountNumber);
        getchar();
        while(!checkNumber(accountNumber))
        {
            printf("%s",printvalue);
            scanf("%s", accountNumber);
            getchar();
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
            if(askMenu()) return "0";
        }
    }
    while (!flag);
    return accountNumber;
}
char* validateDuplication(char *printvalue,int i)
{
    int flag1=0,flag2=0;
    char* accountNumber = (char*)malloc(MAX_ACCOUNT_LENGTH* sizeof(char));
    do
    {
        flag1=0,flag2=0;
        printf("%s",printvalue);
        scanf("%s", accountNumber);
        getchar();
        while(!checkNumber(accountNumber))
        {
            printf("%s",printvalue);
            scanf("%s", accountNumber);
            getchar();
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
        if (flag1)
        {
            printf("Error: Account Number already exist\n");
        }
        if(strlen(accountNumber)!=10)
        {
            printf("Error: Account Number must consist of 10 numbers\n");
            flag2=1;
        }
    }
    while (flag1||flag2);
    return accountNumber;
}
int checkName(char*name,int i)
{
    if(name[i]>='a'&& name[i]<= 'z'||(name[i] >='A'&& name[i] <='Z'))
        return 1;
    else return 0;
}
char* validationName()
{
    int flag,countSpace=0;
    char* name = (char*)malloc(100* sizeof(char));
    do
    {
        countSpace=0;
        printf("Enter your name: ");
        gets(name);
        for (int i=0; i<strlen(name); i++)
        {
            flag = 1;
            if (!(checkName(name,i)||(name[i] == ' ')))
            {
                printf("Error: Name must only consist of characters\n");
                flag = 0;
                break;
            }
            if(name[i]==' '&&checkName(name,i+1))
            {
                countSpace++;
            }
        }
        if(countSpace<1)
        {
            printf("Error: Name must consist of first name and last name\n");
        }
    }
    while (!flag||countSpace<1);
    return name;
}
char* validateEmail()
{
    char* email = (char*)malloc(100* sizeof(char));
    int flag_mail=0,flag=0,i,j;
    do
    {
        flag_mail=0,flag=0;
        printf("Please enter your email: ");
        scanf("%s",email);
        getchar();
        for (i = 0; email[i] != '\0'; i++)
        {
            if (email[i] == '@')
            {
                flag_mail = 1;
                for(j=i-1; email[j]!='\0'; j++)
                {
                    if(email[j]=='.')
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }

        if (!flag_mail)
        {
            printf("Error: Email must contain @\n");
        }
        if(!flag)
        {
            printf("Error: Email must contain . after @\n");
        }
    }
    while (!flag_mail||!flag);
    return email;
}
char* validateBalance()
{
    char* balance = (char*)malloc(100* sizeof(char));
    do
    {
        printf("Enter your balance: ");
        scanf("%s", balance);
        getchar();
    }
    while (!checkNumber(balance));
    return balance;
}
char* validateMobile()
{
    char* mobileNumber = (char*)malloc(15* sizeof(char));
    int flag=0;
    do
    {
        flag=0;
        printf("Enter the mobile number: ");
        scanf("%s", mobileNumber);
        getchar();
        while(!checkNumber(mobileNumber))
        {
            printf("Enter the mobile number: ");
            scanf("%s", mobileNumber);
            getchar();
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
int validateBalanceExistance(char *balance,int i)
{
    if(atof(balance)>accounts[i].balance)
    {
        printf("Error: You don't have enough balance\nYour balance: %f\n",accounts[i].balance);
        return 0;
    }
    else return 1;
}
int validateBalance100000(char* balance)
{
    if(atof(balance)>10000.0)
    {
        printf("Error: Max limit per transaction is $10,000\n");
        return 0;
    }
    else return 1;
}
void add()
{
    char printvalue[]="Enter account number: ";
    count++;
    int i=count;
    strcpy(accounts[i].account_no,validateDuplication(printvalue,i));
    strcpy(accounts[i].name,validationName());
    strcpy(accounts[i].mobile,validateMobile());
    strcpy(accounts[i].mail,validateEmail());
    accounts[i].balance=atof(validateBalance());

    time_t t;
    time(&t);
    struct tm *tm_info = localtime(&t);

    accounts[i].d_open.month = tm_info->tm_mon + 1;
    accounts[i].d_open.year = tm_info->tm_year + 1900;
    char filename[30] ;
    sprintf(filename,"%s.txt",accounts[count].account_no);
    FILE *file1=fopen(filename, "w");
    if (file1 == NULL)
    {
        printf("Error opening file\n");
        exit(-1);
    }
    fclose(file1);
    if(!askSave()) return;
    printer(accounts[i]);
}

void DEPOSIT()
{
    int i;
    char printvalue[]="Enter the account number: ";
    char accountNumber[MAX_ACCOUNT_LENGTH];
    char temp[MAX_ACCOUNT_LENGTH];
    strcpy(temp,validateAccountNumber(printvalue,&i));
    if(!atoi(temp)) return;
    strcpy(accounts[i].account_no,temp);
    char  depositAmount[100];
    do
    {
        strcpy(depositAmount,validateBalance());
    }
    while(!validateBalance100000(depositAmount));
    if(!askSave()) return;
    accounts[i].balance+=atof(depositAmount);
    printf("Deposit successful\nNew balance: %f\n",accounts[i].balance);
    double deposit=atof(depositAmount);
    FILE* file = fopen(strcat(accountNumber,".txt"), "a");
    if (file == NULL)
    {
        printf("Error opening file");
    }
    fprintf(file, "Depositted amount to the account: %f New balance: %f\n", deposit,accounts[i].balance);
    fclose(file);
}
void TRANSFER()
{
    int i,j;
    char printvalue1[]="Enter the account number to transfer money from: ";
    char accountNumber1[MAX_ACCOUNT_LENGTH];
    char temp1[MAX_ACCOUNT_LENGTH];
    strcpy(temp1,validateAccountNumber(printvalue1,&i));
    if(!atoi(temp1)) return;
    strcpy(accounts[i].account_no,temp1);
    char printvalue2[]="Enter the account number to transfer money to: ";
    char accountNumber2[MAX_ACCOUNT_LENGTH];
    char temp2[MAX_ACCOUNT_LENGTH];
    strcpy(temp2,validateAccountNumber(printvalue2,&j));
    if(!atoi(temp2)) return;
    strcpy(accounts[i].account_no,temp2);
    while(atof(accountNumber1)==atof(accountNumber2))
    {
        printf("Error: You can't transfer money to the same account\n");
        strcpy(temp2,validateAccountNumber(printvalue2,&j));
        if(!atoi(temp2)) return;
        strcpy(accounts[i].account_no,temp2);
    }
    char  transferAmount[100];
    do
    {
        strcpy(transferAmount,validateBalance());
    }
    while(!validateBalance100000(transferAmount)||!validateBalanceExistance(transferAmount,i));
    if(!askSave()) return;
    accounts[i].balance-=atof(transferAmount);
    accounts[j].balance+=atof(transferAmount);  // Update the balances of the source and destination accounts
    printf("Transfer Successful\nNew balance of The source account: %f\nNew balance of The destination account: %f\n",accounts[i].balance,accounts[j].balance);
    double transfer=atof(transferAmount);
    FILE* file1 = fopen(strcat(accountNumber1,".txt"), "a");
    if (file1 == NULL)
    {
        printf("Error opening file");
    }
    fprintf(file1, "Transferred amount from the account: %f New Balance: %f\n",transfer,accounts[i].balance);
    FILE* file2 = fopen(strcat(accountNumber2,".txt"), "a");
    if (file2 == NULL)
    {
        printf("Error opening file");
    }

    fprintf(file2, "Transferred amount to the account: %f New Balance: %f\n",transfer,accounts[j].balance);
    fclose(file1);
    fclose(file2);
}
int WITHDRAW()
{
    int i;
    char printvalue[]="Enter the account number: ";
    char accountNumber[MAX_ACCOUNT_LENGTH];
    char temp[MAX_ACCOUNT_LENGTH];
    strcpy(temp,validateAccountNumber(printvalue,&i));
    if(!atoi(temp)) return;
    strcpy(accounts[i].account_no,temp);
    char  withdrawnAmount[100];
    do
    {
        strcpy(withdrawnAmount,validateBalance());
    }
    while(!validateBalance100000(withdrawnAmount)||!validateBalanceExistance(withdrawnAmount,i));
    if(!askSave()) return;
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
}
void advancedSearch()
{
    int i,j,k,keylen,namelen,check1,check2,good = 0,matchedlen = -1,hold ;
    char keyword[MAX_Keyword] = {};
    user matched[MAX_ACCOUNTS];
    printf("Enter Keyword: ");
    gets(keyword);
    keylen = strlen(keyword);
    for(i = 0; i < count ; i++)
    {
        good = 0;
        namelen = strlen(accounts[i].name);
        for(j = 0 ; j < namelen  ; j++  )
        {
            good = 0;

            check1 = (accounts[i].name[j] == keyword[0] || (accounts[i].name[j] + 32) == keyword[0] || (accounts[i].name[j] - 32) == keyword[0]); //capital check
            if(check1)
            {
                good = 0;

                for(k = j ; k-j <= keylen ; k++ )
                {
                    if(isspace(accounts[i].name[k]))
                    {
                        k++; //to jump the space
                        j++; //to keep the original k-j
                    }
                    check2 = (accounts[i].name[k] == keyword[k-j] || (accounts[i].name[k] + 32) == keyword[k-j] || (accounts[i].name[k] - 32) == keyword[k-j])  ;

                    if(check2)
                    {
                        good++; //used to check that all consecutive matched letters are = the length of the original keyword
                    }
                    if(good == keylen && hold != i) //hold used here because the same name could have several instances of the same keyword while is should be stored only once
                    {
                        hold = i;
                        matchedlen++;
                        matched[matchedlen] = accounts[i];
                    }
                }
            }
        }
    }

    printf("\n\nSearch results:\n\n");
    if(matchedlen != -1)
    {
        for(i = 0 ; i <= matchedlen ; i ++)
        {
            printer(matched[i]);
            printf("\n");
        }
    }
    else
    {
        printf("Keyword not found\n");
    }
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
void printer(user a)
{
    printf("Account number: %s\n",a.account_no);
    printf("Name: %s\n",a.name);
    printf("E-mail: %s\n",a.mail);
    printf("Balance: %.2lf $\n",a.balance);
    printf("Mobile: %s\n",a.mobile);
    printf("Date Opened: %s %d\n",monthName(a.d_open.month),a.d_open.year);
}

void sortByName(user *a, int z)
{
    int i,j, flag = 1,type;
    if(z == 1)
    {
        type = 1;
    }
    else
    {
        type = -1;
    }
    user x;
    for(i = 0 ; i < count-1; i++)
    {
        if(flag == 0) break;
        flag = 0;
        for(j = 0 ; j < count - i -1 ; j++)
        {

            if(strcmp((a+ j)-> name, (a+ j +1)-> name ) == type)
            {
                x =  (*(a+ j));
                (*(a + j)) = (*(a+ j +1));
                (*(a+ j +1)) = x;
                flag = 1;
            }
        }
    }
}

void sortByBalance(user *a,int z)
{
    int i,j, flag = 1;
    user x;
    for(i = 0 ; i < count-1; i++)
    {
        if(flag == 0) break;
        flag = 0;
        for(j = 0 ; j < count - i -1 ; j++)
        {
            if(z == 1)
            {


                if((a+ j)-> balance < (a+ j +1)-> balance)
                {
                    x =  (*(a+ j));
                    (*(a + j)) = (*(a+ j +1));
                    (*(a+ j +1)) = x;
                    flag = 1;
                }
            }
            else
            {
                if((a+ j)-> balance > (a+ j +1)-> balance)
                {
                    x =  (*(a+ j));
                    (*(a + j)) = (*(a+ j +1));
                    (*(a+ j +1)) = x;
                    flag = 1;
                }
            }
        }
    }
}

int dateCmp(date a, date b)
{
    if(a.year > b.year ) return 1;
    if(a.year < b.year ) return -1;
    if(a.year == b.year)
    {
        if(a.month > b.month ) return 1;
        if(a.month < b.month ) return -1;
        if(a.month == b.month ) return 0;
    }

}
void sortByDate(user *a,int z)
{
    int i,j, flag = 1,type;
    if(z == 1)
    {
        type = 1;
    }
    else
    {
        type = -1;
    }
    user x;
    for(i = 0 ; i < count-1; i++)
    {
        if(flag == 0) break;
        flag = 0;
        for(j = 0 ; j < count - i -1 ; j++)
        {

            if(dateCmp((a+ j)-> d_open,(a+ j +1)-> d_open) == type)
            {
                x =  (*(a+ j));
                (*(a + j)) = (*(a+ j +1));
                (*(a+ j +1)) = x;
                flag = 1;
            }
        }
    }
}

void print()
{
    user sorted[MAX_ACCOUNTS] ;
    int i,way,type;
    for(i=0 ; i < count ; i++)
    {
        sorted[i] = accounts[i]; //array to change it,s order without changing the original array
    }
    printf("How would you like the accounts to be sorted?\n");
    printf("1) By name\n2) By Balance\n3) By date opened\n");
    do
    {
        scanf("%d",&way);
        if(!(way>0 && way<4)) printf("Please enter number from 1 to 3!\n");
    }
    while(!(way>0 && way<4));
    switch(way)
    {
    case 1:
        printf("Please choose the type:\n");
        printf("1) A-Z\n2) Z-A\n");
        do
        {
            scanf("%d",&type);
            if(!(type>0 && type<3)) printf("Please enter number from 1 to 2!\n");
        }
        while(!(type>0 && type<3));
        sortByName(sorted,type);
        break;
    case 2:
        printf("Please choose the type:\n");
        printf("1) Highest to Lowest\n2) Lowest to Highest\n");
        do
        {
            scanf("%d",&type);
            if(!(type>0 && type<3)) printf("Please enter number from 1 to 2!\n");
        }
        while(!(type>0 && type<3));
        sortByBalance(sorted,type);
        break;
    case 3:
        printf("Please choose the type:\n");
        printf("1) Old to New\n2) New to Old\n");
        do
        {
            scanf("%d",&type);
            if(!(type>0 && type<3)) printf("Please enter number from 1 to 2!\n");
        }
        while(!(type>0 && type<3));
        sortByDate(sorted,type);
        break;


    }
    printf("\n\n");
    for(i=0 ; i < count ; i++) //print sorted array
    {
        printer(sorted[i]);
        printf("\n");
    }

}
void QUERY()
{
    char accountNumber[MAX_ACCOUNT_LENGTH];
    int flag=0;
    do
    {
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
                printer(accounts[i]);
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
void deleteacc()
{
    int i,flag=0;
    char printvalue[]="Enter account number: ";

    strcpy(accounts[i].account_no,validateAccountNumber(printvalue,&i));

    if(accounts[i].balance!=0)
    {
        printf("Balance not equal to zero, Account cannot be deleted\n");
        flag=1;
    }
    if(!flag)
    {
        askSave();
        for( i; i<count-1; i++)
        {
            accounts[i]=accounts[i+1];
        }
        count--;
        printf("The account has been deleted\n");
        save();
    }
}

void modify ()
{
    int i;
    char printvalue[]="Enter account number: ";
    strcpy(accounts[i].account_no,validateAccountNumber(printvalue,&i));
    int flag=1;
    printer(accounts[i]);
    do
    {
        printf("What do you want to modify\n1)Name\n2)Mobile\n3)Email\n4)Return to Menu\n");
        char choice[30];
        scanf("%s", choice);
        getchar();
        switch (atoi(choice))
        {

        case 1:
        {

            strcpy(accounts[i].name,validationName());
            if(!askSave()) return;
            printer(accounts[i]);
            break;
        }

        case 2:
        {

            strcpy(accounts[i].mobile,validateMobile());
            if(!askSave()) return;
            printer(accounts[i]);
            break;
        }

        case 3:
        {
            strcpy(accounts[i].mail,validateEmail());
            if(!askSave()) return;
            printer(accounts[i]);

            break;
        }
        case 4:
            return;

        default:
        {
            printf("The Number you entered is not in range\n");
            flag = 0;
        }
        }
    }
    while(!flag);
}
void report ()
{
    int i;
    char printvalue[]="Enter account number: ";

    strcpy(accounts[i].account_no,validateAccountNumber(printvalue,&i));

    char filename[30];
    sprintf(filename,"%s.txt",accounts[i].account_no);


    FILE*file=fopen(filename,"r");

    if (file== NULL)
    {
        printf("Error opening file 'accounts.txt'\n");
        exit(-1);
    }

    int no_line=0;
    char buffer[MAX_LINES][MAX_LEN];
    while(!feof(file))
        if(fgets(buffer[no_line],MAX_LEN,file)!=NULL)no_line++;

    if(no_line>=5)
    {
        for(int i=0; i<5; i++)
        {
            printf("%s\n",buffer[no_line-i-1]);
        }
    }
    else
    {
        for(int i=0; i<no_line; i++)
        {
            printf("%s\n",buffer[no_line-i-1]);
        }
    }

    fclose(file);
}
int save()
{
    const char* filename="accounts.txt";
    int i ;
    FILE* file = fopen(filename, "w+");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    for(i=0; i<count; i++)
    {

        fprintf(file,"%s,%s,%s,%0.2f,%s,%d-%d \n",accounts[i].account_no,accounts[i].name,accounts[i].mail,accounts[i].balance,accounts[i].mobile,accounts[i].d_open.month,accounts[i].d_open.year);

    }
    printf("\nSaved Successfully\n");
    fclose(file);
}
int askMenu()
{
    char choice[30];
    printf("What do you want\n1)Continue\n2)Return to Menu\n");
    scanf("%s",choice);
    getchar();
    switch(atoi(choice))
    {
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        printf("The Number you entered is not in range\nTry Again\n");
        askMenu();
    }
}
int askSave()
{
    char choice[30];
    printf("Do you want to save the changes?\n1)Yes\t2)No\n");
    scanf("%s",choice);
    getchar();

    switch(atoi(choice))
    {
    case 1:
        save();
        break;
    case 2:
        return 0;
        break;
    case 3:
        printf("The Number you entered is not in range\nTry Again");
        askSave();
    }

}

int flag_login = 0;
void MENU()
{
    char n[30];
    system("cls");

    do
    {
        printf("Enter (1 or 2)\n1.LOGIN\n2.QUIT\n");
        scanf("%s", n);
        fflush(stdin);
        if(atoi(n)!=1&&atoi(n)!=2)
            printf("The Number you entered is not in range\nTRY AGAIN\n");
        if (atoi(n) == 2) quit(1);
        if (atoi(n) == 1 && login() == 1)  flag_login++;

    }
    while (!flag_login);

    do
    {

        printf("Enter a number from (1 to 12)\n1.ADD\n2.DELETE\n3.MODIFY\n4.WITHDRAW\n5.TRANSFER\n6.DEPOSIT\n7.REPORT\n8.QUERY\n9.ADVANCED SEARCH\n10.PRINT\n11.SAVE\n12.QUIT\n");
        scanf("%s", n);
        fflush(stdin);
        switch (atoi(n))
        {
        case 1:
            add();
            break;
        case 2:
            deleteacc();
            break;
        case 3:
            modify();
            break;
        case 4:
            WITHDRAW();
            break;
        case 5:
            TRANSFER();
            break;
        case 6:
            DEPOSIT();
            break;
        case 7:
            report();
            break;
        case 8:
            QUERY();
            break;
        case 9:
            advancedSearch();
            break;
        case 10:
            print();
            break;
        case 11:
            save();
            break;
        case 12:
            quit(2);
            break;
        default:
            printf("The Number you entered is not in range\nTRY AGAIN\n");
        }
    }
    while(1);
}
int main()
{
    MENU();
    return 0;
}
