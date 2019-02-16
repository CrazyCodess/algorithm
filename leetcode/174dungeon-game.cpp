/**
* @Date 2019/1/23 15:37
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m<=0)return 0;
        int n = dungeon[0].size();
        vector<vector<int>> ans;
        ans.clear();
        for(int i=0;i<m;i++){
            vector<int> tmp(n,0);
            ans.push_back(tmp);
        }
        if(dungeon[m-1][n-1]>=0)ans[m-1][n-1] = 0;
        else ans[m-1][n-1] = -dungeon[m-1][n-1];
        for(int i = m-2;i>=0;i--){
            ans[i][n-1] = dungeon[i][n-1]>ans[i+1][n-1]?0:ans[i+1][n-1] - dungeon[i][n-1] ;
        }
        for(int i=n-2;i>=0;i--){
            ans[m-1][i] = dungeon[m-1][i]>ans[m-1][i+1]?0: ans[m-1][i+1] - dungeon[m-1][i] ;
        }
        for(int i = m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int left = dungeon[i][j]>ans[i][j+1]?0:ans[i][j+1] - dungeon[i][j] ;
                int right = dungeon[i][j]>ans[i+1][j]?0:ans[i+1][j] - dungeon[i][j] ;
                ans[i][j] = min(left,right);
            }
        }
        return ans[0][0]+1;
    }
};

