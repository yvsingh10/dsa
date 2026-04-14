#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node*link;
};

struct node*tail=NULL;

void append();
void display();
int length();
void insert_loc();
void deletee();

void append()
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  temp->link=NULL;

  if(tail==NULL)
  {
    tail=temp;
    tail->link=temp;
  }
  else
  {
    temp->link=tail->link;
    tail->link=temp;
    tail=temp;
  }
}

void display()
{
 struct node*p;
 printf("List:\n");
 p=tail->link;
 do
 {
   printf("%d->",p->data);
   p=p->link;
 }
 while(p!=tail->link);
 printf("NULL\n");
}

int length()
{
  int count=0;
  struct node*p;
  p=tail->link;
  do
  {
    count++;
    p=p->link;
  }
  while(p!=tail->link);
  return count;
}

void insert_loc()
{
  int loc,i=1;
  struct node*temp,*p;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data to insert: ");
  scanf("%d",&temp->data);
  temp->link=NULL;

  printf("Enter the location: ");
  scanf("%d",&loc);

  if(loc<=length())
  {
    if(loc==1)
    {
      temp->link=tail->link;
      tail->link=temp;
    }
    else
    {
      p=tail->link;
      while(i<loc-1)
      {
	p=p->link;
	i++;
      }
      temp->link=p->link;
      p->link=temp;
    }
  }
  else
  {
    printf("\nInvalid location\n");
  }

}

void deletee()
{
 int l,i=1;
 struct node*p,*q;
 printf("Enter the location to delete: ");
 scanf("%d",&l);

 if(l<=length())
 {
   if(l==1)
   {
     p=tail->link;
     tail->link=p->link;
     p->link=NULL;
     free(p);
   }
   else if(l==length())
   {
     p=tail->link;
     while(i<l-1)
     {
      p=p->link;
      i++;
     }
     p->link=tail->link;
     q->link=NULL;
     free(q);
     tail=p;
   }
   else
   {
     p=tail->link;
     while(i<l-1)
     {
      p=p->link;
      i++;
     }
     q=p->link;
     p->link=q->link;
     q->link=NULL;
     free(q);
   }
 }
 else
 {
  printf("\nInvalid location\n");
 }
}
void main()
{
    int choice;

    clrscr();

    while(1)
    {
	printf("\n--- LINKED LIST MENU ---\n");
	printf("1. Append\n");
	printf("2. Display\n");
	printf("3. Insert at location\n");
	printf("4. Delete from location\n");
	printf("5. Length\n");
	printf("6. Exit\n");

	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
	    case 1:
		append();
		break;

	    case 2:
		display();
		break;

	    case 3:
		insert_loc();
		break;

	    case 4:
		deletee();
		break;

	    case 5:
		printf("Length = %d\n", length());
		break;

	    case 6:
		exit(0);

	    default:
		printf("Invalid choice\n");
	}
    }

    getch();
}


