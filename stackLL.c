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
    temp->next=top;
    top=temp;
    
}
void pop(){
    top=top->next;
}

void peek(){
    printf("%d",top->data);
}

void traverse(){
    struct node *temp;
    while(temp->next!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
        
    }
}

int main()
{
    push();
    push();
    push();
    pop();
    peek();
    traverse();
    return 0;
}
