#include<bits/stdc++.h>  
using namespace std;  
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = nums[0];
        int cnt = 1;
        int count = (int)nums.size()/2;
        for(int i=1; i<nums.size();i++){
            if(nums[i] == nums[i-1])cnt++;
            else cnt = 1;
            if(cnt > count){
                res = nums[i];
            }
        }
        return res;
    }
};
bool cmp(pair<int, int> p, pair<int, int> q){
    return p.first>q.first;
}
int main(){  
    int n,x,y,maxy = -1;
    stack<pair<int, int>> res;
    vector<pair<int, int>> xys;
    while(scanf("%d", &n)!=EOF){
        while(n--){
            scanf("%d%d", &x,&y);
            xys.push_back({x, y});
        }
        sort(xys.begin(), xys.end(), cmp);
        for(int i=0;i<xys.size();i++){
            if(maxy<= xys[i].second){
                maxy = xys[i].second;
                res.push({xys[i].first, xys[i].second});
            }
        }
        pair<int,int> tmp;
        while(!res.empty()){
            tmp = res.top();
            res.pop();
            printf("%d %d\n", tmp.first, tmp.second);
        }
    }
    cout<<min(1, 2);
    return 0;
}