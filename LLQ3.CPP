#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *root = NULL;

// 🔷 Append Function
void append(int x)
{
    struct node *temp, *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = NULL;

    if(root == NULL)
    {
        root = newnode;
    }
    else
    {
        temp = root;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

// 🔷 Display Function
void display()
{
    struct node *temp;
    temp = root;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

// 🔷 Main Function
void main()
{
    int n, i, x;
    struct node *prev = NULL, *curr, *next;

    clrscr();

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &x);
        append(x);
    }

    printf("\nOriginal Linked List:\n");
    display();

    // 🔷 Reverse Logic
    curr = root;

    while(curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }

    root = prev;

    printf("\nReversed Linked List:\n");
    display();

    getch();
}