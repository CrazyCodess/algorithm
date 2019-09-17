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
    Node* connect(Node* root) {
        if(root == NULL)return NULL;
        if(root->left != NULL && root->right != NULL)root->left->next = root->right;
        Node *p = NULL, *q = root->next;
        if(root->right != NULL)p = root->right;
        else if(root->left != NULL)p = root->left;
        while(p != NULL && q != NULL){
            if(q->left != NULL) {
                p->next = q->left;
                break;
            }
            else if(q->right != NULL){
                p->next = q->right;
                break;
            }
            else q = q->next;
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};