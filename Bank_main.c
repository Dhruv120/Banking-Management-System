#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


void insert_record();
void display_record();
void search_record();
void delete_record();
void check_balance();
void transactions();
void currency_convertor();
void interest_calculator();
void term_condition();


struct bank
{
    int account_no;
    char name[50];
    char lname[50];
    long long int mobile_no ;
    long long int balance ;
    int amt;
    char city[20];
}transaction;
struct bank b;



void main()
{
    printf("\t\t\t\t\t    |||||||||     |||||||||\n");
    printf("\t\t\t\t\t    |||||||||     |||||||||\n");
    printf("\t\t\t\t\t    ||||               ||||\n");
    printf("\t\t\t\t\t    ||||   *********   ||||\n");
    printf("\t\t\t\t\t           *********         \n");
    printf("\t\t\t\t\t           *********         \n");
    printf("\t\t\t\t\t    ||||   *********   ||||\n");
    printf("\t\t\t\t\t    ||||               ||||\n"); 
    printf("\t\t\t\t\t    |||||||||     |||||||||\n");
    printf("\t\t\t\t\t    |||||||||     |||||||||\n");
    printf("\n");
    printf("\t\t\t\t * * * * * * WELCOME TO HDFC BANK * * * * * *\n");
    printf("\n");
    printf("\t\t\t\t\t \" We understand your world \"\n\n");
   
    printf("\n");
    int ch;
    while(ch!=0)
    {
    printf("|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|--|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|\n");
    printf("\nSelect your Preference from below options\n");
    printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __\n");
    printf("|                                                    |\n");
    printf("|  1  - Create a New Account                         |\n");
    printf("|  2  - Display record of all Customers              |\n");
    printf("|  3  - Search Your Details                          |\n");
    printf("|  4  - Delete Your Account                          |\n");
    printf("|  5  - Make transaction (Deposit / Withdraw)        |\n");
    printf("|  6  - Check Your Balance                           |\n");
    printf("|  7  - Currency Convertor                           |\n");
    printf("|  8  - Interest Calculator                          |\n");
    printf("|  9  - Term & Condition                             |\n");
    printf("|  10 - Exit                                         |\n");
    printf("| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n");
    printf("\nEnter your choice :");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 : insert_record();
                break;
        case 2 : display_record();
                break;  
        case 3 : search_record();
                break;
        case 4 : delete_record();
                break;             
        case 5 : transactions();
                break;
        case 6 : check_balance();
                break;   
        case 7: currency_convertor();
                break; 
        case 9: term_condition();
                break;              
        case 8: interest_calculator();
                break;
        case 10: exit(0);
                break;        
        default : printf("Wrong choice");                       

    }
    printf("\nPress any key to continue\n");
    getch();
    }
}



void insert_record()
{
   FILE*fp;
   char ch = 'y';
   fp =fopen("record.txt","a");
   if(fp==NULL)
   {
       printf("Cannot open");
   }
    while(ch=='y')
        {
            
            printf("\nEnter your details :\n\n");
            printf("Enter Account number  :");
            scanf("%d",&b.account_no);
            printf("Enter Name            :");
            scanf("%s",b.name);
            printf("Enter Last Name       :");
            scanf("%s",b.lname);
            printf("Enter Mobile No.      :");
            scanf("%lld",&b.mobile_no);
            printf("Enter City            :");
            scanf("%s",b.city);
            printf("Opening Balance       :");
            scanf("%lld",&b.balance);
            printf("\n");
            fprintf(fp,"%d\t %s\t %s\t %lld\t %s\t %lld\n",b.account_no,b.name,b.lname,b.mobile_no,b.city,b.balance);
            printf ("\nPress Y to create New account and any key to go to home page :");
            ch = getch();
        }
    fclose(fp);
   
}

void display_record()
{
    FILE*fp;
    fp = fopen("record.txt","r");

    if(fp==NULL)
    {
        printf("file not found");
        return ;
    }

    printf("\nBank Account holder's Detail are as follow \n");
    printf("\nACCOUNT_NO\t NAME\t\tSURNAME\t \tMOBILE_NO.\t\tCITY\t  CLOSING_BALANCE\n\n");

    while(fscanf(fp,"%d\t %s\t %s\t %lld\t %s\t %lld",&b.account_no,b.name,b.lname,&b.mobile_no,b.city,&b.balance)!=EOF)
    {
        printf("%d\t\t%s\t\t%s\t\t%lld\t\t%s\t\t%lld\n",b.account_no,b.name,b.lname,b.mobile_no,b.city,b.balance);
    }
    fclose(fp);
    getch();
}

void search_record()
{
    int acc ,flag =0;
    FILE*fp;
    fp = fopen("record.txt","r");

    if(fp==NULL)
    {
        printf("file not found");
        return ;
    }
    printf("\nEnter Account number :");
    scanf("%d",&acc);

    while(fscanf(fp,"%d\t %s\t %s\t %lld\t %s\t %lld",&b.account_no,b.name,b.lname,&b.mobile_no,b.city,&b.balance)!=EOF)
    {
    if(b.account_no == acc)
        {
                flag =1;
                printf("\nYour Search is Sucessfull \n");
                printf("\nDetails are As shown below\n\n");
                printf("Name of Customer          : %s\n",b.name);
                printf("Last Name of Customer     : %s\n",b.lname);
                printf("Mobile Number             : %lld\n",b.mobile_no);
                printf("City                      : %s\n",b.city);
                printf("Current Balance           : %lld\n",b.balance);
         }
    }
    if(flag==0)
    {
        printf("No such record found");
    }
    
fclose(fp);
}


void delete_record()
{
    int acc;
    FILE*fp,*ft;
    fp = fopen("record.txt","r");
    printf("Enter Account number :");
    scanf("%d",&acc);
    int test =0;
     if(fp==NULL)
    {
        printf("file not found");
        return ;
    }

    ft = fopen("newrecord.txt","a");
    while(fscanf(fp,"%d\t %s\t %s\t %lld\t %s\t %lld",&b.account_no,b.name,b.lname,&b.mobile_no,b.city,&b.balance)!=EOF)
    {
        if(b.account_no == acc)
        {
                test++;
            printf("Your Account is Deleted Successfully");
        }
        else
        {
            fprintf(ft,"%d\t %s\t %s\t %lld\t %s\t %lld\n",b.account_no,b.name,b.lname,b.mobile_no,b.city,b.balance);

        }
        
    }
    if(test==0)
    {
        printf("Record not found");
    }
  fclose(fp);
   fclose(ft);
   remove("record.txt");
   rename("newrecord.txt","record.txt");

}

void check_balance()
{
    int acc ,flag =0;
    FILE*fp;
    fp = fopen("record.txt","r");

    if(fp==NULL)
    {
        printf("file not found");
        return ;
    }
    printf("Enter Account number :");
    scanf("%d",&acc);

    while(fscanf(fp,"%d\t %s\t %s\t %lld\t %s\t %lld",&b.account_no,b.name,b.lname,&b.mobile_no,b.city,&b.balance)!=EOF)
    {
    if(b.account_no == acc)
        {
                flag =1;
                printf("Your Current Balance  : %lld\n",b.balance);
         }
    }
    if(flag==0)
    {
        printf("No such record found");
    }
    
fclose(fp);
}
void transactions()
{
    int choice, test = 0;
    FILE *old, *newrec;
    int acc, n, amt;
    old = fopen("record.txt", "r");
    newrec = fopen("newrecord.txt", "w");

    printf("Enter the account no. of the customer:");
    scanf("%d", &transaction.account_no);

    printf("\nEnter your choice:\n");
    printf("1 - Deposit Money\n");
    printf("2 - Withdraw Money\n");
    printf("3 - exit\n");
    printf("> ");
    scanf("%d", &choice);

    while (fscanf(old, "%d\t %s\t %s\t %lld\t %s\t %lld", &b.account_no, b.name, b.lname, &b.mobile_no, b.city, &b.balance) != EOF)
    {
        if (b.account_no == transaction.account_no)
        {
            test = 1;
            if (choice == 1)
            {
                printf("\nEnter the amount you want to deposit: ");
                scanf("%lld", &transaction.balance);
                b.balance += transaction.balance;
                fprintf(newrec, "%d\t %s\t %s\t %lld\t %s\t %lld\n", b.account_no, b.name, b.lname, b.mobile_no, b.city, b.balance);
                printf("\n\nDeposited successfully!");
            }
            else if (choice == 2)
            {
                printf("\nEnter the amount you want to withdraw: ");
                scanf("%lld", &transaction.balance);
                b.balance -= transaction.balance;
                fprintf(newrec, "%d\t %s\t %s\t %lld\t %s\t %lld\n", b.account_no, b.name, b.lname, b.mobile_no, b.city, b.balance);
                printf("\n\nWithdrawn successfully!");
            }
            else if (choice == 3)
            {
                exit(0);
            }
        }
        else
        {
            fprintf(newrec, "%d\t %s\t %s\t %lld\t %s\t %lld\n", b.account_no, b.name, b.lname, b.mobile_no, b.city, b.balance);
        }
    }

    if (test == 0)
    {
        printf("No record found");
    }

    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("newrecord.txt", "record.txt");
}


void currency_convertor()
{
    float ans,ans1,ru;
	int ch;

        printf("\n 1. Rupees -> Doller");
		printf("\n 2. Doller -> Rupees");
		printf("\n 3. Exit");
        printf("\nEnter your choice :- ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:printf("\nEnter the currency in Rupees : ");
				scanf("%f",&ru);
				ans=ru/72.92;
				printf("\nThe currency is doller is= %.2f$",ans);
				break;
			case 2:printf("\nEnter the currency in Doller :");
				scanf("%f",&ru);
				ans1=ru*72.92;
				printf("\nThe currency in Rupees is= %.2f",ans1);
				break;
			case 3:exit(0);
        }
	
}


void term_condition()
{
    printf("\n\t\t\t\t *** TERMS & CONDITIONS ***\n");
    printf("\n1 - Customer must maintain Minimum balance of Rs.1000 .\n\n");
    printf("2 - If Customer is Making a cash deposit of more than Rs.49000 , then Pan Card is required .\n\n");
    printf("3 - Customer should provide all correct information while creating new account .\n\n");
    printf("4 - Interest Amount will be credited in your bank account quaterly .\n\n");
    printf("5 - For any query contact to your nearest branch .\n");
}


void interest_calculator()
{
    printf("Select your choice :\n\n");
    printf("  1 - Saving account\n");
    printf("  2 - Current Account\n");
    printf("  3 - FD ( Fixed Deposite )\n");
    printf("  4 - RD ( Recurring Deposit )\n");

    int choice;
    printf("\nEnter your choice :");
    scanf("%d",&choice);

    int amount;
    printf("\nEnter principle amount :");
    scanf("%d",&amount);
    int duration;
    printf("\nEnter duration (In months) :");
    scanf("%d",&duration);
    int rate;
    if(choice==1)
    {
        rate =6;
    }
    else if(choice ==0)
    {
        rate =0;
    }
    else if(choice==3)
    {
        rate = 10;
    }
    else
    {
        rate =15;
    }

    float interest ;
    interest = amount*rate*duration*0.01;

    printf("Your Interest Amount will be : %f",interest);
    
}