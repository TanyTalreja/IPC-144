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
//MACROS
#define MIN 3
#define MAX 30
//DEFINING HEADER FILES
#include "account.h"
#include "commonHelpers.h"

//HEADERFILES INCLUDED

//MAINCODE STARTS HERE ->->->

//F1 to input user account

void getAccount(struct Account *account)
{
	struct Account acc = {0};
	printf("Account Data: New Record\n");                   
	printf("----------------------------------------\n");
	//input accountnumber of user
	
	printf("Enter the account number: ");
	account->accountnum = getPositiveInteger();
	
	//Prompts the user to enter the account type.
	printf("Enter the account type (A=Agent | C=Customer): ");
	account->user = getCharOption("AC");
	//input process ends here -----
	acc = *account;
}

//F2 to input userlogin details from user

void getUserLogin(struct UserLogin *userlogin)
{
	//struct type defined for return value
	struct UserLogin login = { 0 };
	
	//print statements
	printf("\nUser Login Data Input\n");                 
	printf("----------------------------------------\n"); 

	//Prompts the user to enter the user login ID

	printf("Enter user login (10 chars max): ");
	getCString(userlogin->name, MIN, 10);

	//Prompts the user to enter the user display name.
	
	printf("Enter the display name (30 chars max): ");
	getCString(userlogin->dispname, MIN,MAX );

	//Prompts the user to enter the user login password.

	printf("Enter the password (must be 8 chars in length): ");
	getCString(userlogin->password, 8, 8);

	//input process ends here -----
	 login= *userlogin ;
}

//F3 to input demographic details from user
void getDemographic(struct Demographic* demographic)
{
	//struct type defined for return value
	struct Demographic demo= { 0 };
	// process to calc the current date
	int currentyear, maxyear, minyear;
	currentyear = currentYear();
	maxyear = currentyear - 110;
	minyear = currentyear - 18;

	//print statements
	printf("\nDemographic Data Input\n");                
	printf("----------------------------------------\n");

	//Prompts the user to enter the account holder's birth year.

	printf("Enter birth year (current age must be between 18 and 110): ");
	demographic->birthyear = getIntFromRange(maxyear, minyear);

	//Prompts the user to enter the household income
	
	printf("Enter the household Income: $");
	demographic->houseincome = getPositiveDouble();

	//Prompts the user to enter the country where account holder lives.

	printf("Enter the country (30 chars max.): ");
	getCString(demographic->country, MIN, MAX);

	//input process ends here -----
	demo= *demographic ;
}