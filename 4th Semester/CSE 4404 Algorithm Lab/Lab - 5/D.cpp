//base 128 radix sort
#include <bits/stdc++.h>
using namespace std;

void RadixSort(string str[], int n)
{
    vector<string> arr[128];      //temporary array of string vectors, size from A-Z and a-z
    for(int j=9;j>=0;j--)        //traversing all the character of the string from last to first
                                 // given fixed string length 10
    {
        for(int i=0;i<n;i++)
        {
            arr[str[i][j]].push_back(str[i]);       //pushing the string in the array based on the j-th letter
        }
        int idx = 0;                                //index of the string array where the elements are to be put
        for(int i=0;i<128;i++)
        {
            for(int k=0;k<arr[i].size();k++)        //inserting the strings from temporary array in same order
                                                    //since the algorithm is about stable sorting
            {
                str[idx] = arr[i][k];
                idx++;                              //index is incremented to the next point of the string
            }
        }
        for(int i=0;i<128;i++)
        {
            arr[i].clear();                         //temporary string is cleared for next iteration
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int r=0;r<t;r++)
    {
        int n;
        cin>>n;
        string str[n];
        for(int i=0;i<n;i++)
        {
            cin>>str[i];
        }
        RadixSort(str, n);
        for(int i=0;i<n;i++)
        {
            cout<<str[i]<<endl;
        }
    }
}