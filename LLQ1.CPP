#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void append();
void display();
struct node{
 int data;
 struct node*link;
 };
struct node*ROOT=NULL;

void main()
{
 append();
 append();
 append();
 append();
 display();
 getch();
}

void append()
{
 struct node*temp;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("Enter the node value:");
 scanf("%d",&temp->data);
 temp->link=NULL;
		if(ROOT ==NULL)
		{
		 ROOT=temp;
		}
		else
		{
		 struct node *p;
		 p=ROOT;
		 while(p->link !=NULL)
		 {
		  p=p->link;
		 }
		 p->link= temp;
		}
}

void display()
{
 struct node *p;
 p=ROOT;
 while(p!=NULL)
 {
  printf("%d->->",p->data);
  p=p->link;
 }
}