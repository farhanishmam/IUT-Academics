#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, x, y;
    string s;
    stack<int>sk;
    cin >> t;
    while(t--)
    {
        while(!sk.empty())
            sk.pop();
        cin >> s;
        for(auto u : s)
        {
            if(u >= '0' && u <= '9')
                sk.push(u-'0');
            else
            {
                x = sk.top();
                sk.pop();
                y = sk.top();
                sk.pop();

                if(u == '+')
                    sk.push(x+y);
                if(u == '-')
                    sk.push(y-x);
                if(u == '*')
                    sk.push(x*y);
                if(u == '/')
                    sk.push(y/x);
            }
        }
        cout << sk.top() << endl;
    }
}
