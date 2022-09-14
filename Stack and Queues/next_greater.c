#include <stdio.h>
#include<stdlib.h>

int max_size = 100;
typedef struct stack{
    int top;
    int array[100];
}stack;

int ans[5];

void push(int data, stack *s)
{ 
    s->array[++(s->top)] = data;
}

int pop(stack *s)
{
    int popped_data = s->array[s->top];
    (s->top)--;

    return popped_data;
}

int isEmpty(stack *s)
{
    int n;
    if(s->top < 0)
    {
        n = 0;
        return n;
    }

    return 1;
}

void next_greater_element(int x[], stack *s)
{
    
    int size = sizeof(x) / sizeof(x[0]);
    //int ans[size];
    for(int i = size -1; i > 0; i++)
    {
        while(!isEmpty(s) && s->array[s->top] <= x[i])
        {
            pop(s);
        }

        if(isEmpty(s))
            ans[i] =  -1;

        else
        {
            ans[i] = s->array[s->top];
        }

        push(s, x[i]);

    }

    //return ans;
}

int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    int arr[] = {6, 8, 0, 1, 3};
    next_greater_element(arr, s);
    for(int i =0; i< 5; i++)
    {
        printf("%d ", ans[i]);
    }


}