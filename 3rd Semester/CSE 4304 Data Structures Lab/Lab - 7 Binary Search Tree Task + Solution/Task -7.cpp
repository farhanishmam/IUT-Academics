#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *par;
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
        newnode -> par = nullptr;
        return newnode;
    }
    if(root -> data > data)
    {
        root->left = insert(root->left, data);
        root->left->par = root;
    }
    else
    {
        root->right = insert(root->right, data);
        root->right->par = root;
    }
    return root;
}
Node* node_search(Node *node,int idx)
{
    if(node == nullptr || node->data == idx)
        return node;
    else if(node->data > idx)
        return node_search(node->left,idx);
    else
        return node_search(node->right,idx);
}
Node* tree_max(Node *node)
{
    if(node->right != nullptr && node!=nullptr)
    {
        return tree_max(node->right);
    }
    else
    {
        return node;
    }
}
Node* tree_min(Node *node)
{
    if(node->left != nullptr && node!=nullptr)
    {
        return tree_min(node->left);
    }
    else
    {
        return node;
    }
}

void delete_leaf(Node *node)
{
    if(node->par->right == node)
    {
        node->par->right = nullptr;
    }
    else //if(node->par->left == node)
    {
        node->par->left = nullptr;
    }
    delete node;
}

void delete_node(Node* root, int val)
{
    Node* node = node_search(root,val);
    //case 1: no child node
    if(node->right == nullptr && node->left == nullptr)
    {
        delete_leaf(node);
        return;
    }
    //case 2:has one child
    else if(node->left == nullptr || node->right == nullptr)
    {
        Node *scsr;
        if (node->left == nullptr)
                scsr = node->right;
        else scsr = node->left;
        scsr->par = node->par;
        if(node->par->right == node)
        {
            node->par->right = scsr;
        }
        else //if(node->par->left == node)
        {
            node->par->left = scsr;
        }
        delete node;
        return;
    }
    //Case 3:Has both children
    else
    {
        Node* scsr = tree_max(node->left);
        node->data = scsr->data;
        delete_leaf(scsr);
    }
}

void level_order(Node* root)
{
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
    cout<<endl;
}

int main()
{
    Node *root = nullptr;
    Node *node;
    int data;
    cout<<"Insert the reservations"<<endl;
    for(;;)
    {
        cin >> data;
        if(data == -1)
            break;
        root = insert(root, data);
    }
    level_order(root);
    int q;
    cin>>q;
    while(q--)
    {
        cin >> data;
        delete_node(root,data);
        level_order(root);
    }
}