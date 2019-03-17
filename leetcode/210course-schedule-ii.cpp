/**
* @Date 2019/03/16 21:26
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> edges(numCourses, vector<int>());
        vector<int> res;
        int pre,next;
        for(int i=0;i<prerequisites.size();i++){
            pre = prerequisites[i].second;
            next = prerequisites[i].first;
            edges[pre].push_back(next);
            in[next]++;

        }
        queue<int> que;
        for(int i=0;i<numCourses;i++)if(in[i] ==0 )que.push(i);
        int node;
        while(!que.empty()){
            node = que.front();
            que.pop();
            res.push_back(node);
            for(int i=0;i<edges[node].size();i++){
                next = edges[node][i];
                in[next]--;
                if(in[next] == 0)que.push(next);
            }
        }
        if(res.size() != numCourses)res.clear();
        return res;
    }
};