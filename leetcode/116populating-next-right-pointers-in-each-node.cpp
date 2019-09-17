#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    void conn(Node* root){
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL)return;
        Node *lp = root->left;
        Node *rp = root->right;
        while(lp->right != NULL && rp->left != NULL){
            lp->right->next = rp->left;
            lp = lp->right;
            rp = rp->left;
        }
    }
    Node* connect(Node* root) {
        if(root == NULL)return root;
        if(root->left == NULL && root->right == NULL)return root;
        conn(root);
        Node* lp = connect(root->left);
        Node* rp = connect(root->right);
        lp->next = rp;
        return root;
    }
};