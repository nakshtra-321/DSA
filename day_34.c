#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct node *temp;
    int val;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int main()
{
    char exp[50];
    int i=0,a,b,result;

    printf("Enter postfix expression: ");
    fgets(exp,50,stdin);

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i]-'0');
        }

        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
        {
            b = pop();
            a = pop();

            switch(exp[i])
            {
                case '+': result = a + b;
                          break;

                case '-': result = a - b;
                          break;

                case '*': result = a * b;
                          break;

                case '/': result = a / b;
                          break;
            }

            push(result);
        }

        i++;
    }

    printf("Result = %d", pop());

    return 0;
}