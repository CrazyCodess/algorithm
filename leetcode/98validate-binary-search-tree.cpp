/**
* @Date 2019/2/19 17:11
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
    void validBST(TreeNode* node, TreeNode* min, TreeNode* max, bool& flag){
        if(node == NULL)return;
        if((min != NULL&&node->val <= min->val)||(max!=NULL&&node->val >= max->val)){
            flag = false;
            return;
        }
        validBST(node->left, min, node, flag);
        validBST(node->right, node, max, flag);
    }
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        validBST(root, NULL, NULL, flag);
        return flag;
    }
};


