#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};
struct node *create(int data){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
return newnode;
}
struct node *insertend(struct node *head,int data){
struct node* newnode=create(data);
if(!head){
head=newnode;
newnode->next=head;
}
else{
struct node* head2=head;
head2=head2->next;
while(head2!=NULL &&  head2->next!=head){
head2=head2->next;
}
newnode->next=head;
head2->next=newnode;

}

return head;
}
void travesal(struct node *head){
if(!head){
return ;}
struct node*head2=head;
do{
printf("%d",head->data);
head=head->next;
}while(head2!=head);
}
struct node * killat(struct node* head,int pos){
int curr=1;
while(curr+1!=pos){
head=head->next;
curr++;
}
struct node *temp=head->next;
head->next=head->next->next;
free(temp);
return head->next;
}

int main(){
struct node* head=NULL;
head=insertend(head,1);
head=insertend(head,2);
head=insertend(head,3);
head=insertend(head,4);
head=insertend(head,5);
while(head->next!=head){
printf("%d",head->data);
head=killat(head,3);
}
printf(" %d",head->data);

}
