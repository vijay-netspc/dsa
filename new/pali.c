#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
char data;
struct node *prev,*next;
};
struct node * create(char data){
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->prev=newnode->next=NULL;
}

struct node * insertend(struct node *head,char data){
//struct node *head=*temp;
struct node *newnode=create(data);
if(!head){
head=newnode;
}
else{
struct node *head2=head;
while(head2->next!=NULL){
head2=head2->next;
}
head2->next=newnode;
newnode->prev=head2;
}
return head;
}
void travesal(struct node *head){
while(head!=NULL){
printf("%c",head->data);
head=head->next;

}
}
void travesalend(struct node *head){
while(head->next!=NULL){
head=head->next;}
while(head!=NULL){
printf("%c",head->data);
head=head->prev;
}
}
int ispali(struct node *head){
if(!head)
	return 1;
struct node *last=head;
while(last->next!=NULL){
last=last->next;
}
while(head!=NULL){
printf("%c%c\n",head->data,last->data);
if(head->data!=last->data){
return 0;
}
head=head->next;
last=last->prev;
}
return 1;
}
int main(){
char str[30];
struct node *head=(struct node*)NULL;
while(1){
char ch;
scanf("%c",&ch);
if(ch=='\n'||ch=='\r'){
break;}
head=insertend(head,tolower(ch));
}
travesalend(head);
printf("\n");
if (ispali(head)==1){
printf("yes");

}
else{
printf("no");
}
}
