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
    int ans = 0;
    int max_path(TreeNode *root){
        if(root == NULL)return 0;
        int left = max_path(root->left);
        int right = max_path(root->right);
        int l = 0, r = 0;
        if(root->left!=NULL && root->left->val == root->val)l += left+1;
        if(root->right != NULL && root->right->val == root->val)r += right+1;
        //cout<<l<<" "<<r<<endl;
        ans = max(ans, l+r);
        return max(l, r);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)return 0;
        max_path(root);
        return ans;
    }
};