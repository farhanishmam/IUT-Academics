#include <stdio.h>

void print_poly(int i, int n)
{
    if(i<n)
    {
        if(i==0) printf("1");
        else
        {
            printf(" + x");
            if(i>1) printf("^%d", i);
        }
        print_poly(i+1, n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    print_poly(0, n);
    printf("\n");
    return 0;
}
