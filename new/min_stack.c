// Online C compiler to run C program online
#include <stdio.h>
int top=-1,t2=-1,size=5;
int isfull(int *s){
if (top+1==size)
    return 1;
else
    return 0;}
int isempty(int *s)
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int push(int *s,int x)
{
    s[++top]=x;
    
}
int pop(int *s)
{
    return s[top--];
    
}
int main() {
    // Write C code here
    printf("Try programiz.pro");
    int temp,s[5],choice,min=0;
    do{
        printf("push\npop\nview\n");
        scanf("%d",&choice);
        if (choice==1){
            if(isfull(s)){
                printf("noo");
                continue;}
            scanf("%d",&temp);
            if(top==-1)
                {push(s,temp);
                min=temp;}
            else if(temp<min){
                push(s,temp*2-min);
                min=temp;}
            else    
                push(s,temp);
        }
        else if(choice==2){
            if(isempty(s))
                {
                    printf("erru");
                    continue;
                }
            temp=pop(s);
            if(temp<min){
                printf("pop:%d\n",min);
                min=2*min-temp;
            }
            else
                printf("pop %d\n",temp);
        }
        else if(choice==3)
            printf("view:%d\n",min);
        else
            break;
        
    }while(choice<5);
return 0;
}