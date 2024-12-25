#include <stdio.h>
#include <ctype.h>
#include <string.h>

char infix[100], postfix[100];
int top = -1;

void push(char c)
{
    infix[++top] = c;
}
char pop()
{
    return infix[top--];
}
int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}
void convert()
{
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else if (infix[i] == '(')
        {
            push(infix[i++]);
        }
        else if (infix[i] == ')')
        {
            while (infix[top] != '(')
                postfix[j++] == pop();
            pop();
            i++;
        }
        else
        {
            while (top >= 0 && precedence(infix[top]) >= precedence(infix[i]))
                postfix[j++] = pop(); // pop the operator with higher precedence
            push(infix[i++]); // remove the lparn
        }
    }
    while (top >= 0)
        postfix[j++] = pop(); // pop the remaining operators
    postfix[j] = '\0';
}

void main()
{
    printf("Enter INFfix exp:");
    scanf("%s", infix);
    convert();
    printf("postfix exp:%s", postfix);
}