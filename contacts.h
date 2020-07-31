#ifndef CONTACTS_H_
#define CONTACTS_H_
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

/*This file is for our structures and prototypes for our getName, getAddress, getNumbers functions.*/

//--------------------------------
// Structure Types
//--------------------------------


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name
{
   char firstName[30 + 1];
   char middleInitial[6 + 1];
   char lastName[35 + 1];
};
// Structure type Address declaration
// Place your code here...
struct Address
{
   int streetNumber;
   char street[40 + 1];
   int apartmentNumber;
   char postalCode[7 + 1];
   char city[40 + 1];
};

// Structure type Numbers declaration
// Place your code here...

struct Numbers
{
   char cell[10 + 1];
   char home[10 + 1];
   char business[10 + 1];
};
// Structure type Contact declaration
// NOTE:  Make sure the structure name does not have an 's' on the end!
// Place your code here...
struct Contact
{
   struct Name name;
   struct Address address;
   struct Numbers numbers;
};


//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function prototypes below...             |
// +-------------------------------------------------+


// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name *name);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address *address);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers *numbers);

// Get and store from standard input the values for a Contact (NOT: Contacts)
// NOTE:  Make sure the structure Contact does not have an 's' on the end!
// Put function prototype below:
void getContact(struct Contact *contact);


// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_