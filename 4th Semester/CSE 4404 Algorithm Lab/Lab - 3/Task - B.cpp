#define lld long long int

int coins [] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
lld dp [6001];

void counter()
{
    memset (dp, 0, sizeof (dp));
    dp [0] = 1;
    for (int coin : coins)
    {
        for ( int j = 1; j <= 6000; j++ )
        {
            if ( j - coin >= 0 )
                dp [j] += dp [j - coin];
        }
    }
}

int main ()
{
    counter();
    for(;;)
    {
        double c;
        cin>>c;
        if (c == 0) break;
        int index = static_cast<int>(c*20.0);
        printf("%6.2lf", c);
        cout.width(17);
        cout << dp[index] << endl;
    }
}