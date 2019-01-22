/**
* @Date 2019/1/22 10:24
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> freqs;
        ans.clear();
        freqs.clear();
        map<int, int> m;
        m.clear();
        for(int i =0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end())m[nums[i]] = 1;
            else m[nums[i]] ++;
        }
        map<int,int>:: iterator it;
        for(it=m.begin();it!=m.end();it++){
            //cout<<it->second<<" ";
            freqs.push_back(it->second);
        }
        priority_queue<int , vector<int>, greater<int>> pq(freqs.begin(), freqs.begin()+k);
        for(int i=k;i<freqs.size();i++){
            if(freqs[i]>pq.top()){
                pq.pop();
                pq.push(freqs[i]);
            }
        }
        int cnt = pq.top();
        //cout<<cnt;
        for(it=m.begin();it!=m.end();it++){
            if(it->second>=cnt)ans.push_back(it->first);
        }
        return ans;
    }
};


