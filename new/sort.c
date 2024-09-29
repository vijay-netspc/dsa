#include<stdio.h>
int top=-1,size;
int push(int *s,int data){
	s[++top]=data;
}
int pop(int *s){
	return s[top--];
}
int isfull(int *s){
return (top+1==size)?1:0;

}
int isempty(int *s){
return (top==-1)?1:0;
}
int peek(int *s){
return s[top];
}
int sortedinsert(int *s,int data){
if(peek(s)<=data)
	{
	int temp=pop(s);
	sortedinsert(s,data);
	push(s,temp);
	}
else
	push(s,data);
}
int sort(int *s){
if(!isempty(s)){
int temp=pop(s);
sort(s);
sortedinsert(s,temp);
}

}

int main(){
int arr[5]={2,3,1,4,5};
int s[5];
size=5;
for(int i=0;i<5;i++)
	push(s,arr[i]);
sort(s);
while(!isempty(s))
	printf("%d",pop(s));

}
