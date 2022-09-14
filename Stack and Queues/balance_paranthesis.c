#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    char array[100];
    int top;
}stack;

void push(stack *s, char c)
{
    s->array[s->top++] = c;
}

int pop(stack *s)
{
   char popped =  s->array[--(s->top)];
   return popped;
}

int balance_paranthesis(stack *s, char x[], int size)
{
    char left[] = {'{', '[', '('};
    char right[] = {'}', ']', ')'};

    for (int i = 0; i< size; i++)
    {
        if(x[i] == '[' || x[i] == '{' || x[i] == '(')
            push(s, x[i]);

        else
            {
                char y = pop(s);
                if(y != '(' && x[i] == ')')
                {   
                    printf("1");
                    return 0;
                }
                else if(y != '[' && x[i] == ']')
                    {   ;
                    printf("2");
                    return 0;
                }
                else if(y != '{' && x[i] == '}')
                    {   
                    printf("3");
                    return 0;
                }
            }       
    }

    if (s->top > 0)
        return 0;
    
    else
    {
        printf("Balanced");
        return 1;
    }
}


int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = 0;
    char x[] ="[]{}[";
    balance_paranthesis(s, x, 5);


}
