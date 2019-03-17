/**
* @Date 2019/03/14 11:40
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.size()==0||words.size()==0)return res;
        map<string, int> wm;
        int m = words.size();
        int cnt = words[0].size();
        if(s.size() < m*cnt)return res;
        int id1=0, id2=0,count;
        wm.clear();
        for(int i=0;i<m;i++){
            if(wm.find(words[i]) != wm.end()){
                wm[words[i]] ++;
            }else wm[words[i]] = 1;
        }
        string tmp;
        while(id1 <= s.size()-m*cnt){
            id2 = id1;
            count = 0;
            while(true){
                tmp = s.substr(id2, cnt);   
                if(wm.find(tmp)!=wm.end()&&wm[tmp] >0 ){
                    wm[tmp] --;
                    id2 += cnt;
                    count ++;
                }else break;
            }
            wm.clear();
            for(int i=0;i<m;i++){
                if(wm.find(words[i]) != wm.end()){
                    wm[words[i]] ++;
                }else wm[words[i]] = 1;
            }
            if(count == m)res.push_back(id1);
            id1++;
        }
        return res;
    }
};
int main(){
    string s= "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    Solution solu;
    vector<int> vec;
    vec = solu.findSubstring(s, words);
    for(int i=0;i<vec.size();i++)cout<<vec[i]<<endl;
    return 0;
}