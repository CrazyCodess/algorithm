/**
* @Date 2019/03/14 15:33
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        string res="";
        int n = s.size();
        int m = t.size();
        if(n==0||m==0||n<m)return res;
        unordered_map<char, int> wm;
        for(int i =0;i<t.size();i++){
            if(wm.find(t[i])!=wm.end())wm[t[i]]++;
            else wm[t[i]] = 1;
        }
        int l = -1, len = 0, id1=0, id2= -1, count = 0;
        while(id1 < n){
            if(count<m){
                if(id2 == n-1)break;
                id2++;
                if(wm.find(s[id2])!=wm.end()){
                    if(wm[s[id2]]>0)
                    count++;
                    wm[s[id2]]--;
                }
            }
            if(count == m){
                if(len == 0||len>id2-id1+1){
                    len = id2-id1+1;
                    l = id1;
                }
                if(wm.find(s[id1])!=wm.end()){
                    wm[s[id1]]++;
                    if(wm[s[id1]]>0)
                    count--;
                }
                id1++;
            }
        }
        if(l != -1)res = s.substr(l, len);
        return res;
    }
};
int main(){
     Solution solu;
     string s = "ADOBECODEBANC";
     string t = "ABC";
     cout<<solu.minWindow(s, t)<<"&&&";
    //cout<<(char)toupper('_');
    return 0;
}