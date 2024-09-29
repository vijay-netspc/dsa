#include<stdio.h>
int size=10;
struct queue{
int rear;
int front;
int *que;

};
int q1[10],q2[10];
struct queue Q1={0,0,q1},Q2={0,0,q2};

int isfull(struct queue *q){
if((q->rear+1)%size==q->front)
	return 1;
return 0;
}
int isempty(struct queue *q){
if(q->rear==q->front)
	return 1;
return 0;
}
void Eq(struct queue *q,int data){
q->que[q->rear]=data;
q->rear=(q->rear+1)%size;
}
int Dq(struct queue *q){
int data=q->que[q->front];
q->front=(q->front+1)%size;
return data;
}
void push(int data){
Eq(&Q1,data);

}
int pop(){
while((Q1.front+1)%size!=Q1.rear)
		Eq(&Q2,Dq(&Q1));
return Dq(&Q1);

}
int main(){
//int stack[10];
//struct queue Q1={0,0,(int *)malloc(sizeof(int)*10)},Q2={0,0,(int *)malloc(sizeof(int)*10)};
int ch;
do{

printf("1.push\n2.pop ");
scanf("%d",&ch);
if(ch==1){
	int data;
	printf("data: ");
	scanf("%d",&data);
	push(data);}
else if(ch==2)
	{
//	printf("popped:%d",pop());
	if(isempty(&Q1)){
		printf("underflow");continue;}
	printf("popped:%d ",pop());
	
	struct queue temp=Q1;
	Q1=Q2;
	Q2=temp;
}

}while(ch<3);

}
