#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
 int data ;
 struct node*left;
 struct node*right;
 };

struct node*root=NULL;

void append()
{
  struct node*temp,*p;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter data :");
  scanf("%d",&temp->data);
  temp->left=NULL;
  temp->right=NULL;

  if(root==NULL)
  {
    root = temp;
  }
  else
  {
   p=root;
   while(p->right!=NULL)
   {
     p=p->right;
   }
   p->right=temp;
   temp->left=p;
  }
}

void display()
{
  struct node*p=root;
  printf("\nList: ");
  while(p!=NULL)
  {
    printf("%d->",p->data);
    p=p->right;
  }
  printf("NULL\n");
}

int length()
{
 int count =0;
 struct node*p =root;
 while(p!=NULL)
 {
   count++;
   p=p->right;
 }
 return count;
}
void main()
{
 int n,i;
 clrscr();
 printf("Enter the no of nodes: ");
 scanf("%d",&n);

 for(i=0;i<n;i++)
 {
   append();
 }
 display();
 getch();
}
