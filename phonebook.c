/*
Program Description: Phonebook that performs: Add contact, delete, edit, find,
record contacts to file.
Date: 21/04/2017
Author: Team 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 21
#define CONTACTSIZE 200

struct contact
{
  char name[SIZE];
  char phone[11];
  char email[SIZE];
};

//Prototypes
void addnew(struct contact *, int);
void display(struct contact *);
void delete(struct contact *);
void edit(struct contact *);
void find(struct contact *);
void record(struct contact *, FILE*);

int main()
{
  FILE *fp;
  int menu = 0;
  char ch;
  struct contact entry[CONTACTSIZE];
  struct contact *ptr;
  int newcounter = -1;

  ptr = &entry;

  if ((fp = fopen("phonebook.txt", "w+"))==NULL)
  {
    printf("Error opening file\n");
  }
  else
  {
    do
    {
      printf("\n");
      printf("1. Add new contact\n");
      printf("2. Delete old contact\n");
      printf("3. Edit contact\n");
      printf("4. Find contact\n");
      printf("5. Record contacts\n");
      printf("6. Exit\n");
      printf("9. display()\n");

      scanf("%d", &menu);

      while ((ch = getchar()) != '\n' && ch != EOF );   //Fixes infinite loop

      switch(menu)
      {
        case 1:
        {
          newcounter++;   //Increase counter, so new contact is made in the next entry of the array.
          addnew(ptr, newcounter);
          break;
        }
        case 2:
        {
          delete(ptr);
          break;
        }
        case 3:
        {
          edit(ptr);
          break;
        }
        case 4:
        {
          find(ptr);
          break;
        }
        case 5:
        {
          record(ptr, fp);
          break;
        }
        case 6:
        {
          fclose(fp);
          break;
        }
        case 9:
        {
          display(ptr);
          break;
        }
        default:
        {
          printf("Invalid option\n");
          break;
        }
      }
    }
    while (menu != 6);
  }

  return(0);
}

void addnew(struct contact *ptr, int counter)
{

  if (counter == CONTACTSIZE)
  {
    printf("The phonebook is full!\n");
  }
  else
  {
    printf("Enter Name:\n");
    gets((ptr + counter) -> name);

    printf("Enter Phone Number:\n");
    gets((ptr + counter) -> phone);

    printf("Enter Email:\n");
    gets((ptr + counter) -> email);
  }

}

void display(struct contact *ptr)
{
  int i;
  int n;

  printf("How many entries to display?\n");
  scanf("%d", &n);
  //Print contacts
  for (i = 0; i < n; i++)
  {
    printf("\n");
    printf("%s\n", ptr[i].name);
    printf("%s\n", ptr[i].phone);
    printf("%s\n", ptr[i].email);
  }
}

void delete(struct contact *ptr)
{
  int i;
  char key[11];
  int found;
  int counter = -1;
  char choice[4];
  char yes[] = "yes";
  char no[] = "no";

  printf("Enter Phone number of contact:\n");
  gets(key);

  for (i = 0; i < CONTACTSIZE; i++)
  {
    if (strcmp(key, ptr[i].phone) == 0)
    {
      found = 1;
      counter = i;  //Counter to find the array element through the for loop.
      break;
    }
    else
    {
      found = 0;
    }
  }

  if (found == 1)
  {
    printf("Found contact: %s\n", ptr[counter].name);
  }
  else if (found == 0)
  {
    printf("Contact not found.\n");
  }

  //printf("%d\n", counter);  //debug

  printf("Do you want to delete the contact?\n yes/no\n");

  gets(choice);

  if (strcmp(choice, yes) == 0)
  {
    memset(&ptr[counter], 0, sizeof(ptr[counter]));  //Sets struct to null.
    printf("Deleted.\n");
  }
  else if (strcmp(choice, no) == 0)
  {
    printf("Returning to menu.\n");
  }

}

void edit(struct contact *ptr)
{
  int i;
  char key[11];
  int found;
  int counter = -1;
  int editmenu = 0;
  char ch;

  printf("Enter Phone number of contact:\n");
  gets(key);

  for (i = 0; i < CONTACTSIZE; i++)
  {
    if (strcmp(key, ptr[i].phone) == 0)
    {
      found = 1;
      counter = i;  //Counter to find the array element through the for loop.
      break;
    }
    else
    {
      found = 0;
    }
  }

  if (found == 1)
  {
    printf("Found contact: %s\n", ptr[counter].name);
  }
  else if (found == 0)
  {
    printf("Contact not found.\n");
  }

  printf("Which field would you like to edit?\n");
  //Sub menu for contact editing.
  do
  {
    printf("\n");
    printf("1. Name\n");
    printf("2. Phone Number\n");
    printf("3. Email\n");
    printf("4. Go back to main menu\n");

    scanf("%d", &editmenu);

    while ((ch = getchar()) != '\n' && ch != EOF );   //Fixes infinite loop

    switch(editmenu)
    {
      case 1:
      {
        printf("Enter name:\n");
        gets(ptr[counter].name);
        printf("Name changed to: %s\n", ptr[counter].name);
        break;
      }
      case 2:
      {
        printf("Enter phone number:\n");
        gets(ptr[counter].phone);
        printf("Phone changed to: %s\n", ptr[counter].phone);
        break;
      }
      case 3:
      {
        printf("Enter email:\n");
        gets(ptr[counter].email);
        printf("Email changed to: %s\n", ptr[counter].email);
        break;
      }
      case 4:
      {
        break;
      }
      default:
      {
        printf("Invalid option\n");
        break;
      }
    }
  }
  while (editmenu != 4);

}

void find(struct contact *ptr)
{
  int i;
  char key[11];
  int found;
  int counter = -1;

  printf("Enter Phone number of contact:\n");
  gets(key);

  for (i = 0; i < CONTACTSIZE; i++)
  {
    if (strcmp(key, ptr[i].phone) == 0)
    {
      found = 1;
      counter = i;  //Counter to find the array element through the for loop.
      break;
    }
    else
    {
      found = 0;
    }
  }

  if (found == 1)
  {
    printf("Found contact:\n");
    printf("\n");
    printf("%s\n", ptr[i].name);
    printf("%s\n", ptr[i].phone);
    printf("%s\n", ptr[i].email);
  }
  else if (found == 0)
  {
    printf("Contact not found.\n");
  }
}

void record(struct contact *ptr, FILE *fp)
{
  int i;
  char newline[] = "\n";

  for (i = 0; i < CONTACTSIZE; i++)
  {
    fwrite (&ptr[i], sizeof(struct contact), 1, fp);  //write the struct to file.
    fwrite (newline, sizeof(newline), 1, fp);   //Skip a line in the file.
  }

  printf("Contacts recorded to file.\n");
}
