#include<stdio.h>
#include<stdlib.h>
struct node{
int co,power;
struct node *next;
};
struct node* create(int co,int power){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->co=co;
newnode->power=power;
newnode->next=NULL;
return newnode;

}
struct node* insertend(struct node* head,int co,int power){
struct node* newnode=create(co,power);
if(!head)
	head=newnode;

else{
struct node* temp=head;
while(temp->next!=NULL)
	temp=temp->next;
temp->next=newnode;
return head;

}}
void travesal(struct node* head){
while(head!=NULL){
	printf("%dx^%d ",head->co,head->power);
	head=head->next;
}}	
struct node* addition(struct node* head1,struct node* head2){
struct node *head3=NULL;
while(head1!=NULL&&head2!=NULL){

if(head1->power==head2->power)
	{
		head3=insertend(head3,head1->co+head2->co,head1->power);
		head1=head1->next;
		head2=head2->next;
	}
else	{
		if(head1->power>head2->power){
			head3=insertend(head3,head1->co,head1->power);
			head1=head1->next;
			}
		else
			{
			head3=insertend(head3,head2->co,head2->power);
			head2=head2->next;
			}
	}

}
if(head1==NULL)
	while(head2!=NULL)
		head3=insertend(head3,head2->co,head2->power);
else
	while(head1!=NULL)
		head3=insertend(head3,head1->co,head1->power);
return head3;
}
int main(){
struct node *head1=NULL;
struct node *head2=NULL;
head1=insertend(head1,3,2);
head1=insertend(head1,2,1);
head1=insertend(head1,5,0);
head2=insertend(head2,1,2);
head2=insertend(head2,3,0);
travesal(head1);
printf("\n");
travesal(head2);
struct node *head3=NULL;
head3=addition(head1,head2);
printf("\n");
travesal(head3);
}
