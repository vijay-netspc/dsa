#include<stdio.h>
int rear=-1,front=0,size=10;
int getfront(int *s){
if(rear!=front)
	return s[front];
}
int getrear(int *s){
if(rear!=front)
	return s[rear];
}
int main(){
int arr[]={1,23,3,4,5,6,7,8,9,10};
int deq[size];
int k=3;
for(int i=0;i<k;i++)
{
while(rear>=front && arr[i]>=arr[deq[rear]])
	rear--;
deq[++rear]=i;

}
//printf("%d",arr[deq[front]]);
for(int j=k;j<10;j++)
	{printf("%d ",arr[deq[front]]);
	while(rear>=front&&deq[front]<=j-k)
		front++;
	while(rear>=front&&arr[j]>=arr[deq[rear]])
		rear--;
	deq[++rear]=j;
	}
}
