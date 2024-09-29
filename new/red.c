#include<stdio.h>
int top=-1,size=10;
int push(char *s,char data){
s[++top]=data;
return 1;

}
char pop(char *s){
	return s[top--];
}
int main(){
char exp[10],ch,s[10];
while(1){
scanf("%c",&ch);
if(ch=='\n'|| ch=='\r')
	break;
if(ch==')'){
int count=0;
while(top!=-1 && s[top]!='(')
	{ pop(s);
		count++;
}
if(count<=1){
	printf("-1");
	return -1;
}
}
else
{
	push(s,ch);
}

}
printf("0");
}
