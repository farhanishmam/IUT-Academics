#include <iostream>
#include <unordered_map>
using namespace std;


int main(void)
{
    int m,n;
    cin>>m>>n;
    if((m>=100||n>m)||(m<1||n<1))
    {
        cout<<"Invalid Input"<<endl;
    }
    else
    {
        int label = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++)
        {
            int a;
            cin>>a;
            mp[a]++;
        }
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(mp[a]==0)
            {
                label = 1;
            }
        }
        if(label) cout<<"b_array is not a subset of a_array"<<endl;
        else cout<<"b_array is a subset of a_array"<<endl;
    }

}