#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *prev,*next;
};

struct node* create(int data){
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->prev=newnode->next=NULL;
return newnode;
}

struct node* insertend(struct node* head,int data){
struct node* newnode=create(data);
if (!head){
head=newnode;
}
else{
struct node* head2=head;
while(head2->next!=NULL)
	head2=head2->next;
head2->next=newnode;
newnode->prev=head2;


}
return head;
}
struct node* travesal(struct node* head){
while(head!=NULL)
	{
		printf("%d",head->data);
		if(head->next!=NULL)
			head=head->next;
		else
			return head;
	}

}
struct node* partition(struct node* low,struct node* high){
struct node* pivot=low;
struct node* i=low;
for(struct node* j=low->next;j!=high->next;j=j->next){
	if(j->data<pivot->data)
		{
			i=i->next;
			int temp=i->data;
			i->data=j->data;
			j->data=temp;
		}

}
int temp=i->data;
i->data=pivot->data;
pivot->data=temp;
return i;
}

void quick(struct node* low, struct node* high){
//struct node *middle=partition(low,high);
if (high!=NULL&&low!=high&&low!=high->next){
	struct node* middle=partition(low,high);
	quick(low,middle->prev);
	quick(middle->next,high);}

}

int main(){
struct node *head=NULL,*last=NULL;
do{
int n;
char ch;
scanf("%d%c",&n,&ch);
head=insertend(head,n);
if(ch=='\n'||ch=='\r')
	break;


}while(1);
last=travesal(head);
printf("\n");
//last=head->next->next->next;
quick(head,last);
last=travesal(head);
}


