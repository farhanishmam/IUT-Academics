#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *par;
    Node *left;
    Node *right;
    int left_size;
    int right_size;
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
        newnode -> left_size = 0;
        newnode -> right_size = 0;
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
        root->left_size++;
    }
    else
    {
        root->right = insert(root->right, data, flag);
        root->right->par = root;
        root->right_size++;
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


int predecessor_count(Node* root,int idx)
{
    int count = 0;
    Node* node = node_search(root,idx);
    if(node->left != nullptr)
        count += node->left_size;
    Node* prdcsr = node->par;
    while(prdcsr!= nullptr)
    {
        if(prdcsr->data < node->data)
        {
            count += prdcsr ->left_size + 1;
        }
        prdcsr = prdcsr->par;
    }
    return count;
}

int main()
{
    Node *root = nullptr;
    Node *node;
    bool flag = false;
    int data, x;
    cout<<"Insert the reservations"<<endl;
    for(;;)
    {
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
    for(int i=0;i<q;i++)
    {
        int val;
        cin>>val;
        cout<<predecessor_count(root,val)<<endl;
    }
}

