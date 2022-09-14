#include <stdio.h>
#include<stdlib.h>

int max_size = 100;
typedef struct stack{
    int top;
    int array[100];
}stack;

void push(int data, stack *s)
{
    if(max_size == top)
    {
        print("Stack full");
        return;
    }
    s->array[s->top++] = data;
}

int pop(stack *s)
{
    if(s->top == -1)
    {
        print("stack empty");
        return;
    }

    int popped_data = array[top];
    top--;

    return popped_data;
}

int main()
{
    stack *stack1 = (stack *)malloc(sizeof(stack));
}
