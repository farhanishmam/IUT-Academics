#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height = -1;
};

Node* insert(Node *root, int data)
{
    if(root == nullptr)
    {
        Node *newnode = new Node;
        newnode -> data = data;
        newnode -> right =  nullptr;
        newnode -> left = nullptr;
        return newnode;
    }
    if(root -> data > data)
        root -> left = insert(root -> left, data);
    else
        root -> right = insert(root -> right, data);
    return root;
}

int main()
{
    Node *root = nullptr;
    int data, x;
    for(;;)
    {
        cin >> data;
        if(data == -1)
            break;
        root = insert(root, data);
    }
    queue<Node*> visited;
    visited.push(root);
    root->height = 0;
    int max_height = -1;
    while(!visited.empty())
    {
        Node* current = visited.front();
        if(current->height >max_height)
        {
            max_height = current->height;
        }
        if(current->left!= nullptr)
        {
            current->left->height = current->height + 1;
            visited.push(current->left);
        }
        if(current->right!= nullptr)
        {
            current->right->height = current->height + 1;
            visited.push(current->right);
        }
        visited.pop();
    }
    cout<<max_height;
}
