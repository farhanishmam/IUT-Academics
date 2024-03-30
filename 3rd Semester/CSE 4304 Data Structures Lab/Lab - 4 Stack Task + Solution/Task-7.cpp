#include<bits/stdc++.h>
using namespace std;

int check_order(char c)
{
    if(c=='^') return 3;
    else if(c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}

int main(void)
{
    int n;
    cin>>n;
    for(int k=0;k<n;k++)
    {
        string str;
        stack<char> stk;
        cin>>str;
        for(int i=0;i<str.size();i++)
        {
            if(isalpha(str[i]))
            {
                cout<<str[i];
            }
            else if(str[i]=='(')
            {
                stk.push('(');
            }
            else if(str[i]==')')
            {
                for(;;)
                {
                    if(stk.top()=='(')
                    {
                        stk.pop();
                        break;
                    }
                    else
                    {
                        cout<<stk.top();
                        stk.pop();
                    }
                }
            }
            else
            {
                if(stk.empty()||stk.top()=='(')
                {
                    stk.push(str[i]);
                }
                else if(check_order(str[i])<=check_order(stk.top()))
                {
                    while(stk.top()!='('||!stk.empty())
                    {
                        cout<<stk.top();
                        stk.pop();
                    }
                    cout<<str[i];
                }
                else
                {
                    stk.push(str[i]);
                }
            }
        }
        while(!stk.empty())
        {
            cout<<stk.top();
            stk.pop();
        }
        cout<<endl;
    }
}
