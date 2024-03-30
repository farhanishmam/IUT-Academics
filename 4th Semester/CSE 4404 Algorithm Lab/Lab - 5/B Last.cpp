//using last element quick sort
#include<bits/stdc++.h>
#define SIZE 2000001
using namespace std;
int arr[SIZE];

void quicksort (int arr[],  int n)
{
    int start, end,pivot;
    if (n < 2)
        return;

    pivot = arr[n-1];

    for (start = 0, end= n - 1; ; start++, end--) {
        while (arr[start] < pivot)
            start++;
        while (pivot < arr[end])
            end--;

        if (start>= end)
            break;
        swap(arr[start], arr[end]);
    }
    quicksort(arr, start);
    quicksort(arr + start, n - start);
}

int main ()
{
    int n;
    for(;;)
    {
        cin>>n;
        if(n == 0) break;

        for(int i = 0; i < n; i++)
        {
            scanf("%d",&arr[i]);
        }
       quicksort(arr, n);
        for (int i=0; i <n ; i++)
        {
            printf("%d",arr[i]);
            if(i<n-1) cout<<" ";    //tackle presentation error
        }
        cout<<endl;
    }
    return 0;
}