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
    int ans = INT_MIN;
    int maxGain(TreeNode* root){
        if(root == NULL) return 0;
        int left = max(maxGain(root->left), 0);
        int right = max(maxGain(root->right), 0);
        ans = max(ans, left + right + root->val);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return ans;
    }
};