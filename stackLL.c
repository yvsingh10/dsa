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
    struct node*temp=top;
    top=top->next;
    free(temp);
}

void peek(){
    struct node*temp=top;
    printf("Value of top is:%d",top->data);
}

void traverse(){
    struct node *temp;
    printf("\nStack elements:\n");
    while(temp!=NULL){
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
