#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1)return n;
        if(n == 2)return 2 + int(ratings[0] != ratings[1]);
        vector<vector<int>> edges(n, vector<int>());
        vector<int> in(n, 0);
        vector<int> prize(n, 0);
        int res = 0;
        for(int i = 0;i < n;i++){
            if(i > 0 && ratings[i] < ratings[i-1]){
                in[i]++;
                edges[i].push_back(i - 1);
            }
            if(i < n-1 && ratings[i] < ratings[i+1]){
                in[i]++;
                edges[i].push_back(i + 1);
            }
        }
        queue<int> que;
        for(int i = 0;i < n;i++)if(in[i] == 0){
            que.push(i);
            prize[i] = 1;
        }
        int node,y;
        while(!que.empty()){
            node = que.front();
            que.pop();
            res += prize[node];
            for(int i = 0;i<edges[node].size();i++){
                y = edges[node][i];
                in[y] -- ;
                if(in[y] == 0){
                    que.push(y);
                    prize[y] = prize[node] + 1;
                }
            }
        }
        return res;

    }
};