#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 10
int top = -1;
char s[30][30];

int isFull()
{
    if (top == SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char str[SIZE]){
    if(isFull()){
        printf("\nStack is full !");
    }
    else{
        strcpy(s[++top],str);
    }
}

int pop(char str[20]){
    int a;
    if(isEmpty()){
        printf("\nStack is Empty!");
    }
    else{
        strcpy(str,s[top]);
        a = top--;
        return a;
    }
}

void postinfix(char post[SIZE]){
    char s1[SIZE], s2[SIZE], s3[SIZE], temp[SIZE],inf[SIZE];
    for(int i=0; post[i] != '\0'; i++){
        s1[0] = post[i];
        s1[0] = post[i];
        s1[1] = '\0';

        if(isalpha((post[i])!=0)){
            push(s1);
        }
        else{
            pop(s2);
            pop(s3);
            strcpy(inf,"(");
            strcat(inf,s3);
            strcat(inf,s1);
            strcat(inf,s2);
            strcat(inf,")");
            push(inf);
        }
    }
    pop(inf);
    printf("\nThe infix expression is: ");
    printf("\n%s",inf);
}

int calc(int a, int b, char op){
    int ans;
    switch(op){
        case'+':
        ans = a+b;
        break;
        case '-':
        ans = a-b;
        break;
        case '*':
        ans = a*b;
        break;
        case'/':
        ans = a/b;
        break;
        default:;
    }
    return(ans);
}

void eval(char post[SIZE]){
    int op1, op2, ans, z;
    for(int i=0;post[i]!='\0';i++){
        if(isalpha(post[i])!=0){
            printf("\nEnter value of %c", post[i]);
            scanf("%d",&z);
            pushval(z);
        }
        else{
            op1 = pop(s);
            op2 = pop(s);
            ans = calc(op2,op1,post[i]);
            push(ans);
        }
    }
    prinf("\nEvaluaion is: ");
    printf("%d", s[top]);
}



int main()
{
    int choice, cont = 0;
    char element;
    char post[10];
    printf("Enter the expression");
    scanf("%s", post);
    // do
    // {
    //     printf("1-Push Element\n");
    //     printf("2-Pop Element\n");
    //     printf("Enter your choice:\n");
    //     scanf("%d", &choice);
    //     switch (choice)
    //     {
    //     case 1:
    //     {
    //         printf("Enter the character to be pushed:\n");
    //         scanf(" %c", &element);
    //         push(s);
    //     }
    //     break;
    //     case 2:
    //     {
    //         pop(s);
    //         printf("Popped Element:%c\n", element);
    //     }
    //     break;
    //     default:
    //     {
    //         printf("INVALID INPUT\n");
    //     }
    //     }

    //     printf("Enter 0 to continue 1 to terminate:");
    //     scanf("%d", &cont);
    // } while (cont == 0);

    eval(post);

    return 0;
}