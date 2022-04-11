// ===================================================================================
//  Assignment: 1 
//  Milestone : 3
 /*
==================================================
Assignment #1
==================================================
Name : Tanishq Talreja
ID : 126460203
Email : ttalreja@myseneca.ca
Section : NCC
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "account.h"
#include "accountTicketingUI.h"

// ------------------------------------------------------------------
// Main entry point to application:

int main(void)
{
    // *** NOTE: No other variables are allowed to be declared ***
    struct Account account = { 0 };                               // *** DO NOT MODIFY THIS LINE ***

    printf("Assignment 1 Milestone 3 - Tester\n");                // *** DO NOT MODIFY THIS LINE ***
    printf("=============================================\n");    // *** DO NOT MODIFY THIS LINE ***

    // ---------------------------------------------------------
    // Account Data
    // ---------------------------------------------------------
    // Input (new record)
    getAccount(&account);   // Call function to get user input for a new "Account"

    // ---------------------------------------------------------
    // UserLogin Data
    // ---------------------------------------------------------
    // Input (new record)
       getUserLogin(&account.userlogin);   // Call function to get user input for a new "UserLogin"
    
    // ---------------------------------------------------------
    // Demographic Data
    // ---------------------------------------------------------
    // Input (new record)
        getDemographic(&account.demographic);  // Call function to get user input for a new "Demographic"

    // ---------------------------------------------------------
    // Display formatted Account summary/details
    // ---------------------------------------------------------
        displayAccountSummaryHeader();     // Call function to display the account SUMMARY header
        displayAccountSummaryRecord(&account);  // Call function to display an account SUMMARY record
        putchar('\n');
        
        //display all data

        displayAccountDetailHeader();         // Call function to display the account DETAIL header
        displayAccountDetailRecord(&account);   // Call function to display an account DETAIL record

    putchar('\n');
    printf("Account, User Login, and Demographic test completed!\n");  // *** DO NOT MODIFY THIS LINE ***

    return 0;       // *** DO NOT MODIFY THIS LINE ***
}
