#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)return head;
        ListNode* mp = new ListNode(0);
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode  *pre, *p, *tmp;
        mp = ans;
        int cnt = 1;
        while(mp != NULL && cnt < m){
            mp = mp->next;
            cnt++;
        }
        pre = mp->next;
        p = pre->next;
        while(cnt < n){
            tmp = p->next;
            p->next = pre;
            pre = p, p = tmp;
            cnt ++;
        }
        mp->next->next = p;
        mp->next = pre;
        return ans->next;
    }
};