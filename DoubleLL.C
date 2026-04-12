#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *ROOT = NULL;

void add_begin();
void append();
void display();
int length();
void insert_loc();
void deletee();

void add_begin()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));

    printf("Enter node value you want to add at beginning: ");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;

    if(ROOT==NULL)
    {
        ROOT=temp;
    }
    else{
        temp->right=ROOT;
        ROOT->left=temp;
        ROOT=temp;
    } 
}

void append()
{
    struct node *temp, *p;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right=NULL;

    if(ROOT == NULL)
    {
        ROOT = temp;
    }
    else
    {
        p = ROOT;
        while(p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left=p;
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
        p = p->right;
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
        p = p->right;
    }
    return count;
}

void insert_loc()
{
    int loc, i = 1;
    struct node *temp, *p,*q;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &temp->data);
    temp->left= NULL;
    temp->right=NULL;

    printf("Enter location: ");
    scanf("%d", &loc);

    if(loc == 1)
    {
        temp->right = ROOT;
        ROOT->left = temp;
        ROOT=temp;
        return;
    }

    if(loc <= length())
    {
        p = ROOT;
        while(i < loc - 1)
        {
            p = p->right;
            i++;
        }

        temp->right= p->right;
        q->left = temp;
        p->right=temp;
        temp->left=p;
    }
    else
    {
        printf("Invalid location\n");
    }
}

void deletee()
{
    int loc;
    int i=1;
    struct node*p,*q;

    printf("Enter loc of the node u want to delete: ");
    scanf("%d",&loc);

    if(loc<=length())
    {
        if(loc==1)
        {
            p=ROOT;
            ROOT=ROOT->right;
            q=p->right;
            q->left=NULL;
            p->right=NULL;
            free(p);
        }
        else if(loc==length())
        {
            p=ROOT;
            while(i<loc-1)
            {
                p=p->right;
                i++;
            }
            q=p->right;
            p->right=NULL;
            q->left=NULL;
            free(q); 
        }
        else
        {
            struct node*r;
            p=ROOT;
            while(i<loc-1)
            {
                p=p->right;
                i++;
            }
            q=p->right;
            r=q->right;
            r->left=p;
            p->right=r;
            q->left=NULL;
            q->right=NULL;
            free(q);
        }
    }
    else{
        printf("linked list is out of index\n");
    }
}
void main()
{
    int choice;

    clrscr();

    while(1)
    {
        printf("\n LINKED LIST MENU \n");
        printf("1. Add Begin\n");
        printf("2. Append\n");
        printf("3. Display\n");
        printf("4. Insert at location\n");
        printf("5. Delete from location\n");
        printf("6. Length\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {   
            case 1:
                add_begin();
                break;

            case 2:
                append();
                break;

            case 3:
                display();
                break;

            case 4:
                insert_loc();
                break;

            case 5:
                deletee();
                break;

            case 6:
                printf("Length = %d\n", length());
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
