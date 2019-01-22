/**
* @Date 2019/1/22 20:40
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        ans.clear();
        if(root == NULL)return ans;
        vector<int> tmp;
        tmp.clear();
        Node* tmpNode;
        queue<Node*> que;
        tmp.push_back(root->val);
        ans.push_back(tmp);
        que.push(root);
        int cnt=1,childCnt=0;
        while(!que.empty()){
            tmp.clear();
            while(cnt--){
                tmpNode = que.front();
                if(tmpNode->children.size()){
                    for(int i=0;i<tmpNode->children.size();i++){
                        tmp.push_back(tmpNode->children[i]->val);
                        que.push(tmpNode->children[i]);
                        childCnt++;

                    }
                }
                que.pop();
            }
            if(!tmp.empty())ans.push_back(tmp);
            cnt = childCnt;
            childCnt = 0;
        }
        return ans;
    }
};

