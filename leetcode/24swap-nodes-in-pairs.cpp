/**
* @Date 2019/1/23 20:11
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode* ans = new ListNode(-1);
        ans->next = head;
        ListNode* p = ans;
        ListNode* q = head->next;
        while(p->next != NULL&&q!=NULL){

            p->next->next = q->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
            cout<<p->val;
            if(p->next==NULL)break;
            q = q->next->next->next;
        }
        return ans->next;
    }
};

