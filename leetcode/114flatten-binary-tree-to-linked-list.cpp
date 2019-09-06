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
    void flatten(TreeNode* root) {
        if(root == NULL)return;
        stack<TreeNode*> trees;
        trees.push(root);
        TreeNode *p;
        TreeNode *pre = new TreeNode(-1);
        while(!trees.empty()){
            p = trees.top();
            trees.pop();
            if(p->right)trees.push(p->right);
            if(p->left)trees.push(p->left);
            pre->right = p;
            pre->left = NULL;
            pre = p;
        }
    }
};