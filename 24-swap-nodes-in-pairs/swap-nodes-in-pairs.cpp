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
    ListNode* swapPairs(ListNode* head) {
        
           if(!head||!(head->next))
           return head;

            ListNode* tem=head;
            
            ListNode* next=head->next;
            while(tem)
            {
                   int temp=tem->val;
                   tem->val=next->val;
                    next->val=temp;
                    tem=next->next;
                    if(!tem)
                    {
                         return head;
                    }
                    if(!tem->next)
                    {
                         return head;
                    }
                    next=tem->next;

            } 
            return head;
           

    }
};