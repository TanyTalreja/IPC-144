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
#define MAX_ARR_SIZE 31
#define MIN_ARR_SIZE 11

//DEF LIBS
#include <stdio.h>
#include "commonHelpers.h"    

//BEGIN of main code
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
//MAIN CODE GOES HERE
 
//DEFINING struct for userlogin
struct UserLogin
{
	
	char dispname[MAX_ARR_SIZE]; 
	char name[MIN_ARR_SIZE];
	char password[MIN_ARR_SIZE];

};

//defining struct for demographic
struct Demographic
{
	int birthyear;
	double houseincome;
	char country[MAX_ARR_SIZE];
};

//defining struct for account 

struct Account
{
	int accountnum;
	char user;
	//defining struct data type for UserLogin as userlogin
	struct UserLogin userlogin;
	//defining struct data type for DEMOGRAPHIC as demographic
	struct Demographic demographic;
	
	//specification 1 completed
};

// FUNCTIONS TO CALL

//F1 to input user account

void getAccount(struct Account* account);

//F2 to input userlogin details from user

void getUserLogin(struct UserLogin* userlogin);

//F3 to input demographic details from user
void getDemographic(struct Demographic* demographic);

//MILESTONE 4
//update account function 
void updateAccount(struct Account* accounts);

//F2 to update the login
void updateUserLogin(struct UserLogin* login);

//F3 to update the demo

void updateDemographic(struct Demographic* demo);

#endif // !ACCOUNT_H_

