#include<stdio.h>

int main()
{
    char a[100];
    int d;
    scanf("%d ",&d);
    for(int i=0;i<d;i++)
    {
        scanf("%c",&a[i]);
    }
    for(int i=0;i<d;i++)
    {
        printf("%c",a[i]);
    }

}
