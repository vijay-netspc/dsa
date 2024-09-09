#include<stdio.h>
int size=6,front=0,rear=0,top=-1;
int enq(int *q,int x)
{
if((rear+1)%size==front)
	printf("erroro");
else{q[rear]=x;
rear=(rear+1)%size;
}
}
int dq(int *q)
{
if(front==rear)
{
printf("erru");
}
else
{
int temp=q[front];
front=(front+1)%size;
return temp;
}
}
int main()
{
int qt[5]={1,2,3,4,5},q[6];
int k=3,s[k];
int i1=0;
while(i1<5)
{
enq(q,qt[i1]);
i1++;
printf("%d  %d\n",front,rear);
}
while(top+1!=k)
{
s[++top]=dq(q);
}
int i=0;
while(i<k)
{
enq(q,s[top--]);
i++;
}
i=0;
while(i<size-1-k)
{
enq(q,dq(q));
i++;
}
//while((rear+1))
while(front!=rear)
	printf("\n%d.",dq(q));

}
