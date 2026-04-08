#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *ROOT = NULL;

void find_middle()
{
    struct node *slow, *fast;

    if(ROOT == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    slow = fast = ROOT;

    while(fast != NULL && fast->link != NULL)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    printf("\nMiddle element = %d\n", slow->data);
}


void append()
{
    struct node *temp, *p;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data );
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

    find_middle();

    getch();
}
