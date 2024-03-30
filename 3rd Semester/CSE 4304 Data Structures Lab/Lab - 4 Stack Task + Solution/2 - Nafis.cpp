#include<bits/stdc++.h>
using namespace std;

void print(deque<int> s)
{
    while(!s.empty())
    {
        cout << s.front() << " ";
        s.pop_front();
    }
}

int main()
{
    int t, type, val;
    deque<int> sk;

    cin >> t;
    while(t--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> val;
            sk.push_back(val);
        }
        else if(!sk.empty())
            sk.pop_back();
        cout << "size =" << sk.size() << " items=";
        if(sk.size() == 0)
            cout << "NULL";
        print(sk);
        cout << endl;
    }
}
