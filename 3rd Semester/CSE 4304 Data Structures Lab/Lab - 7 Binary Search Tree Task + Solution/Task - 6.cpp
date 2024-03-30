#include<bits/stdc++.h>
using namespace std;

//The complexity of my approach is h^2 where h is the height of tree
//For a large data output this is significantly more efficient than log(n)
//If n = 2^32 then in average scenario the height of tree shouldn't be a lot more than 32, say it is around 50
//Then total time complexity is only 50^2 = 2500 which is a lot lesser than 2^32
//I have seen some approaches where this is done in h time complexity but since those weren't my own approach,
//I decided to try this one. And the code is also easier to understand for me.
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

vector<int> parent_vector(Node* root, int val)
{
    vector<int> v;
    Node* node = node_search(root,val);
    while(node != nullptr)
    {
        v.push_back(node->data);
        node = node->par;
    }
    return v;
}

int max_node(Node* root, int x, int y)
{
    vector<int> vec1 = parent_vector(root,x);
    vector<int> vec2 = parent_vector(root,y);
    int mx = -1;
    int flag = 0;
    int pos1,pos2;
    for(int i=0;i<vec1.size();i++)
    {
        for(int j=0;j<vec2.size();j++)
        {
            if(vec1[i] == vec2[j])
            {
                pos1 = i;
                pos2 = j;
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    for(int i=0;i<=pos1;i++)
    {
        mx = max(vec1[i],mx);
    }
    for(int i=0;i<=pos2;i++)
    {
        mx = max(vec2[i],mx);
    }
    return mx;
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
        if(flag)
        {
            flag = false;
            cout << "(Reservation failed)"<<endl;
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<max_node(root, a,b)<<endl;
    }
}