#include<bits/stdc++.h>
using namespace std;

void print(stack <char> sk)
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
    int t;
    string s, ans;
    map<char, char> mp;
    mp['('] = ')';
    mp['{'] = '}';
    mp['['] = ']';
    stack<char>sk;
    cin >> t;
    getline(cin, s);
    while(t--)
    {
        ans = "Yes";
        while(!sk.empty())
            sk.pop();
        getline(cin, s);
        for(auto c : s)
        {
//            print(sk);
            if(c == '(' || c == '{' || c == '[')
                sk.push(c);
            else if(c == ')' || c == '}' || c == ']')
            {
                if(sk.empty() || mp[sk.top()] != c)
                {
                    ans = "No";
                    break;
                }
                else
                    sk.pop();
            }
        }

        if(!sk.empty())
            ans = "No";
        cout << ans << endl;
    }
}
