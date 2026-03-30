#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *ROOT = NULL;


int length();
void deletee();


void append()
{
    struct node *temp, *p;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if(ROOT == NULL)
    {
	ROOT = temp;
    }
    else
    {
	p = ROOT;
	while(p->link != NULL)
	{
	    p = p->link;
	}
	p->link = temp;
    }
}


void display()
{
    struct node *p = ROOT;

    printf("\nList: ");
    while(p != NULL)
    {
	printf("%d -> ", p->data);
	p = p->link;
    }
    printf("NULL\n");
}


int length()
{
    int count = 0;
    struct node *p = ROOT;

    while(p != NULL)
    {
	count++;
	p = p->link;
    }
    return count;
}


void insert_loc()
{
    int loc, i = 1;
    struct node *temp, *p;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    printf("Enter location: ");
    scanf("%d", &loc);


    if(loc == 1)
    {
	temp->link = ROOT;
	ROOT = temp;
	return;
    }

    if(loc <= length())
    {
	p = ROOT;

	while(i < loc - 1)
	{
	    p = p->link;
	    i++;
	}

	temp->link = p->link;
	p->link = temp;
    }
    else
    {
	printf("Invalid location\n");
    }
}

void deletee()
{
  int l;
  int i=1;
  struct node *p;
  printf("Enter the location to delete: ");
  scanf("%d",&l);


  if(l<=length())
  {
    if(l==1)
    {
      p=ROOT;
      ROOT=ROOT->link;
      p->link =NULL;
      free(p);
    }
    else
    {
      struct node*p,*q;
      p=ROOT;

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
 }



void main()
{
    int n, i;

    clrscr();

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
	append();
    }

    display();

    insert_loc();

    display();

    deletee();

    display();

    getch();
}
