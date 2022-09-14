#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int array[100];
    int top1;
    int top2;
}stack;

void push1(int x, stack *s)
{
    s->array[s->top1++] = x;
}

void push2(int x, stack *s)
{
    s->array[s->top2--] = x;
}

int pop1(stack *s)
{
    if(s->top1 > 0)
    {
        int x;
        s->top1 = s->top1 - 1 ;
        x = s->array[s->top1];
        return x;
    }

    return -1;
}

int pop2(stack *s)
{
    if(s->top2 < 99)
    {
        int x;
        s->top2 = s->top2 + 1;
        x = s->array[s->top2];
        return x;
    }
    return -1;
}

void display(stack *s)
{
    for(int i =1; i<100 ;i++)
    {
        printf("%d ",s->array[i]);
    }
}


int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top1 = 0;
    s->top2 = 100-1;
    push2(11, s);
    int rs = pop2(s);
    int sq = pop2(s);
    printf("%d\n",sq);
    //display(s);
}










