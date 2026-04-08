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
void swap_nodes();


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


void swap_nodes()
{
    int x, y;
    struct node *p1, *p2, *prev1 = NULL, *prev2 = NULL, *temp;

    if(ROOT == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    printf("Enter first value: ");
    scanf("%d", &x);

    printf("Enter second value: ");
    scanf("%d", &y);

    if(x == y)
    {
        printf("Both values are same, no swap needed\n");
        return;
    }

    p1 = ROOT;
    while(p1 != NULL && p1->data != x)
    {
        prev1 = p1;
        p1 = p1->link;
    }

    p2 = ROOT;
    while(p2 != NULL && p2->data != y)
    {
        prev2 = p2;
        p2 = p2->link;
    }

    if(p1 == NULL || p2 == NULL)
    {
        printf("One or both values not found\n");
        return;
    }

    if(prev1 != NULL)
        prev1->link = p2;
    else
        ROOT = p2;

    if(prev2 != NULL)
        prev2->link = p1;
    else
        ROOT = p1;

    temp = p1->link;
    p1->link = p2->link;
    p2->link = temp;

    printf("\nNodes swapped successfully\n");
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

    swap_nodes();   
    display();      

    getch();
}
