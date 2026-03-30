#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void main()
{
    struct node *root = NULL, *temp, *newnode;
    int n, i, count = 0;

    clrscr();

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Creating linked list
    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);

        newnode->link = NULL;

        if(root == NULL)
        {
	    root = newnode;
        }
        else
	{   temp=root;
            temp->link = newnode;
            temp = newnode;
        }
    }

    // Counting nodes with value = 10
    temp = root;

    while(temp != NULL)
    {
        if(temp->data == 10)
        {
            count++;
        }
        temp = temp->link;
    }

    printf("\nTotal nodes containing value 10 = %d", count);

    getch();
}