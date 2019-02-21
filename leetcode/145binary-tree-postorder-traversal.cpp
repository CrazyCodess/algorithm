/**
* @Date 2019/2/20 11:27
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)return res;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode* node;
        while(!nodeStack.empty()){
            node = nodeStack.top();
            if(node->right != NULL)nodeStack.push(node->right);
            if(node->left != NULL)nodeStack.push(node->left);
            if(node->left == NULL&&node->right == NULL){
                res.push_back(node->val);
                nodeStack.pop();
            }
            node->left = NULL;
            node->right = NULL;
        }
        return res;
    }
};


