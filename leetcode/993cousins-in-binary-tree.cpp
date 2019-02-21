/**
* @Date 2019/2/17 20:55
* @Created by dmyan
*/
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
class Solution {
public:
    bool traversing(TreeNode* node, int& dleft, int& dright, int depth, int x, int y){
        if(node ==NULL)return true;
        if(node->left!=NULL&&node->right!=NULL){
            if((node->left->val == x&&node->right->val == y)||(node->left->val == y&&node->right->val == x))return false;
        }

        if(node->val == x)dleft = depth;
        if(node->val == y)dright = depth;
        if(dleft!=-1&&dright!=-2)return true;
        return traversing(node->left, dleft, dright, depth+1, x, y)&&traversing(node->right, dleft, dright, depth+1, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int depth = 0;
        int dleft = -1, dright = -2;
        if(root->val == x||root->val == y)return false;
        if(traversing(root, dleft, dright, depth, x, y)&&dleft!=-1&&dright!=-1&&dleft == dright)return true;
        return false;
    }
};

