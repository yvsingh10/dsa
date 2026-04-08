#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *ROOT = NULL;

void append();
void display();
void reverse();


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


void reverse()
{
    struct node *prev = NULL, *curr, *next;

    if(ROOT == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    curr = ROOT;

    while(curr != NULL)
    {
        next = curr->link;   // store next
        curr->link = prev;   // reverse link
        prev = curr;         // move prev
        curr = next;         // move curr
    }

    ROOT = prev;

    printf("\nReversed List :\n");
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

    reverse();   

    display();   

    getch();
}
