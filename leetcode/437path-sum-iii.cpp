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
    int paths(TreeNode *root, int sum){
        if(root == NULL)return 0;
        int res = 0;
        if(root->val == sum)res ++;
        res += paths(root->left, sum-root->val);
        res += paths(root->right, sum-root->val);
        return res;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)return 0;
        return paths(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};