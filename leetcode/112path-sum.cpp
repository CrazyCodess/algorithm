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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)return false;
        stack<TreeNode*> nodes;
        int num = root->val;
        nodes.push(root);
        TreeNode *p;
        while(!nodes.empty()){
            p = nodes.top();
            num = p->val;
            if(num == sum && p->right == NULL && p->left == NULL) return true;
            nodes.pop();
            if(p->right){
                p->right->val += num;
                nodes.push(p->right);
            }
            if(p->left){
                p->left->val += num;
                nodes.push(p->left);
            }
        }
        return false;
    }
};