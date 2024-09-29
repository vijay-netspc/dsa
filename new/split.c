#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next; 
};
struct node *create(int data){
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
return newnode;
}
struct node *insertend(struct node *head,int data){
struct node *newnode=create(data);
if(!head){
head=newnode;
newnode->next=head;
}
else{
struct node *head2=head;
while(head2->next!=head)
	head2=head2->next;
head2->next=newnode;
newnode->next=head;
return head;
}
}
void travesal(struct node* head){
struct node *head2=head;
do{
printf("%d",head->data);
head=head->next;
}while(head!=head2);
}
struct node* split(struct node* head){
struct node* slow=head,*fast=slow->next;
while(1){
if(fast!=head&&fast->next!=head){
printf("hi\n");
slow=slow->next;
fast=fast->next->next;
}
else
	break;
}
printf("slow:%d fast:%d",slow->data,fast->data);
return slow;
}
int main(){
struct node* head=NULL;
int i=1;
while(i<=5){
head=insertend(head,i);
i++;
}
travesal(head);
struct node *temp=split(head);
struct node *head2=temp->next,*headnew=head2;
while(head2->next!=head)
	head2=head2->next;
head2->next=headnew;
temp->next=head;
travesal(head);
printf("\n");
travesal(headnew);


}
