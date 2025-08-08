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
 ListNode* root=nullptr;

   ListNode*  re(ListNode* head)
   {

               if(!head)
           return nullptr;

           if(!head->next){
            if(!root)
            root=head;
           return head;
           }
           ListNode* next=re(head->next);
           next->next=head;
           head->next=nullptr;
           return head;



              
   }
    ListNode* reverseList(ListNode* head) {
         
        //    if(!head)
        //    return nullptr;

        //    if(!head->next)
        //    return head;
        //    reverseList
        re(head);
        return root;
    }
};