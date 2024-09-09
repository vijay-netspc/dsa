#include<stdio.h>
int top=4,size=5;
int ssorted_insert(int *stack,int x);
int push(int *stack,int x)
{
stack[++top]=x;

}
int pop(int *stack)
{
if(top ==-1)
	return -1;
else{
	int temp=stack[top];
	top--;
	return temp;
}

}
int sort_stack(int *stack)
{
if (top!=-1)
{
	int temp1=pop(stack);
	sort_stack(stack);
	ssorted_insert(stack,temp1);
}
}
int ssorted_insert(int *stack,int x)
{
if (top==-1 || stack[top]>x)
{	push(stack,x);
	return 0;
}
else
{	int temp=pop(stack);
	ssorted_insert(stack,x);
	push(stack,temp);

}

}
int main()
{
int stack[5]={3,2,-1,0,5};
sort_stack(stack);
while(top!=-1)
	printf("%d",pop(stack));
}
