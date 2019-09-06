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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* ans = NULL;
        int n = inorder.size();
        int m = postorder.size();
        if(n == 0||m == 0)return ans;
        vector<int> postlef;
        vector<int> postrig;
        vector<int> inlef;
        vector<int> inrig;
        ans = new TreeNode(postorder[m-1]);
        int root = postorder[m-1];
        int id = 0;
        for(;id < n;id++){
            if(inorder[id] == root)break;
            inlef.push_back(inorder[id]);
        }
        for(int i = id+1;i < n;i++)inrig.push_back(inorder[i]);
        int j = 0;
        for(; j < id;j++){
            postlef.push_back(postorder[j]);
        }
        for(;j < m-1;j++){
            postrig.push_back(postorder[j]);
        }
        ans->left = buildTree(inlef, postlef);
        ans->right = buildTree(inrig, postrig);
        return ans;
    }
};