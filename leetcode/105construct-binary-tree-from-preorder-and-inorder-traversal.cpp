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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ans = NULL;
        int n = preorder.size();
        int m = inorder.size();
        if(n == 0||m == 0)return ans;
        vector<int> prelef;
        vector<int> prerig;
        vector<int> inlef;
        vector<int> inrig;
        ans = new TreeNode(preorder[0]);
        int root = preorder[0];
        int id = 0;
        for(;id < m;id++){
            if(inorder[id] == root)break;
            inlef.push_back(inorder[id]);
        }
        for(int i = id+1;i < m;i++)inrig.push_back(inorder[i]);
        int j = 1;
        for(; j < (id+1) && j < n;j++){
            prelef.push_back(preorder[j]);
        }
        for(;j < n;j++){
            prerig.push_back(preorder[j]);
        }
        ans->left = buildTree(prelef, inlef);
        ans->right = buildTree(prerig, inrig);
        return ans;
    }
};