    #include <iostream>  
    #include <cstdio>  
    #include <cstring>  
    #include <string>  
    #include <cmath>  
    #include <vector>  
    #include <algorithm>  
    #include <map>  
    const int N = 1001;  
    using namespace std;  
    typedef __int64 LL;  
    map<LL,int> m;  
    int cnt[20] = {1,1,1,2,2,2,2,3,3,3,3,3};  
      
    bool solve(int a[])  
    {  
        for(int i=0;i<12;i++)  
        {  
            LL tmp = 0;  
            for(int j = i;j<12;j++)  
            {  
                tmp = tmp *10 + a[j];  
            }  
            for(int j = 0;j<i;j++)  
                tmp = tmp *10 + a[j];  
            //printf("%I64d\n",tmp);  
            if(m[tmp]){}  
            else  
            
            {  
                m[tmp] = 1;  
                return true;  
            }  
        }  
        LL tmp = 0;  
        for(int i=11;i>=0;i--)  
            tmp = tmp *10 + a[i];  
        if(m[tmp]){}  
        else  
        {         
            m[tmp] = 1;  
            return true;          
        }  
        return false;  
    }  
      
    int main()  
    {  
        int ans = 0;  
        //solve(cnt);  
          
        while(next_permutation(cnt,cnt+12))  
        {  
            LL tmp = 0;  
            for(int i=0;i<12;i++)  
            {  
                tmp = tmp * 10 + cnt[i];  
            }  
            
            //printf("%I64d\n",tmp);  
            if(solve(cnt))  
            {  
                ans++;  
            }  
        }  
        printf("%d\n",ans);  
        return 0;  
    }  
