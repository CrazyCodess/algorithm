/**
* @Date 2019/2/20 10:43
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
/**
 * 中序遍历二叉树非递归版本
 * 这是递归版本
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *   class Solution {
 *   public:
 *       void traversal(TreeNode* node, vector<int>& res){
 *           if(node == NULL)return;
 *           traversal(node->left, res);
 *           res.push_back(node->val);
 *           traversal(node->right, res);
 *       }
 *       vector<int> inorderTraversal(TreeNode* root) {
 *           vector<int> res;
 *           traversal(root, res);
 *           return res;
 *       }
 *   };
 *
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)return res;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode* node;
        while(!nodeStack.empty()){
            node = nodeStack.top();
            if(node->left == NULL){
                res.push_back(node->val);
                cout<<node->val<<"\n";
                nodeStack.pop();
                if(node->right!=NULL)nodeStack.push(node->right);
            }else {
                nodeStack.push(node->left);
                node->left = NULL;
            }
        }
        return res;
    }
};


