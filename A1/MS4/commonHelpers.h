/*
	==================================================
	 Assignment #1 Milestone #1:
	==================================================
	Name   :Tanishq Talreja
	ID     :126460203
	Email  :ttalreja@myseneca.ca
	Section:NCC
*/
#define _CRT_SECURE_NO_WARNINGS

#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

int currentYear(void);

void clearStandardInputBuffer(void);
//1.INTEGER FUNCTION

int getInteger(void);
//2.GET POSI INT

int getPositiveInteger(void);
//GET DB
double getDouble(void);
//GET +DB
double getPositiveDouble(void);
//GET RANGE
int getIntFromRange(int lowerRange, int upperRange);

// CHAR INpUT
char getCharOption(const char string[]);

//CHAR STRING INP
void getCString(char* string, int lowrange, int uprange);

#endif // !COMMON_HELPERS_H_