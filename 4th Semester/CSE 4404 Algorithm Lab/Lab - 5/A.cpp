#include <bits/stdc++.h>
#define LL long long int
#define modulo 1000000007
using namespace std;

int main()
{
    bool flag = true;
    int n;
    cin>>n;
    LL A[n][n],B[n][n],C[n][n];         //declaring input matrices
    LL r[n], Br[n], ABr[n], Cr[n];      //declaring temporary matrices for calculating

    //taking input
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%I64d",&A[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%I64d",&B[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%I64d",&C[i][j]);
        }
    }

    //iteratively performing the steps for k times
    //7 is my lucky number
    for(int k=0; k<7 && flag; k++)
    {
        //initializing the matrices for calculation
        for(int i=0; i<n; i++)
        {
            ABr[i] = 0;
            Br[i] = 0;
            Cr[i] = 0;
            r[i] = abs(rand()%2);     //randomly picking between 0 and 1
        }

        //performing the matrix calculations
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                Br[i]=(Br[i]+(B[i][j]*r[j]))%modulo;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                ABr[i]=(ABr[i]+(A[i][j]*Br[j]))%modulo;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                Cr[i]=(Cr[i]+(C[i][j]*r[j]))%modulo;
            }
        }
        for(int i=0; i<n; i++)
        {
            if((Cr[i]!=ABr[i]))
            {
                flag = false;       //if it gives false once, we terminate the loop and
                                    //conclude that the whole matrix multiplication is wrong since
                                    //since the algorithm doesn't give false negative
                                    //hence any given negative is true negative
                break;
            }
        }
    }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}