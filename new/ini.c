#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int size,top=-1;
int isfull(char *s){
if(top+1==size)
	return 1;
return 0;
}
int isempty(char *s){
if(top==-1)
	return 1;
return 0;
}
void push(char *s,char ch){
	s[++top]=ch;
}
char pop(char *s){
	return s[top--];
}
char peek(char *s){
	return s[top];
}
int cb(char *exp,char *s){
//int count=0;
for(int i=0;exp[i]!='\0';i++)
{
	if(exp[i]=='(')//{
		push(s,exp[i]);
//		count++;}
	else if(exp[i]==')')

		{ if(isempty(s))
			return 0;
		pop(s);
//		count--;
		
}

	
}
//if(count==0)
if(isempty(s))
	return 1;
return 0;
}
int precedence(char ch){
switch(ch){
case '+': case '-': return 1;
case '/': case '*': return 2;
default :return 0;
}

}
char *initopost(char *exp,char *s){
int j=0;
char *post=malloc(sizeof(char)*30);
for(int i=0;exp[i]!='\0';i++)
{
if (exp[i]=='(')
	push(s,'(');
else if(exp[i]==')')
	{
	while(!isempty(s)&&peek(s)!='(')
		post[j++]=pop(s);
pop(s);	
}
else if(isdigit(exp[i])){
post[j++]=exp[i];

}	
else
{
while(!isempty(s) && precedence(peek(s))>=precedence(exp[i]))
	post[j++]=pop(s);
push(s,exp[i]);
}

}
while(!isempty(s))
	post[j++]=pop(s);
return post;
}
int main(){
char exp[30];
scanf("%s",exp);
size=strlen(exp);
char s[size];
if(cb(exp,s)==1)
	printf("yes");
else
	printf("no");
char *post=malloc(sizeof(char)*30);
post=initopost(exp,s);
printf("%s",post);
}


