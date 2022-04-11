/*
==================================================
Assignment #1 Milestone #3:
==================================================
Name : Tanishq Talreja
ID : 126460203
Email : ttalreja@myseneca.ca
Section : NCC
*/

#define _CRT_SECURE_NO_WARNINGS
//I/O lib
#include <stdio.h>
//for structure passsing
#include"account.h"
//MAIN CODE STARTS FROM HERE ->->->->

//pause exec.
// Pause execution until user enters the enter key
void pauseExecution(void)
{
	printf("<< ENTER key to Continue... >>");
	clearStandardInputBuffer();
	putchar('\n');
}


//F1 to display header for summ

void  displayAccountSummaryHeader(void)
{
	printf("\nAcct# Acct.Type Birth\n");
	printf("----- --------- -----\n");
}

//F2 display header for the whole data
void displayAccountDetailHeader(void)
{
	//  formatting 
	printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
	printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");
}

//F3 to display the data for the summ up

void displayAccountSummaryRecord(const struct Account *account)
{
	//print statment

	printf("%05d %-9s %5d\n",account->accountnum, account->user == 'A' ? "AGENT" : "CUSTOMER",
							account->demographic.birthyear);
}

//F4 display the whole data

void displayAccountDetailRecord(const struct Account* account)
{
	int i;
	//print statements
	printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s ", account->accountnum,
		account->user == 'A' ? "AGENT" : "CUSTOMER",
		account->demographic.birthyear,account->demographic.houseincome,account->demographic.country,
		account->userlogin.dispname,account->userlogin.name);

	//print loop for password
	for ( i = 0; account->userlogin.password[i] != '\0'; i++)
	{
		if (i % 2 == 1)
		{
			putchar('*');
		}
		else
		{
			printf("%c",account->userlogin.password[i]);
			
		}
	}
	putchar('\n');


}


//func to display the summary of records

void displayAllAccountSummaryRecords(const struct Account acc[], int size)
{
	int i;
	displayAccountSummaryHeader();
	for (i = 0; i < size ; i++) //loop till i<size and the array of accountnum is > 0
	{	//passing the array element by element to the funct
		
		if (acc[i].accountnum==0)
		{
			//do nothing
		}
		else
		{
			displayAccountSummaryRecord(&acc[i]);
		}
	}
	putchar('\n');
	pauseExecution();


}
//F5 display the detailed rec
void displayAllAccountDetailRecords(const struct Account acc[], int size)
{
	int i;
	displayAccountDetailHeader();
	for (i = 0; i < size; i++) //loop till i<size and the array of accountnum is > 0
	{
		if (acc[i].accountnum == 0)
		{
			//do nothing
		}
		else
		{
			displayAccountDetailRecord(&acc[i]);
		}//passing the array element by element to the funct
		
	}
	putchar('\n');
	pauseExecution();

}


//MILESTONE 4 Starts


void menuAgent(struct Account acc[], int size, const struct Account* accounts)
{
	//vars
	int selection, j, found = 0, accountnumber, position, search=-1;
	char delete;
	int addacount;

	do
	{
		//display name of agent
		printf("\nAGENT: %s (%05d)", accounts->userlogin.dispname, accounts->accountnum);
		//display menu option
		printf("\n==============================================");
		printf("\nAccount Ticketing System - Agent Menu");
		printf("\n==============================================");
		printf("\n1) Add a new account");
		printf("\n2) Modify an existing account");
		printf("\n3) Remove an account");
		printf("\n4) List accounts : summary view");
		printf("\n5) List accounts : detailed view");
		printf("\n----------------------------------------------");
		printf("\n0) Logout\n");
		printf("\nSelection: ");
		//input and clearing buffer
		selection = getIntFromRange(0, 5);

		//switch case for menu
		switch (selection)
		{
		case 0:
			printf("\n### LOGGED OUT ###\n\n");
			//do nothing
			break;
		case 1:
			//logic for adding new account
			//binary search for acct num =0
			for (j = 0; j < size && found == 0; j++)
			{
				if (acc[j].accountnum == 0)
				{
					addacount = j;
					found = 1;
				}
			}
			if (found == 0)
			{
				printf("\nERROR: Account listing is FULL, call ITS Support!");
			}
			else
			{
				putchar('\n');
				getAccount(&acc[addacount]);
				getUserLogin(&acc[addacount].userlogin);
				getDemographic(&acc[addacount].demographic);
			}
			printf("\n*** New account added! ***\n");
			putchar('\n');
			pauseExecution();
			found = 0;

			break;
		case 2:
			//logic to update account and if not valid acctnum display error msg
			search = findAccountIndexByAcctNum(search, acc, size, 1);
			//display error if !found
			if (search == -1)
			{
				printf("\n Error : Match not found!");
			}
			else
			{
				updateAccount(&acc[search]);
			}
			break;
		case 3:
			//input acc num and search for it
			printf("\nEnter the account#: ");
			accountnumber = getPositiveInteger();
			//binary search
			if (accounts->accountnum == accountnumber)
			{
				printf("\nERROR: You can't remove your own account!\n");
			}
			else if (accounts->accountnum != accountnumber)
			{
				search = findAccountIndexByAcctNum(accountnumber, acc, size, 0);
				
				if (search == -1)
				{
					printf("\n Error : Match not found!");
				}
				else
				{

					displayAccountDetailHeader();
					displayAccountDetailRecord(&acc[search]);

					printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
					delete = getCharOption("YN");
					if (delete == 'N')
					{
						printf("\n*** No changes made! ***");
					}

					else
					{
						acc[search].accountnum = 0; //set acctnum =0
						printf("\n *** Account Removed! ***\n");
					}
				}
			}
			//if record found display header and ask for deletion
			break;

		case 4:
			displayAllAccountSummaryRecords(acc, size);
			break;

		case 5:
			displayAllAccountDetailRecords(acc, size);
			break;

		default:
			printf("Error!  invalid selection!\n\n");
			break;
		}
	} while (selection);
	
}

//F1 for app start
void applicationStartup(struct Account account[], int size)
{
	int position,flag=0;
	do
	{
		
		position = menuLogin(account, size);

		if (position < 0)
		{
			printf("==============================================");
			printf("\nAccount Ticketing System - Terminated");
			printf("\n==============================================\n");
			flag = 1;
		}

		if (position >= 0)
		{


			if (account[position].user == 'C')
			{
				printf("\nCUSTOMER: home menu currently unavailable...\n");
				putchar('\n');
				pauseExecution();
			}

			else
			{
				menuAgent(account, size, &account[position]);
				
			}

		}
		
	} while (flag==0);
	
	
	
	
}

//F2 for  menu login

int menuLogin(const struct Account acc[], int size)
{
	//vars 
	int selection=0, search=0, position=0;
	int found = 0;
	char input;
	do
	{
		//Display login menu
		printf("==============================================\n");
		printf("Account Ticketing System - Login\n");
		printf("==============================================\n");
		printf("1) Login to the system\n");
		printf("0) Exit application\n");
		printf("----------------------------------------------\n\n");
		printf("Selection: ");

		// call commonhelpers function for range thing
		selection = getIntFromRange(0, 1);

		//if returned selection =1 then ask for acct num.

		if (selection == 1)
		{	
			printf("\nEnter your account#: ");
			scanf("%d", &search);
			search = findAccountIndexByAcctNum(search,acc,size,0);
			if (search ==-1)
			{
				printf("\nERROR: Access Denied.\n");
				putchar('\n');
				pauseExecution();
				putchar('\n');
				
			}
			else
			{
				position=search;
				selection = -1;
			}
		}
		//if user selects 0 then it will return -1
		else if (selection==0)
		{
			printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
			input = getCharOption("YyNn");
			if (input=='Y' || input == 'y')
			{
				position = -1;
				selection = -1;

			}
			else
			{
				selection = 0;
			}
		}
		
		//loops exit when found=1 or selection =0
	} while (selection>=0);
	
	return position;
}

//F3 for menu of agent
//accounts is for the agent that has logged in


//F4 search function
int findAccountIndexByAcctNum(int accountnum,const struct Account acc[],int size,int input)
{
	int  i, find = 0, addr=0;
	if (input==1)
	{
		printf("\nEnter your account#: ");
		accountnum = getPositiveInteger();

		//binary search loop for find of acc num
		for (i = 0; i < size && find==0 ; i++)
		{
			if (accountnum == acc[i].accountnum)
			{
				addr = i;
				find = 1;
				
			}
		}
		 if (find == 0)
		 {	
			 addr = -1;
		 }
	}
	else if (input==0)
	{
		for (i = 0; i < size && find == 0; i++)
		{
			if (acc[i].accountnum == accountnum)
			{
				
				addr = i; 
				find = 1;
				
			}
		}
		if (find == 0)
		{
			addr = -1;
		}
		
	}
	
	return addr;
}









