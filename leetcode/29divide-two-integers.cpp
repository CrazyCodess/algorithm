/**
* @Date 2019/02/26 16:42
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN&&divisor == -1)return INT_MAX;
        bool sign = (dividend<0)^(divisor<0);
        long long rem = abs((long long)dividend), res = 0, divi, cnt = 1, base = abs((long long)divisor);
        if(base > rem)return 0;
        while(rem>= base){
            divi = base;
            cnt = 1;
            while(divi <= rem){
                divi <<= 1;
                if(divi<rem) cnt <<= 1;
                else{
                    rem -= divi>>1;
                }
            }
            res += cnt;
        }
        return sign?-res:res;
    }
};
int main(){
    Solution solu;
    int num, num1;
    while(cin>>num>>num1)
    cout<<solu.divide(num,num1)<<endl;
    return 0;
}