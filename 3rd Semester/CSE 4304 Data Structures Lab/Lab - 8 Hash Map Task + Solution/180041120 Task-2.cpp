#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
    int m;
    cin>>m;
    if(m<=0 || m>=100)
    {
        cout<<"Invalid Input"<<endl;
    }
    else
    {
        int max_val;
        int max_no = 0;
        unordered_map<int, int> mp;
        for(int i=0;i<m;i++)
        {
            int a;
            cin>>a;
            mp[a]++;
            if(mp[a]>max_no)
            {
                max_val = a;
                max_no = mp[a];
            }
        }
        cout<<"Most frequent element: "<<max_val<<endl;
        cout<<"Frequency: "<<max_no<<endl;
    }
}