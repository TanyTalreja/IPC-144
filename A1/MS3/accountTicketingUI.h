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

#endif // !ACCOUNTUI_H_
