#include<bits/stdc++.h>
using namespace std;

//arr_in means input array
//begin means beginning index of the array
//end means ending index of the array
void init(const int arr_in[],int node, int begin, int end, int tree[])
{

    if(begin == end)
    {
        //leaf_node found
        tree[node] = arr_in[begin];
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (begin + end)/2;

    init(arr_in,left,begin,mid, tree);
    init(arr_in,right,mid+1,end,tree);
    tree[node] = tree[left] + tree[right];
}

//in our query i means the index from which we start calculating the sum
//and j means the index upto which we calculate the sum
int query_sum(int node, int begin, int end, int i, int j, int tree[])
{
    if(i>end || j<begin)//out of range
    {
        return 0;
    }
    if(begin>= i && end<=j)//complete intersection
    {
        return tree[node];
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (begin + end)/2;

    int p1 = query_sum(left,begin,mid,i,j, tree);
    int p2 = query_sum(right,mid+1,end,i,j, tree);
    return p1+p2;
}

void update(int node, int begin, int end, int i, int new_value, int tree[])
{
    if(i>end || i<begin)
    {
        return; //out of range
    }
    if(begin>= i && end<=i)
    {
        tree[node] = new_value; //position is found
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (begin + end)/2;

    update(left, begin, mid, i, new_value, tree);
    update(right, mid+1, end, i , new_value, tree);

    tree[node] = tree[left] + tree[right];
}

int main(void)
{
    const int arr_size = 8;
    int arr[arr_size + 1] = {0,5,6,1,2,3,5,6,9};
    int tree[arr_size*2];
    init(arr,1,1,arr_size,tree);
    cout<<"Built tree: "<<endl;
    for(int i=1;i<arr_size*2;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    cout<<"Select the range for query"<<endl;
    int a,b;
    cin>>a>>b;
    cout<<"The sum within the given range is: "<<query_sum(1,1,arr_size,a,b, tree)<<endl;
    cout<<"Insert the position of the value you want to update and the updated value: "<<endl;
    cin>>a>>b;
    update(1,1,arr_size,a,b, tree);
    cout<<"Updated tree: "<<endl;
    for(int i=1;i<arr_size*2;i++)
    {
        cout<<tree[i]<<" ";
    }
}