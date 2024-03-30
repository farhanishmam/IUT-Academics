#include<bits/stdc++.h>
#define BIG_NUMBER 99999999
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
    //we return the least value
    if(tree[left]>tree[right])
    {
        tree[node] = tree[right];
    }
    else
        tree[node] = tree[left];
}
//in our query i means the index from which we start calculating the sum
//and j means the index upto which we calculate the sum
int query_sum(int node, int begin, int end, int i, int j, int tree[])
{
    if(i>end || j<begin)
    {
        		     //If outside range then we can never return that number. So, we
        return INT_MAX;     //should return biggest possible integer number which when compared with p1
                            //or p2 will always get omitted and p1 or p2 will get returned only
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
    //we return the least value
    if(p1>p2) return p2;
    else return p1;
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
        int a,b;
        cin>>a>>b;
        cout<<query_sum(1,1,arr_size,a,b, tree)<<endl;
    }
}