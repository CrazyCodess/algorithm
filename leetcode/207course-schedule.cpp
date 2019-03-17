/**
* @Date 2019/03/16 20:20
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> edges(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        vector<int> res;
        pair<int ,int> tmp;
        for(int i=0;i<prerequisites.size();i++){
            tmp = prerequisites[i];
            edges[tmp.second].push_back(tmp.first);
            in[tmp.first]++;
        }
        for(int i=0;i<numCourses;i++){
            if(in[i] == 0)q.push(i);
        }
        int node;
        while(!q.empty()){
            node = q.front();
            q.pop();
            res.push_back(node);
            for(int i=0;i<edges[node].size();i++){
                in[edges[node][i]]--;
                if(in[edges[node][i]] == 0)q.push(edges[node][i]);
            }
        }
        return res.size() == numCourses;
    }
};