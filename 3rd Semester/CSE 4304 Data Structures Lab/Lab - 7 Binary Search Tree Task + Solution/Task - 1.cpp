#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* insert(Node *root, int data, bool &flag)
{
    if(root == nullptr)
    {
        Node *newnode = new Node;
        newnode -> data = data;
        newnode -> right =  nullptr;
        newnode -> left = nullptr;
        return newnode;
    }
    if(abs(root -> data - data) <= 3)
    {
        flag = true;
        return root;
    }
    if(root -> data > data)
        root -> left = insert(root -> left, data, flag);
    else
        root -> right = insert(root -> right, data, flag);
    return root;
}

void inorder(Node *root)
{
    if(root == nullptr)
        return;
    inorder(root -> left);
    cout<<(root -> data)<<" ";
    inorder(root -> right);
}

int main()
{
    Node *root = nullptr;
    bool flag = false;
    int data, x;
    for(;;)
    {
        cin >> data;
        if(data == -1)
            break;
        root = insert(root, data, flag);
        inorder(root);
        if(flag == true)
        {
            flag = false;
            cout << "(Reservation failed)";
        }
        cout<<endl;
    }
}
