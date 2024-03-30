#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *par;
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
        newnode -> par = nullptr;
        return newnode;
    }
    if(abs(root -> data - data) <= 3)
    {
        flag = true;
        return root;
    }
    if(root -> data > data)
    {
        root->left = insert(root->left, data, flag);
        root->left->par = root;
    }
    else
    {
        root->right = insert(root->right, data, flag);
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
Node* successor(Node* root,int idx)
{
    Node* node = node_search(root,idx);
    if(node->right != nullptr)
        return tree_min(node->right);
    Node* scsr = node->par;
    while(scsr!=nullptr && scsr->right == node)
    {
        node = scsr;
        scsr = scsr->par;
    }
    return scsr;
}
Node* predecessor(Node* root,int idx)
{
    Node* node = node_search(root,idx);
    if(node->left != nullptr)
        return tree_max(node->left);
    Node* prdcsr = node->par;
    while(prdcsr!= nullptr && prdcsr->left == node)
    {
        node = prdcsr;
        prdcsr = prdcsr->par;
    }
    return prdcsr;
}

int main()
{
    Node *root = nullptr;
    Node *node;
    bool flag = false;
    cout<<"Insert the reservations"<<endl;
    for(;;)
    {
		int data;
        cin >> data;
        if(data == -1)
            break;
        root = insert(root, data, flag);
        if(flag == true)
        {
            flag = false;
            cout << "(Reservation failed)"<<endl;
        }
    }

    int q;
    cin>>q;
    while(q--)
    {
		int x;
        cin>>x;     
        node = node_search(root,x);
        if(node == nullptr)
        {
            cout<<"Reservation not found!"<<endl;
            continue;
        }

        node = predecessor(root,x);
        if(node != nullptr)
            cout<<node->data<<" ";
        else
            cout<<"NULL"<<" ";

        node = successor(root,x);
        if(node !=nullptr)
            cout<<node->data<<endl;
        else cout<<"NULL"<<endl;
    }
}