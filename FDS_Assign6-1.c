#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 3
char stack[MAXSIZE];
int top = -1;

int isFull()
{
    if (top == MAXSIZE - 1)
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

void push(char item)
{
    if (!isFull())
    {
        top = top + 1;
        stack[top] = item;
    }
    else
    {
        printf("Stack is Full\n");
    }
}

char pop()
{
    if (!isEmpty())
    {
        char temp = stack[top];
        top = top - 1;
        return temp;
    }
    else
    {
        printf("The stack is empty\n");
        return 0;
    }
}


int icp(char ch)
{
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

int in_post(char inexp[]){
    int k =0;
    int i =0;
    int tkn;
    tkn=inexp[i];
    while(tkn != '\0'){
        if(isalpha(tkn)!=0){
            // postexp[k] = inexp[i];
            k++;
        }
    }   
}


int main()
{
    int choice, cont = 0;
    char element;
    do
    {
        printf("1-Push Element\n");
        printf("2-Pop Element\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the character to be pushed:\n");
            scanf(" %c", &element);
            push(element);
        }
        break;
        case 2:
        {
            element = pop();
            printf("Popped Element:%c\n", element);
        }
        break;
        default:
        {
            printf("INVALID INPUT\n");
        }
        }

        printf("Enter 0 to continue 1 to terminate:");
        scanf("%d", &cont);
    } while (cont == 0);

    return 0;
}