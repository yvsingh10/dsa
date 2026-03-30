#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *ROOT = NULL;

// ✅ Function declaration
int length();

// ✅ Append function
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

// ✅ Display function
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

// ✅ Length function
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

// ✅ Insert at location
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

    // insert at beginning
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

// ✅ Main function
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

    getch();
}