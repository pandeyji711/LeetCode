/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        if(head==nullptr)
        return head;
        // if()
        ListNode* last=head;
        while(last->next)
        {
             last=last->next;
             n++;
        }
        // cout<<n;
        if(k%(n+1)==0)return head;
        int s=n-(k%(n+1));
       
        ListNode* mid=head;
        while(s--)
        {
              mid=mid->next;
        }
        ListNode* start=mid->next;
        // cout<<mid->val;
        mid->next=nullptr;
        last->next=head;
        return start;
    }
};