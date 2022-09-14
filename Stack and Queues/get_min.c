#include<stdio.h>
#include<stdlib.h>
#include<limit.h>

typedef struct stack{
    int array[100];
    int top;
}stack;

int min = INT_MAX;

void push(stack *s, int x)
{
    s->array[s->top++];
    if (x > min)
    {
        min = x;
    }
}

int push(stack *s)
{
    int popped = s->array[--(s->top)];
    return popped;
}

int find_max()
{
    return min;
}