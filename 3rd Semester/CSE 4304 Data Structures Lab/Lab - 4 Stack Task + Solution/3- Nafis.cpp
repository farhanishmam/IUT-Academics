#include<bits/stdc++.h>
using namespace std;
stack<char>sk;

void print()
{
    while(!sk.empty())
    {
        cout << sk.top();
        sk.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    string s;

    cin >> n;
    while(n--)
    {
        cin >> s;
        for(auto u : s)
            sk.push(u);
        print();
    }
}
