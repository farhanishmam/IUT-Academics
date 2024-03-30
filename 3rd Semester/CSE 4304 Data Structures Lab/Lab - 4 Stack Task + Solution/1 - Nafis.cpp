#include<bits/stdc++.h>
using namespace std;

int n, t, top = 0, type, val;
int sk[100009];

void print()
{
    cout << "items =";
    for(int i = 1; i <= top; i++)
        cout << sk[i] << " ";
}
int main()
{
    cin >> n >> t;

    while(t--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> val;
            if(top == n)
            {
                cout << "size=" << top << " ";
                print();
                cout << endl;
            }
            else
            {
                top++;
                sk[top] = val;
                cout << "size=" << top << " ";
                print();
                cout << endl;
            }
        }

        if(type == 2)
        {
            top = max(0, top-1);
            if(top == 0)
                cout << "size=0 items=NULL" << endl;
            else
            {
                cout << "size=" << top << " ";
                print();
                cout << endl;
            }
        }
    }
}
