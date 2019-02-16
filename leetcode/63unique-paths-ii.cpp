/**
* @Date 2019/1/23 10:32
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0)return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> ans;
        ans.clear();
        for(int i=0;i<row;i++){
            vector<int> tmp(col,0);
            ans.push_back(tmp);
        }
        if(!obstacleGrid[0][0])ans[0][0] = 1;
        for(int i=1;i<col;i++)
            if(obstacleGrid[0][i]==0)
                ans[0][i] = ans[0][i-1];
        for(int i=1;i<row;i++)
            if(obstacleGrid[i][0]==0)
                ans[i][0] = ans[i-1][0];
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(obstacleGrid[i][j]==1)ans[i][j] =0;
                else ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++)cout<<ans[i][j]<<" ";
        //     cout<<"\n";
        // }
        return ans[row-1][col-1];
    }
};


