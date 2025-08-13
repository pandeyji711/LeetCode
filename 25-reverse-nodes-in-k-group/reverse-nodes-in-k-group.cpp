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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tem1=head;
        ListNode* tem2=head;
        
        while(tem1!=nullptr)
        {
             int t=k;
             vector<int>v;
               while(tem1!=nullptr&&t>0)
               {
                   v.push_back(tem1->val);
                   tem1=tem1->next;
                   t--;
               }
               if(t>0)
               {
                   return head;
               }else{
                  reverse(v.begin(),v.end());
             int i=0;
                   while(i<v.size())
                   {
                  tem2->val=v[i];
                   tem2=tem2->next;
                   i++;
                   }
                    
               }

        }
        return head;


    }
};