#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
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
    while(!visited.empty())
    {
        Node* current = visited.front();
        cout<< current->data <<" ";
        if(current->left!= nullptr) visited.push(current->left);
        if(current->right!= nullptr) visited.push(current->right);
        visited.pop();
    }
}
