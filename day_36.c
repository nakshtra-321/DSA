#include <stdio.h>
#define MAX 100

int queue[MAX];
int front=-1,rear=-1;

void enqueue(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear=(rear+1)%MAX;
        queue[rear]=x;
    }
}

void dequeue(){
    if(front==-1) return;
    if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
}

void display(){
    if(front==-1) return;
    int i=front;
    while(1){
        printf("%d ",queue[i]);
        if(i==rear) break;
        i=(i+1)%MAX;
    }
}

int main(){
    int n,m,x,i;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }

    scanf("%d",&m);

    for(i=0;i<m;i++){
        int temp=queue[front];
        dequeue();
        enqueue(temp);
    }

    display();
    return 0;
}