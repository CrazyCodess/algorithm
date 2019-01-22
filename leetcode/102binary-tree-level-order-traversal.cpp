/**
* @Date 2019/1/22 20:14
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        ans.clear();
        if(root==NULL)return ans;
        vector<int> tmp;
        tmp.clear();
        TreeNode* tmpNode;
        queue<TreeNode*> q;
        tmp.push_back(root->val);
        ans.push_back(tmp);
        q.push(root);
        int cnt=1,sonCnt=0;
        while(!q.empty()){
            tmp.clear();
            sonCnt=0;
            while(cnt){
                tmpNode = q.front();
                if(tmpNode->left!=NULL){
                    tmp.push_back(tmpNode->left->val);
                    q.push(tmpNode->left);
                    sonCnt++;
                }
                if(tmpNode->right!=NULL){
                    tmp.push_back(tmpNode->right->val);
                    q.push(tmpNode->right);
                    sonCnt++;
                }
                q.pop();
                cnt--;
            }
            if(!tmp.empty())ans.push_back(tmp);
            cnt =sonCnt;
        }
        return ans;
    }
};


