#include<bits/stdc++.h>
using namespace std;


int main(void)
{
    vector<int*> vec;
    int a = 2;
    vec.push_back(nullptr);
    vec.push_back(&a);
    cout<<vec[0]<<" "<<vec[1]<<endl;
}
