/**
* @Date 2019/1/23 10:35
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<=0||n<=0)return 0;
        vector<vector<int>> ans;
        ans.clear();
        for(int i=0;i<m;i++){
            vector<int> tmp(n,0);
            ans.push_back(tmp);
        }

        for(int i=0;i<n;i++)
            ans[0][i] = 1;
        for(int i=0;i<m;i++)
            ans[i][0] = 1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){

                ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
        return ans[m-1][n-1];
    }
};


