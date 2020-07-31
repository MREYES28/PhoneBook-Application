//==============================================
// Name:           Melvyn Reyes
// Student Number: 130 904 154
// Email:          mreyes28@myseneca.ca
// Section:        NWW
// Date:           11/26/2019
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

/*This file contains prototypes for our contactHelpers.c functions.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*-------------------------------------------------------------------------
Description: This header file modularizes general helper functions
to help reduce redundant coding for common repetitive tasks.
------------------------------------------------------------------------- */

// Hint:  This header file now has functions with parameters referring to 
//        the struct Contact type so be sure to include the contacts.h header:
#include "contacts.h"


//--------------------------------
// Function Prototypes
//--------------------------------


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes here...              |
// +-------------------------------------------------+


// clearKeyboard:  Empty function definition 
void clearKeyboard();

// pause: Empty function definition goes here:
void pause();


// getInt: Empty function definition goes here:
int getInt();


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max);


// yes: Empty function definition goes here:
int yes();


// menu: Empty function definition goes here:
int menu();


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem();

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);


// displayContactHeader
// put function prototype here:
void displayContactHeader();

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int count);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact *contact);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact contacts[], int size);

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact contacts[], int size);

// addContact:
// put function prototype here:
void addContact(struct Contact contacts[], int size);

// updateContact:
// put function prototype here:
void updateContact(struct Contact contacts[], int size);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact contacts[], int size);

// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contacts[], int size);