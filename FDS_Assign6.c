#include <stdio.h>

int maxsize = 20;
struct stack{
    int top;
}stack[5];


int isFull(struct stack* stack){
    if(stack->top == maxsize-1)
        return 1;
    else
        return 0;
}

void push(char item){
    if(!isFull(stack)){
        stack->top = stack->top+1;
        stack->top=item;
        printf("%c pushed to stack \n", item);
    }
    else
        printf("Stack is full");
}

int isEmpty(struct stack* stack)
{
    return stack->top == -1;
}

char pop(struct stack* stack){
    char temp;
    if (!isEmpty(stack)){
        temp = stack->top;
        stack->top = stack->top-1;
        return(temp);
    }
    else
        printf("Stack is empty");
        return 0;
}

int icp(char ch){
    if (ch == '+' || ch == '-')
        return 1;
    if( ch =='*' || ch == '/')
        return 2;
    if (ch =='^')
        return 4;
    if ( ch == '(')
        return 5;
    else  
        return 0;
}

int isp(char ch){
    if (ch == '+' || ch == '-')
        return 1;
    if( ch =='*' || ch == '/')
        return 2;
    if (ch =='^')
        return 3;
    else  
        return 0;
}

int main(){

    push('a');
}