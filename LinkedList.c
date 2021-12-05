#include <stdio.h>
#include <stdlib.h>
/*
this first global block is for the creation of the structure that contains two components
1. data(integer value)
2. next address(pointer)
*/
struct node{

int data;
struct node *next;

};
struct node *head = NULL;

//insert_end function is used to insert an element at the end of the linked list
void insert_end()
{
  struct node *temp, *newnode;
  //temp traverses through the list and newnode is the new structure pointer created to hold the incoming data

  int item;
  newnode = (struct node *)malloc(sizeof(struct node));
  //allocating memory for new node through malloc function


  printf("Enter the element that you would like to enter at the end of the linked list : ");
  scanf("%d", &item);
  //accepting user value


  newnode->data = item;
  newnode->next = NULL;
  //assigning the incoming data to a stucture


  if(head ==  NULL)
  {   //if there is no element already declared
      head = newnode;

  }

  else
    {
        //if there are previously alloted elements

    temp = head;
    while(temp->next!=NULL)//making temp traverse to the end of the list and then stop
            temp = temp->next;

    temp->next= newnode;//attach the new node at the end of the list
    }

}


void insert_beg()
{

    struct node *newnode;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the element that you would like to insert at the beginning of the list :");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = NULL;

    if(head == NULL)
    {   //if there is no list present previously
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
        //attaching the newnode to the beginning and repositioning the head pointer to the new beginning address
    }
}


void deleteend()
{
    int deleted_item;
    struct node *temp;
    if(head == NULL)
        printf("NO ELEMENTS PRESENT TO BE DELETED");

    else if(head->next==NULL)
    {
        deleted_item = head->data;
        head = NULL;
        printf("Deleted item : %d", deleted_item);
    }
    else
    {
        temp = head;
        while(temp->next->next!=NULL)
            temp = temp->next;
        deleted_item = temp->next->data;
        printf("Deleted item : %d", deleted_item);
        temp->next =NULL;

    }

}

void deletefirst()
{
    int deleted_item;
    if(head == NULL)
        printf("NO ELEMENTS PRESENT TO BE DELETED");
    else if(head->next==NULL)
    {
        deleted_item = head->data;
        head = NULL;
        printf("Deleted item : %d", deleted_item);
    }
    else
    {
        deleted_item = head->data;
        head = head->next;
        printf("Deleted item : %d", deleted_item);
    }
}


void display()//to display the elements
{
printf("Elements are : ");
struct node *pointer;
pointer = head;
while(pointer!=NULL){
   printf("\t%d", pointer->data);
   pointer = pointer->next;
}

}




main()
{
    int ch;
    do{
  printf("\n===============================\nEnter your choice:\n1.Insert beginning\n2.Insert End\n3.Delete End\n4.Delete First\n5.Display\n6.Exit\n===============================\n\n");
  scanf("%d", &ch);
      switch(ch)
    {
      case 1: insert_beg(); break;
      case 2: insert_end(); break;
      case 3: deleteend(); break;
      case 4: deletefirst(); break;
      case 5: display(); break;
      default: exit(0);
    }
    }while(1);


}
