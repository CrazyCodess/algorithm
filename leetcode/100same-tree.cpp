/**
* @Date 2019/2/19 10:47
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
    bool sameTree(TreeNode* p, TreeNode* q){
        if(p==NULL&&q==NULL)return true;
        if(p != NULL&& q != NULL){
            if(p->val != q->val)return false;
            return sameTree(p->left, q->left)&&sameTree(p->right, q->right);
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return sameTree(p, q);
    }
};


