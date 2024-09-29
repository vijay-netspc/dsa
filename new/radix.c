#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node* create(int data){
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
return newnode; 
}

struct node* insertend(struct node *head,int data){
struct node* newnode=create(data);
if(! head)
	head=newnode;
else{
	struct node* curr=head;
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=newnode;
}
return head;
}
int getdigit(int data,int exp){
return (data/exp)%10;
}
int main(){
int arr[]={11,3,2,44,21,111,22,8};
int exp=1;
for(int i=0;i<3;i++)
	{
	struct node* buckets[10]={NULL};
	for(int j=0;j<8;j++){
		struct node *head=NULL;
		buckets[getdigit(arr[j],exp)]=insertend(buckets[getdigit(arr[j],exp)],arr[j]);
		
	}int index=0;
	for(int i=0;i<10;i++)
		{
		while(buckets[i]!=NULL)
			{//printf("%d",buckets[i]->data);
			arr[index++]=buckets[i]->data;
			buckets[i]=buckets[i]->next;
			}
		}

exp*=10;
}
for(int i=0;i<8;i++)
	printf("%d ",arr[i]);
}
