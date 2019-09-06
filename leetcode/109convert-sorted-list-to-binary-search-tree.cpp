/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *root = NULL;
        if(head == NULL)return root;
        ListNode* p = head;
        ListNode *left, *lp;
        left = new ListNode(-1);
        lp = left;
        int n = 0;
        while(p != NULL){
            n++;
            p = p->next;
        }
        int mid = n/2;
        p = head;
        while(mid){
            lp->next = new ListNode(p->val);
            lp = lp->next;
            p = p->next;
            mid --;
        }
        root = new TreeNode(p->val);
        root->left = sortedListToBST(left->next);
        root->right = sortedListToBST(p->next);
        return root;
    }
};