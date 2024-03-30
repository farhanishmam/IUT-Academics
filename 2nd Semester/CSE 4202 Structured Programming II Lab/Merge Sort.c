#include <stdio.h>

int arr[10] = {13,4,12,2,1,3,4,1,2,19};

void merge(int st, int ed);

int merge_s (int st, int ed)
{
    if (st == ed) return 1;
    merge_s(st,(st+ed)/2);
    merge_s((st+ed)/2 + 1,ed);
    merge(st,ed);
}

void merge(int st, int ed)
{
    int temp[100] = {};
    int k=0;
    int i =st;
    int j=(st+ed)/2 + 1;
    for(;;)
    {
        if(arr[i]<arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;

        }
        else if(arr[i]>=arr[j])
        {
            temp[k] = arr[j];
            k++;
            j++;
        }

        if(i>(st+ed)/2)
        {
            for(;j<=ed;j++)
            {
                temp[k] = arr[j];
                k++;
            }
            break;

        }
        else if(j>ed)
        {
            for(;i<=(st+ed)/2;i++)
            {
                temp[k] = arr[i];
                k++;
            }
            break;
        }
    }
    k = 0;
    for(int x=st; x<=ed;x++)
    {
        arr[x] = temp[k];
        k++;
    }
}



int main(void)
{
    merge_s(0,9);
    for(int i=0; i<10;i++)
    {
       printf("%d ",arr[i]);
    }
}
