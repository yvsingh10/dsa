#include<stdio.h>

#define SIZE 4
void enqueue(int x);
void dequeue();
void display();
int f= -1;
int R= -1;
int queue[SIZE];

void enqueue(int x){
    if (R== SIZE-1){
        printf("Queue is full.");
              return;
        
    }
    else{
        R=R+1;
        queue[R]=x;
        if(f== -1){
             f =0;
            
        }
    }
}


void dequeue(){
    int num;
    if(f==-1){
        printf("Queue is empty.");
        return;
    }
    else{
        num=queue[f];
        printf("Deleted element is:%d",num);
        f=f+1;
        printf("\n");
    }
    if(f>R){
         f= -1;
         R= -1;
    }
}

void display(){
    if(f== -1){
        printf("Queue is empty.");
        return;
    }
    else{
        int i;
        printf("Queue elements are:");
        for(i=f;i<=R;i++){
            printf("%d\n",queue[i]);
        }
        
    }
}
int main(){
    enqueue(7);
    enqueue(9);
    enqueue(5);
    enqueue(4);
    dequeue();
    display();
    
    return 0;
    
}
