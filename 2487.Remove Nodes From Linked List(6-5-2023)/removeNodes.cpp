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
    ListNode* removeNodes(ListNode* head) {
        vector<int>v;
        struct ListNode* tem=head;
        while(tem!=NULL)
        {
            v.push_back(tem->val);
            tem=tem->next;
        }
        int r=v.size()-1;
        vector<int>ans;
        int max=v[r];
        ans.push_back(v[r]);
        for(int i=r-1;i>=0;i--)
        {
           if(max<=v[i])
           {
            max=v[i];
            ans.push_back(v[i]);
           }
        }
        int n=ans.size();
        reverse(ans.begin(),ans.end());
        int i=0;
         struct ListNode* tem1=head;
         struct ListNode* pre=head;
        while(n--)
        {
            tem1->val=ans[i];
            i++;
            pre=tem1;
            tem1=tem1->next;
        }
        
       pre->next=NULL;
       return head;

    }
};