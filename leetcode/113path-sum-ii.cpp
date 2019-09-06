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
    void path(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int> tmp){
        if(sum <= 0)return;
        if(root->left == NULL && root->right == NULL){
            tmp.push_back(root->val);
            sum -= root->val;
            if(sum == 0)ans.push_back(tmp);
            return;
        }
        tmp.push_back(root->val);
        sum -= root->val;
        if(root->left)path(root->left, sum, ans, tmp);
        if(root->right)path(root->right, sum, ans, tmp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        vector<int> tmp;
        path(root, sum, ans, tmp);
        return ans;
    }
};