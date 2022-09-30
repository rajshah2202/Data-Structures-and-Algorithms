#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int height(node *root)
{
    if(root == NULL)
        return 0;
    
    else
    {
        int left_height = height(root->left);
        int right_height = height(root->right);

        if(left_height > right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }   
}

node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return (temp);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Height of tree is " << height(root);
    return 0;
}