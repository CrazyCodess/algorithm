/**
* @Date 2019/03/15 11:48
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int  maxReplacement(string s, int k){
        int l=0, r=1, count = 0, res=0;
        char cw = s[l];
        while(l<s.size()){
            if(r>=s.size()){
                if(r-l>res)res = r-l;
                //cout<<res<<cw<<endl;
                break;
            }
            if(s[r] == cw){
                r++;
            }else if(count<k){
                count++;
                r++;
            }else{
                if(r-l>res)res = r-l;
                //cout<<res<<cw<<endl;
                l++;
                cw = s[l];
                r = l+1;
                count=0;
            }

        }
        return res;
    }
    int characterReplacement(string s, int k) {
        string s1;
        for(int i=s.size()-1;i>=0;i--)s1.push_back(s[i]);
        int res = 0;
        if(s.size()>1&&k>0){
            string s2 = s;
            s2[0] = s2[1];
            res = maxReplacement(s2, k-1);
        }
        return max(max(maxReplacement(s, k), maxReplacement(s1, k)), res);
    }
};

int main(){
    Solution solu;
    cout<<solu.characterReplacement("AAAB", 0)<<"...."<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}