#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_ACCOUNTS        100
#define MAX_Keyword         50

typedef struct
{
    int month;
    int year;
} date;
typedef struct
{
    char account_no[12];
    char name[100];
    char mail[100];
    double balance;
    char mobile[15];
    date d_open;
} user;

user accounts[MAX_ACCOUNTS];        //accounts data
int count = 0;                      //accounts number

void loadAccounts()
{
    const char* filename="accounts.txt";
    FILE* file = fopen(filename, "r");
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
        hold = -i; //just for safety because hold can have a random value = i and ruin some if conditions
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
        printf("keyword not found\n");
    }
}

void save()
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
    printf("\nsaved succesfully\n");
    fclose(file);
}
void quit()
{
    printf("Are you sure thet you want to exit?\n1)yes                  2)no\n");
    int val;
    do
    {
        scanf("%d",&val);
        scanf("%c"); // to store the extra space to prevent messing up any gets() function in the code
        if(val==1)
            exit(1);
        if(val == 2)
            main();
        else
            printf("Please enter number from 1 to 2!\n");
    }
    while(!(val>0 && val<3));

}

int main()
{
    int i;
    loadAccounts();
    advancedSearch();
    save();
    quit();
    return 0;
}
