#include<bits/stdc++.h>
#define SIZE 1001
using namespace std;

char x[SIZE], y[SIZE];
int counter[SIZE][SIZE];

int main(){
    int i, j;

    while(gets(x) && gets(y)){

        int xlen = strlen(x);
        int ylen = strlen(y);

        for(i = 1; i <= xlen; i++){
            for(j = 1; j <= ylen;j++){
                
                if(x[i-1] == y[j-1])
                    counter[i][j] = counter[i-1][j-1] + 1;
                else
                    counter[i][j] = max(counter[i-1][j], counter[i][j-1]);
            }
        }

    
        cout<<counter[xlen][ylen]<<endl;

    }
}
    