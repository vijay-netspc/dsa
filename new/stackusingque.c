// Online C compiler to run C program online
#include <stdio.h>
int size,qc=1;
struct q{
    int front,rear,*que;
    
    
};
int push(struct q *q1,int x)
{

    q1->que[q1->rear]=x;
    q1->rear=(q1->rear+1)%size;
   // printf("\n%d %d",q1->front,q1->rear);
    //printf("\n%d",q1->que[q1->rear-1]);
    
}
int pop(struct q *q1,struct q *q2){
    // if(q2->front!=q2->rear){//printf("h%d %d\n",q2->front,q2->rear);
    //     return q2->que[q2->front++];
        
    // }
    // if(q1->front+1==q1->rear){//printf("%d %d\n",q1->front,q1->rear);
    //     return q1->que[q1->front++];}
    while((q1->front+1)%size!=q1->rear)
        {
            q2->que[q2->rear]=q1->que[q1->front];
            q2->rear=(q2->rear+1)%size;
            q1->front=(q1->front+1)%size;
        }
    int temp=q1->que[q1->front];
    q1->front=(q1->front+1)%size;
    return temp;
    
}
int main() {
    // Write C code here
    printf("Try programiz.pro");
    printf("\n Enter the stack size:");
    scanf("%d",&size);
    int que1[size],que2[size];
    struct q q1={0,0,que1},q2={0,0,que2};
    int choice;
    do{
    printf("1.push,2.pop\nenter:");
    scanf("%d",&choice);
    if(choice==1)
    {   int x;
        printf("\nEnter push num:");
        scanf("%d",&x);
        push(&q1,x);
        
    }
    if(choice==2)
    {
        printf("%d\n",pop(&q1,&q2));
        if (q1.front==q1.rear){
        struct q temp=q1;
        q1=q2;
        q2=temp;}
    }
        
    }while(choice<3);
    

    return 0;
}