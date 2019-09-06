/**
* @Date 2019/02/26 15:03
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *ans = new TreeNode(-1);
        ans->right = root;
        TreeNode *p, *pre, *np, *npre;
        stack<TreeNode*> trees;
        trees.push(ans);
        pre = NULL;
        while(!trees.empty()){
            p = trees.top();
            trees.pop();
            if(p->right){
                if(p->right->val > p->val){
                    trees.push(p->right);
                }else{
                    pre = p;
                    p = p->right;
                    break;
                }
            }
            if(p->left){
                if(p->left->val < p->val){
                    trees.push(p->left);
                }else{
                    pre = p;
                    p = p->left;
                    break;
                }
            }
        }
        int value = p->val;
        np = ans;
        while(np!=NULL){
            if()
        }


    }
};