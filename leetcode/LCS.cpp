int ansvalue = 0, r, l;
    for(int i=1;i<=lena;i++)
        for(int j=1;j<=lenb;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j])dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
            ansvalue = max(ansvalue, dp[i][j]);
        }
    for(int i=1;i<=lena;i++)
        if(dp[i][lenb] == ansvalue) { r=i; break; }
    cleardp();//clear dp array with 0
    for(int i=lena;i>=1;i--)
    {
        for(int j=lenb;j>=1;j--)
        {
            dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            if(a[i]==b[j])dp[i][j]=max(dp[i][j], dp[i+1][j+1]+1);
        }
        if(dp[i][1]==ansvalue) { l=i; break; }
    }
    //l,r is the answer