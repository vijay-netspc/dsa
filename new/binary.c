// Online C compiler to run C program online
#include <stdio.h>
int front=0,rear=1,size=6;
int enq(int *q,int x)
{
    q[rear]=x;
    rear=(rear+1)%size;
}
int deq(int *q)
{
   int x=q[front];
    front=(front+1)%size;
    return x;
    
}
int main() {
    // Write C code here
    printf("Try programiz.pro");
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    int q[n+1];
    q[0]=1;
    for(int i=0;i<n;i++)
    {
        int temp=deq(q);
        printf("%d ",temp);
        enq(q,temp*10);
        enq(q,temp*10+1);
    }
    
    

    return 0;
}