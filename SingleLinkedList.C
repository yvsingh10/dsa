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
int length();
void insert_loc();
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

    if(p == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

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
    int l, i = 1;
    struct node *p;

    if(ROOT == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    printf("Enter location to delete: ");
    scanf("%d", &l);

    if(l <= length())
    {
        if(l == 1)
        {
            p = ROOT;
            ROOT = ROOT->link;
            p->link = NULL;
            free(p);
        }
        else
        {
            struct node *q;
            p = ROOT;

            while(i < l - 1)
            {
                p = p->link;
                i++;
            }

            q = p->link;
            p->link = q->link;
            q->link = NULL;
            free(q);
        }
    }
    else
    {
        printf("Invalid location\n");
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
