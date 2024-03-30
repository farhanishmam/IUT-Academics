int fib(int n)
{
    if(n<3) return 1;
    return fib(n-2) + fib(n-1);
}

int main()
{
    int n, v;
    scanf("%d", &n);
    v = fib(n);
    printf("%d\n", v);
    return 0;
}
