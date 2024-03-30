//using median quick sort
#include<bits/stdc++.h>
#define SIZE 2000001
using namespace std;
int arr[SIZE];

void quicksort (int arr[],  int n)
{
    int start, end,pivot;
    if (n < 2)                      //base case
        return;
    pivot = arr[n/2];               //median is taken as pivot

    for (start = 0, end= n - 1; ; start++, end--)
    {
        while (arr[start] < pivot)          //find the larger element from start
            start++;
        while (pivot < arr[end])            //find the smaller element from end
            end--;
        if (start>= end)                    //boundaries overlap
            break;
        swap(arr[start], arr[end]);     //swap the elements
                                            //Reason: This results in arrays with elements smaller at the left
                                            //and arrays with elements larger at the right of pivot
                                            //pivot also gets swapped to the correct position when boundaries overlap
    }
    quicksort(arr, start);                          //sort all the elements smaller than pivot
    quicksort(arr + start, n - start);          //sort all the elements larger than pivot
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