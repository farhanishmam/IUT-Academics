#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int count = 0;
    string str;
    cin>>str;
    stack<char> s;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
			s.push(str[i]);
        else
        {
            if(!s.empty()&& s.top()=='(')
				s.pop();
            else count++;
        }
    }
    cout<<count<<endl;
}
