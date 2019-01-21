/**
* @Date 2019/1/21 10:48
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return head;
        ListNode* p = head->next;
        ListNode* pre = head;
        ListNode* tmp ;
        while(p){
            tmp = p;
            p = p->next;
            pre->next = p;
            tmp ->next = NULL;
            ListNode* h = new ListNode(0);
            h->next = head;
            while(h->next&&h->next->val<tmp->val) {
                h = h->next;
            }
            if(h->next==NULL){
                h->next = tmp;
                tmp->next = NULL;
            }else{
                if(h->next == head)head = tmp;
                if(h == pre)pre = tmp;
                tmp->next = h->next;
                h->next = tmp;
            }
        }
        return head;
    }
};


