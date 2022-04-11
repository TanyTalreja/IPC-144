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


#ifndef ACCOUNTUI_H_
#define ACCOUNTUI_H_
//F1 to display header for summ

void  displayAccountSummaryHeader(void);

//F2 display header for the whole data

void displayAccountDetailHeader(void);

//F3 to display the data for the summ up

void displayAccountSummaryRecord(const struct Account* account);

//F4 display the whole data

void displayAccountSummaryRecord(const struct Account* account);

//milestone 4
//F1 for app start
void applicationStartup(struct Account account[], int size);

//F2 for  menu login

int menuLogin(const struct Account acc[], int size);
// F3 for menu of agent
//accounts is for the agent that has logged in
void menuAgent(struct Account acc[], int size, const struct Account* accounts);

//F4 search function
int findAccountIndexByAcctNum(int accountnum, const struct Account acc[], int size, int input);
//F5 display the detailed rec
void displayAllAccountDetailRecords(const struct Account acc[], int size);

//F6 display the summary of rec
void displayAllAccountSummaryRecords(const struct Account acc[], int size);

//pause exec.
// Pause execution until user enters the enter key
void pauseExecution(void);

#endif // !ACCOUNTUI_H_
