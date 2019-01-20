/**
* @Date 2019/1/20 19:58
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        long max = (long)pow(2,31)-1;
        long min = (long)pow(-2,31);
        bool isNeg = false;
        bool isFirst = true;
        bool isNum = false;
        for(int i=0;i<str.length();i++){

            if((str[i]=='+'||str[i] =='-')&&isFirst&&!isNum){
                isFirst = false;
                if(str[i] =='-')
                    isNeg = true;
            }else if(str[i]>='0'&&str[i]<='9'){
                isNum = true;
                ans = ans*10 + (int)(str[i] - '0');
                if(ans>max || ans <min) break;
            }else if(ans !=0 || ans>max || ans <min||isNum||!isFirst) break;
            else if(str[i] != ' ')break;
        }
        if (isNeg) ans = -ans;
        if(ans>max)return (int)max;
        if (ans < min)return (int)min;

        return (int)ans;
    }
};


