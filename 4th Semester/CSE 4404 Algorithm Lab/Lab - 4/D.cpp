#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    //Defining sizes for temporary arrays and creating left and right temporary arrays
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    // Copying data from main array to left and right temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0; //Index of left temp array
    int j = 0; //Index of right temp array
    int k = l; //Index of main array

    //Comparing left and right temp arrays and inserting in main array using 2 fingers rule
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //Only one of the lower two loops will run
    // Copying the remaining elements of left array in main array
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Or, copying the remaining elements of right array in main array
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r)
{
    if(l >= r) //boundary limits
    {
        return;
    }
    int m = (l+r-1)/2; //finding the mid
    mergeSort(arr,l,m); //divide for left sub-array
    mergeSort(arr,m+1,r); //divide for right sub-array
    merge(arr,l,m,r); //merge the two sub-arrays in sorted order
}

int main(void)
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0) break;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        mergeSort(arr,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<arr[i];
            if(i!=n-1) cout<<" ";
        }
        cout<<endl;
    }
}