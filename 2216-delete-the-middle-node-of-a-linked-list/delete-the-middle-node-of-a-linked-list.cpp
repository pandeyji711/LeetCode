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
    ListNode* deleteMiddle(ListNode* head) {
          ListNode* pre=nullptr;
          ListNode* curr=head;
          ListNode* fast=head;
            while(fast!=nullptr&&fast->next!=nullptr)
            {
                   fast=fast->next->next;
                   pre=curr;
                   curr=curr->next;
            }
            if(pre!=nullptr)
            pre->next=curr->next;
            else
            return nullptr;
            
            return head;
    }
};