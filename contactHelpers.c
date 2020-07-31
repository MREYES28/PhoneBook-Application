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

/*This file is our implementation of our prototypes defined in contactHelpers.h*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"

// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5



//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
   while (getchar() != '\n');
}

// pause: Empty function definition goes here:
void pause()
{
   printf("(Press Enter to Continue)");
   clearKeyboard();
}


// getInt: Empty function definition goes here:
int getInt()
{
   char NL = 'x';
   int value = 0;

   while (NL != '\n')
   {
      scanf("%d%c", &value, &NL);
      if (NL != '\n') {
         clearKeyboard();
         printf("*** INVALID INTEGER *** <Please enter an integer>: ");
      }
   }
   return value;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
   int value = -1;
   
   while (value != min && value != max)
   {
      value = getInt();
      if (value > max || value < min)
      {
         printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
      }
      else
      {
         return value;
      }
   }
   return value;
}

// yes: Empty function definition goes here:
int yes()
{
   char CH = 'x';
   char NL = 'x';

   while (CH != 'Y' || CH != 'y' || CH != 'N' || CH != 'n' || NL != '\n') {
      scanf("%c%c", &CH, &NL);
       if (NL != '\n')
       {
          clearKeyboard();
          printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
       }
     else if (CH == 'Y' || CH == 'y') {
         return 1;

      }
      else if (CH == 'N' || CH == 'n') {
         return 0;
      }
   }
   return CH;
}


// menu: Empty function definition goes here:
int menu()
{
   int choice = 0;

   printf("Contact Management System\n");
   printf("-------------------------\n");
   printf("1. Display contacts\n");
   printf("2. Add a contact\n");
   printf("3. Update a contact\n");
   printf("4. Delete a contact\n");
   printf("5. Search contacts by cell phone number\n");
   printf("6. Sort contacts by cell phone number\n");
   printf("0. Exit\n\n");

   printf("Select an option:> ");

  choice = getIntInRange(0, 6);
  printf("\n");

  return choice;
}


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem()
{
   struct Contact contact[MAXCONTACTS] = { { { "Rick",{ '\0' }, "Grimes" },
   { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
   { "4161112222", "4162223333", "4163334444" } },
   {
      { "Maggie", "R.", "Greene" },
      { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
      { "9051112222", "9052223333", "9053334444" } },
      {
         { "Morgan", "A.", "Jones" },
         { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
         { "7051112222", "7052223333", "7053334444" } },
         {
            { "Sasha",{ '\0' }, "Williams" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9052223333", "9052223333", "9054445555" } },
   };

   int exit = 0;
   int choice;

   do {

      choice = menu();
      switch (choice)
      {
         menu();
      case 1:

         displayContacts(contact, MAXCONTACTS);
         pause();
         printf("\n");

         break;

      case 2:

         addContact(contact, MAXCONTACTS);
         pause();
         printf("\n");

         break;
      case 3:

         updateContact(contact, MAXCONTACTS);
         pause();
         printf("\n");

         break;
      case 4:

         deleteContact(contact, MAXCONTACTS);
         pause();
         printf("\n");

         break;
      case 5:

         searchContacts(contact, MAXCONTACTS);
         pause();
         printf("\n");

         break;
      case 6:

         printf("<<< Feature to sort is unavailable >>>\n\n");
         pause();
         printf("\n");

         break;
      case 0:

         printf("Exit the program? (Y)es/(N)o: ");
         
         if (yes() == 1)
         {
            
            exit = 1;
            printf("\n");
            break;
         }
         printf("\n");
         break;

      }
   } while (exit != 1);
   printf("Contact Management System: terminated\n");
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

void getTenDigitPhone(char phoneNum[])
{
   int needInput = 1;
   int i = 0;
   int check = 0;

   do
   {
      scanf("%10s", phoneNum);
      clearKeyboard();
      for (i = 0; phoneNum[i] != '\0'; i++)
      {
         if (!isdigit(phoneNum[i]))
         {
            needInput = 0;
            if (needInput == 0)
            {
               break;
            }
         }
         else
         {
            needInput = 1;
         }
         
      }
      if (needInput == 0 || strlen(phoneNum) != 10)
      {
         //if needInput is 0 error
         check = 0;
      }
      else
      {
         check = 1;
      }
      if (check == 0 || strlen(phoneNum) != 10)
      {
         printf("Enter a 10-digit phone number: ");
      }
      else
      {
         check = 1;
      }
   } while (check == 0);
   
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
   int find = -1;
   int i = 0;

   for (i = 0; i < size; i++)
   {
      if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
      {
         find = i;
      }
   }
   
   return find;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader()
{
   printf("+-----------------------------------------------------------------------------+\n");

   printf("|                              Contacts Listing                               |\n");

   printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
   printf("+-----------------------------------------------------------------------------+\n");

   printf("Total contacts: %d\n\n", count);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *contact)
{
   //fullname
   printf(" %s ", contact->name.firstName);

   if (strlen(contact->name.middleInitial) != 0)
   {
      printf("%s ", contact->name.middleInitial);
   }

   printf("%s", contact->name.lastName);
   printf("\n");

   //numbers
   printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

   //contact address
   printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

   if (contact->address.apartmentNumber > 0)
   {
      printf("Apt# %d, ", contact->address.apartmentNumber);
   }

   printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
   int i = 0;
   int valid = 0;
   displayContactHeader();

   for (i = 0; i < size; i++)
   {
      if (strlen(contacts[i].numbers.cell) > 0)
      {
         displayContact(&contacts[i]);
         valid++;
      }
   }
   displayContactFooter(valid);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
   char cellNum[11];
   int found = 0;

   printf("Enter the cell number for the contact: ");
   getTenDigitPhone(cellNum);

   found = findContactIndex(contacts, size, cellNum);

   if (found != -1)
   {
      printf("\n");
      displayContact(&contacts[found]);
      printf("\n");
   }
   else
   {
      printf("*** Contact NOT FOUND ***\n\n");
   }
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
   int add = -1;
   int i = 0;

   for (i = 0; i < size; i++)
   {
      if (strlen(contacts[i].numbers.cell) == 0)
      {
         add = i;
      }
     
   }
   if (add > -1)
   {
      getContact(&contacts[add]);
      printf("--- New contact added! ---\n\n");
   }
   else
   {
      printf("*** ERROR: The contact list is full! ***\n\n");
   }
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
   int update = 0;
   char cellNum[11];

   printf("Enter the cell number for the contact: ");
   getTenDigitPhone(cellNum);

  
      update = findContactIndex(contacts, size, cellNum);
      if (update > 0)
      {
         printf("\nContact found:\n");
         displayContact(&contacts[update]);
         printf("\n");

         printf("Do you want to update the name? (y or n): ");
         if (yes() == 1)
         {
            getName(&contacts[update].name);
         }
         printf("Do you want to update the address? (y or n): ");
         if (yes() == 1)
         {
            getAddress(&contacts[update].address);
         }
         printf("Do you want to update the numbers? (y or n): ");
         if (yes() == 1)
         {
            getNumbers(&contacts[update].numbers);
         }
         printf("--- Contact Updated! ---\n\n");
      }
      else
      {
         printf("*** Contact NOT FOUND ***\n\n");
      }
   

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
   int del = 0;
   char cellNum[11];

   printf("Enter the cell number for the contact: ");
   getTenDigitPhone(cellNum);

      del = findContactIndex(contacts, size, cellNum);

      if (del > -1)
      {
         printf("\nContact found:\n");
         displayContact(&contacts[del]);
         printf("\n");
         printf("CONFIRM: Delete this contact? (y or n): ");

         if (yes() == 1)
         {
            contacts[del].numbers.cell[0] = '\0';
            printf("--- Contact deleted! ---\n\n");
         }
         else
         {
            printf("\n");
         }
         
      }
   
   
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
   //int i = 0;
   //int sort = 0;

   //for (i = 0; i < size; i++)
   //{
   //   sort = i;
   //}
}