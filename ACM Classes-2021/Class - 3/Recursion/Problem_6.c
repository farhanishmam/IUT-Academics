int fact(int n)
{
    if(n<2) return 1;
    return n * fact(n-1);
}

int main()
{
    int n, v;
    scanf("%d", &n);
    v = fact(n);
    printf("%d\n", v);
    return 0;
}