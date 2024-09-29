#include <stdio.h>
#include <ctype.h>
int top = -1;
int isempty(int size) {
    return (top == -1);
}
int isfull(int size) {
    return (top == size - 1);
}
void push(char arr[], int size, char element) {
    if (isfull(size)) {
        printf("Stack Overflow\n");
    } else {
        top++;
        arr[top] = element;
    }
}
char pop(char arr[], int size) {
    if (isempty(size)) {
        return '\0';
    } else {
        return arr[top--];
    }
}
char peek(char arr[], int size) {
    if (isempty(size)) {
        return '\0';
    } else {
        return arr[top];
    }
}
int main(){
    int size=100;
    char string[100];
    scanf("%s",string);
    char stack[100];
    for(int i=0;string[i]!='\0';i++){
        if (string[i]==')'){
            int count=0;
            while(!isempty(size) && peek(stack,size)!='('){
                pop(stack,size);
                count++;
            }
            if (count<=1){
                printf("-1");
                return -1;
            }
            pop(stack,size);
        }
        else{
            push(stack,size,string[i]);
        }
    }
    printf("0");
    return 0;
}
