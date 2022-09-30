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

int diameter(node *root)
{
    if(root == NULL)
        return 0;
    
    int left_height = height(root->left);
    int right_height = height(root->right);

    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    return max(left_height + right_height + 1, max(left_diameter, right_diameter));
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
    cout << "Diameter of tree is " << diameter(root);
    return 0;
}