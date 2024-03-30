#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long int hash_function(string s)
{
    int key = 769; //I chose 769 because it has lower value and error rate
    //other primes can have lower error rate but has higher value
    int modulo = 1000000007;//10^9 + 7
    long long int hash = 0;
    for(int i=0;i<s.size();i++)
    {
        hash += s[i]*pow(key,i);
        if(hash > pow(2,63))
        {
            hash = hash%modulo;
        }
    }
    return hash;
}

vector<int> search(string input, string pattern)
{
    vector<int> v;
    long long int hash_pattern = hash_function(pattern);
    int n = input.size();
    int m = pattern.size();
    for(int i=0;i<=n-m;i++)
    {
        long long int hash_inp = hash_function(input.substr(i, i+m-1));
        if (hash_inp == hash_pattern)
        {
            if(input.substr(i,i+m-1) == pattern)
            {
                v.push_back(i);
            }
        }
    }
    return v;
}

int main(void)
{
    string str1, str2;
    getline(cin, str1);
    getline(cin,str2);
    vector<int> v = search(str1,str2);
    if(v.empty())
    {
        cout<<"Pattern not found"<<endl;
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << "Pattern found at: "<<v[i] <<endl;
        }
    }
}
