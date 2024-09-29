// Online C compiler to run C program online
#include <stdio.h>
struct stack{
    int top,size;
    int *s;
};
int push(struct stack *s1,int x){
    s1->s[++s1->top]=x;
}
int pop(struct stack *s1,struct stack *s2)
{
    if(s2->top==-1){
        while(s1->top!=-1)
            {
                push(s2,s1->s[s1->top--]);
            }
        pop(s1,s2);
        
    }
    else
        {
        return s2->s[s2->top--];
        }
    
}
int enq(struct stack *s1,int x)
{
    push(s1,x);
    
}
int deq(struct stack *s1,struct stack *s2)
{
    pop(s1,s2);
    
}

int main() {
    // Write C code here
    int st1[5],st2[5];
    struct stack s1={-1,5,st1},s2={-1,5,st2};
    
    printf("Try programiz.pro");
    int choice;
    do{printf("push\n");
        printf("pop\n");
        printf("Enter :");
        scanf("%d",&choice);
        if(choice==1){
            int x;
            printf("Enter push n:");
            scanf("%d",&x);
            enq(&s1,x);}
        else if(choice==2)
            printf("%d",deq(&s1,&s2));
        else
            break;
    }while(choice<=3);

    return 0;
}