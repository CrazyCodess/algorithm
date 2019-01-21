/**
* @Date 2019/1/21 10:27
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
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        while(list1&&list2){
            if(list1->val < list2->val){
                p->next = list1;
                list1 = list1->next;
                p = p->next;
            }else{
                p->next = list2;
                list2 = list2->next;
                p = p->next;
            }
        }
        if(list1) p->next = list1;
         if(list2) p->next = list2;
         return head->next;
     }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* p = head->next;
        ListNode* pre = head;
        while (p->next){
            pre = pre->next;
            p = p->next;
        }
        pre->next = NULL;
        return mergeTwoLists(sortList(head), sortList(p));
    }
};


