/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        vector<int> nums;
        queue<TreeNode*> treeQue;
        stack<TreeNode*> tmp;
        bool f = false;
        treeQue.push(root);
        TreeNode *p;
        while(!treeQue.empty()){
            while(!treeQue.empty()){
                p = treeQue.front();
                nums.push_back(p->val);
                treeQue.pop();
                if(f){
                    if(p->right)tmp.push(p->right);
                    if(p->left)tmp.push(p->left);
                }else{
                    if(p->left)tmp.push(p->left);
                    if(p->right)tmp.push(p->right);
                }
            }
            ans.push_back(nums);
            nums.clear();
            while(!tmp.empty()){
                treeQue.push(tmp.top());
                tmp.pop();
            }
            f = !f;
        }
        return ans;
    }
};