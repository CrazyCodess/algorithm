/**
* @Date 2019/1/21 9:32
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)return NULL;
        ListNode* p = head;
        ListNode* pre=head;
        ListNode* r = new ListNode(0);
        r->next = head;
        for(int i=0;i<n;i++){
            p=p->next;
        }
        while(p!=NULL){
            p=p->next;
            r=pre;
            pre=pre->next;
        }
        if(pre==head)return pre->next;
        r->next=pre->next;
        delete pre;
        return head;
    }
};


