// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*top=NULL;

void push(){
  
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->top=NULL;
    
    temp->next=top;
    top=temp;
    
}











int main() {
    // Write C code here
    printf("Start small. Ship something.");

    return 0;
}
