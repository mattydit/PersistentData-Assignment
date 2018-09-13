/*
Program Description: IT services ticketing system
Author: Team 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

struct details
{
  char name[21];
  char phone[11];
  char desc[31];
  char times[6];
};
//Structure for the queue.
struct q
{
  struct details array[SIZE];
  int tail;
  int head;
};

//Prototypes
void enqueue(struct q *);   //Add new ticket.
void dequeue(struct q *);   //Delete ticket.
void display(struct q *);   //Display the tickets.
void demo(struct q *);      //Demo 3 out of 5 filled.

int main()
{
  int menu;
  struct q queue;
  struct q *ptr;    //Pointer for struct
  char ch;

  queue.tail = 0;
  queue.head = 0;

  ptr = &queue;

  do
  {
    printf("\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Demo\n");
    printf("5. Exit\n");

    scanf("%d", &menu);

    while ((ch = getchar()) != '\n' && ch != EOF );   //Fixes infinite loop

    switch(menu)
    {
      case 1:
      {
        enqueue(ptr);
        break;
      }
      case 2:
      {
        dequeue(ptr);
        break;
      }
      case 3:
      {
        display(ptr);
        break;
      }
      case 4:
      {
        demo(ptr);
        break;
      }
      case 5:
      {
        break;
      }
      default:
      {
        break;
      }
    }
  }
  while (menu != 5);

  return(0);
}

void enqueue(struct q *ptr)
{
  struct details ticket;

  if (ptr -> tail == SIZE)
  {
    printf("Queue is full\n");
  }
  else  //If queue isn't full add new ticket
  {
    printf("Enter name\n");
    gets(ticket.name);

    printf("Enter phone number\n");
    gets(ticket.phone);

    printf("Enter short description of the issue\n");
    gets(ticket.desc);

    printf("Enter time of phone call\n");
    gets(ticket.times);

    ptr -> array[ptr -> tail++] = ticket;

    printf("Enqueued at %d\n", ptr -> tail);

    if (ptr -> tail == SIZE)
    {
      printf("Queue is now full\n");
    }
  }
}

void dequeue(struct q *ptr)
{
  if (ptr -> tail == ptr -> head)
  {
    printf("Underflow\n");
  }
  else
  {
    ptr -> head++;
    printf("Ticket is dequeued from %d\n", ptr -> head);
  }
}

void display(struct q *ptr)
{
  int i;

  if (ptr -> head == ptr -> tail)
  {
    printf("Queue is empty\n");
  }
  else
  {
    for (i = ptr -> head; i < ptr -> tail; i++)
    {
      printf("\n");
      printf("Name of client: %s\n", ptr -> array[i].name);
      printf("Contact Number: %s\n", ptr -> array[i].phone);
      printf("Description of issue: %s\n", ptr -> array[i].desc);
      printf("Time of phone call: %s\n", ptr -> array[i].times);
    }
  }
}

void demo(struct q *ptr)
{
  struct details ticket;

  if (ptr -> tail == SIZE)
  {
    printf("Queue is full\n");
  }
  else
  {
    strcpy(ticket.name, "Jane");
    strcpy(ticket.phone, "4558");
    strcpy(ticket.desc, "Monitor broken");
    strcpy(ticket.times, "12:05");

    ptr -> array[ptr -> tail++] = ticket;

    printf("Enqueued at %d\n", ptr -> tail);

    strcpy(ticket.name, "Sean");
    strcpy(ticket.phone, "5656");
    strcpy(ticket.desc, "Desktop flickering");
    strcpy(ticket.times, "12:06");

    ptr -> array[ptr -> tail++] = ticket;

    printf("Enqueued at %d\n", ptr -> tail);

    strcpy(ticket.name, "Mark");
    strcpy(ticket.phone, "1212");
    strcpy(ticket.desc, "Router lights amber");
    strcpy(ticket.times, "12:10");

    ptr -> array[ptr -> tail++] = ticket;

    printf("Enqueued at %d\n", ptr -> tail);
  }
}
