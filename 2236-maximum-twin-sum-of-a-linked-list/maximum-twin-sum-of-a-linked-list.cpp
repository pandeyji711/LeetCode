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
 ListNode* newhead=nullptr;
  ListNode* rev(ListNode* head)
  {
              if(head->next==nullptr)
              {
                 if(newhead==nullptr)
                 newhead=head;
              return head;

              }
           ListNode* x= rev(head->next);
              x->next=head;
              head->next=nullptr;
               return head;
  }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode *fast=head;
    
        while(fast)
        {
               slow=slow->next;
               fast=fast->next->next;
               

        } 
     ListNode* curr=slow;
       ListNode* next=nullptr;
         ListNode* pre=nullptr;
         while(curr)
         {
               next=curr->next;
               curr->next=pre;
               pre=curr;
               curr=next;
                            
         }
        
    //   rev(slow);
      int ans=0;
        // n--;
      
        while(pre)
        {
             int sum=head->val+pre->val;
             if(sum>ans)
             {
                 ans=sum;
             }
             head=head->next;
            pre=pre->next;

        }

        return ans;

    }
};