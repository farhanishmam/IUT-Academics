#include<stdio.h>

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int min(int a, int b)
{
    if(a>b) return b;
    return a;
}

int max(int a, int b)
{
    if(a<b) return b;
    return a;
}

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    int c,d;
    c = min(a,b);
    d = max(a,b);
	printf("GCD is %d\n",gcd(c, d));
	printf("LCM is %d", c*d/(gcd(c,d)));
}
