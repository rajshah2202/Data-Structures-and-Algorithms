#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void reverse_iterative(node** head)
{
    node *prev = NULL;
    node *curr = *head;
    node *next = NULL;

    while(curr != NULL)
    {
        next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

void insert(node **head, int data)
{
    node* new_node = (node *)malloc(sizeof(node));
    new_node -> data = data;
    new_node -> next = *head;
    *head = new_node;
}

int main()
{
    node *head = NULL;
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 9);

    node *temp = head;
    temp = temp->next;
    while(temp == NULL)
    {
        printf("%d ", temp->data);
        temp = temp -> next;
    }
}
