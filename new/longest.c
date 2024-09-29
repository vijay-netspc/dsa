#include<stdio.h>
int main(){
char s[10],ch;
int top=-1;
int count=0;
while(1){
scanf("%c",&ch);
if(ch=='\n'||ch=='\r'){
	break;
}
if (ch==')' && top!=-1)
{
top--;
count+=2;
}
else if(ch=='(')
top++;
}
printf("%d",count);
}
