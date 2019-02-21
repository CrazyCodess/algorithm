/**
* @Date 2019/2/20 11:23
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)return res;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode* node;
        while(!nodeStack.empty()){
            node = nodeStack.top();
            res.push_back(node->val);
            nodeStack.pop();
            if(node->right != NULL)nodeStack.push(node->right);
            if(node->left != NULL)nodeStack.push(node->left);
        }
        return res;
    }
};


