#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void mirror_recurssive(node *root)
{
    if (root == NULL)
        return;

    else
    {
        mirror_recurssive(root->left);
        mirror_recurssive(root->right);

        node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void mirror_iterative(node *root)
{
    if (root == NULL)
        return;

    else
    {
        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *current = q.front();
            q.pop();

            node *temp = current->left;
            current->left = current->right;
            current->right = temp;

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    cout << "Inorder traversal of tree is " << endl;
    inorder(root);
    cout << endl;
    mirror_recurssive(root);
    cout << "Inorder traversal of tree after mirror is " << endl;
    inorder(root);
    cout << endl;
    mirror_iterative(root);
    cout << "Inorder traversal of tree after mirror is " << endl;
    inorder(root);
    cout << endl;
    return 0;
}