//Task 3
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int l=2*i+1;
    int r=2*i+2;


    if (l<n&&arr[l]<arr[smallest])
        smallest = l;


    if (r<n&&arr[r]<arr[smallest])
        smallest=r;


    if (smallest!=i) {
        swap(arr[i],arr[smallest]);


        heapify(arr,n,smallest);
    }
}


void build_min_heap(int arr[], int n)
{

    for (int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

}

void Heap_Min(int arr[],int n)
{
    cout<<arr[0];
}

void Heap_Extract_Min(int arr[],int n)
{
    swap(arr[0],arr [n-1]);
    n--;
    build_min_heap(arr,n);
}
void Min_Heap_Insert(int arr[],int x,int n)
{
    n=n+1;
    arr[n-1]=x;
    build_min_heap(arr,n);
}





void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = { 5,3,16,2,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    build_min_heap(arr, n);
    printArray(arr, n);
    cout<<endl;
    Heap_Min(arr,n);
    cout<<endl;
    Heap_Extract_Min(arr,n);
    Heap_Min(arr,n);
}
