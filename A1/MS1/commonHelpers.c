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

//defined libs
#include <stdio.h>
#include <time.h>
//USER DEF libs
#include "commonHelpers.h"

// Uses the time.h library to obtain current year information
// Get the current 4-digit year from the system
int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

//INPUT BUFFER
//As demonstrated in the course notes :
//https://ict.senecacollege.ca//~ipc144/pages/content/formi.html#buf
// Empty the standard input buffer

void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; // On purpose: do nothing
	}
}

//1.INTEGER FUNCTION

int getInteger(void)
{
	int integer;
	char newline='x' ;
	
	while (newline != '\n')
	{
		scanf("%d%c", &integer, &newline);
		if (newline=='\n')
		{
			return integer;
		}
		
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	}

	
}

//2.GET POSI INT
int getPositiveInteger(void)
{
	int positive=-1;
	char newline='x';

	while ( positive<=0)
	{
		scanf("%d%c", &positive, &newline);
		if (positive>0)
		{
			if (newline != '\n')
			{
				clearStandardInputBuffer();
			}
			return positive;			
		}
		
		else
		{
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
	}
	

}

//GET DB
double getDouble(void)
{
	double db;
	char newline = 'x';

	while (newline != '\n')
	{
		scanf("%lf%c", &db, &newline);
		if (newline == '\n')
		{
			return db;
		}

		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number:");
		}
	}


}

//GET +DB

double getPositiveDouble(void)
{
	double positive = -1;
	char newline = 'x';

	while (positive <= 0)
	{
		scanf("%lf%c", &positive, &newline);
		if (newline != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number:");

		}
		else if (positive > 0)
		{
			if (newline == '\n')
			{

				return positive;
				clearStandardInputBuffer();
			}
		}

		else
		{
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
	}


}

//GET RANGE
int getIntFromRange(int lowerRange,int upperRange)
{
	int integer;
	char newline = 'x';
	int flag = 0;

	while (newline != '\n' || flag==0)
	{
		scanf("%d%c", &integer, &newline);
		
		if (newline == '\n')
		{
			if (integer>=lowerRange && integer<=upperRange)
			{
				flag = 1;
				return integer;
				
			}
			else
			{
				printf("ERROR: Value must be between %d and %d inclusive: ", lowerRange, upperRange);
				flag = 0;
			}
		}

		if (newline!='\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
		
	}

}
// CHAR INpUT
char getCharOption(const char string[])
{
	int i, found = 0;
	char name;
	char newline = 'x';

	while (found == 0)
	{
		scanf("%c%c", &name, &newline);

		if (newline == '\n')
		{
			for (i = 0; !found && i < string[i] != '\0'; i++)
			{
				if (string[i] == name)
				{
					found = 1;
				}
			}

		}

		if (!found)
		{
			if (newline != '\n')
			{
				clearStandardInputBuffer();
			}
			printf("ERROR: Character must be one of [%s]: ", string);
		}

	}

	return name;
}

//CHAR STRING INP
void getCString(char *string,int lrange,int urange)
{
	int flag=0;
	int i, count = 0;
	char word[30];
	do
	{
		scanf("%[^\n]",word);

		for (i = 0; word[i] != '\0'; i++)
		{
			count = i;
		}
		

		//For loop is ended
		//enters if count is between range
		if (count+1>=lrange&&count+1<=urange)
		{
			//COPY PASTE THE STRING
			if (string!=NULL)
			{
				for (i = 0; word[i] != '\0'; i++)
				{
					string[i] = word[i];
				}
			}
			
			flag = 1;
		}

		else if (lrange==urange)
		{
			printf("ERROR: String length must be exactly %d chars: ",urange);
		}
		else if (lrange>=3)
		{
			printf("RROR: String length must be no more than %d chars: ", urange);
		} 
		else
		{
			printf("ERROR: String length must be between %d and %d chars: ",lrange,urange);
		}
		clearStandardInputBuffer();

	} while (flag==0);
	
	

}

