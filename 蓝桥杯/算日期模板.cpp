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
    int main()   
    {  
        int mou[20] = {0,31,28,31,30,31,30,31,31,30,31,30,31};  
        int t = 0;  
        int year = 2014,m = 11,day = 9;  
        while(t<=1000)  
        {  
            int ps = 0;  
            if(m == 2 && year%4==0 && year % 400!=0)  
            {  
                ps = 1;  
            }  
            while(day<=(mou[m]+ps))  
            {  
                day++;  
                t++;  
                if(t>=1000)  
                    break;  
            }  
            if(t>=1000)  
                break;  
            day = 1;  
            m++;  
            if(m==13)  
            {  
                year++;  
                m = 1;  
            }  
            printf("%d %d %d %d\n",year,m,day,t);  
        }  
        printf("%d %d %d\n",year,m,day);  
        return 0;  
    }  
