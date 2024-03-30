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
    if(i>end || j<begin)
    {
        return 0;
    }
    if(begin>= i && end<=j)
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

int update(int node, int begin, int end, int i, int new_value, int tree[])
{
    if(i>end || i<begin)
    {
        return 0; //out of range
    }
    if(begin>= i && end<=i)
    {
        tree[node] = new_value; //position is found
        return 0;
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
    int arr_size,q;
    cin>>arr_size>>q;
    int arr[arr_size + 1];
    int tree[arr_size*2];

    for(int i=1;i<=arr_size;i++)
    {
        cin>>arr[i];
    }
    init(arr,1,1,arr_size,tree);
    for(int i=0;i<q;i++)
    {
        int num;
        cin>>num;
        if(num==1)
        {
            int a;
            cin>>a;
            a++;
            cout<<query_sum(1,1,arr_size,a,a,tree)<<endl;
            update(1,1,arr_size,a,0,tree);
        }
        else if(num==2)
        {
            int a,inc;
            cin>>a>>inc;
            a++;
            int val = query_sum(1,1,arr_size,a,a,tree);
            update(1,1,arr_size,a,val+inc,tree);
        }
        else if(num==3)
        {
            int a,b;
            cin>>a>>b;
            a++;
            b++;
            cout<<query_sum(1,1,arr_size,a,b,tree)<<endl;
        }
    }
}