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
    ListNode* partition(ListNode* head, int x) {
        // vector<pair<int,int>>vp;
        ListNode* tem=head;
        int ind=0;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>lpq;
           priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mpq;
        while(tem!=nullptr)
        {
              if(tem->val<x)
                lpq.push({ind,tem->val});
                else
                mpq.push({ind,tem->val});
                ind++;
              
                tem=tem->next;
        }
         ListNode* tem2=head;
        while(!lpq.empty())
        {
                        tem2->val=lpq.top().second;
                        tem2=tem2->next;
                        lpq.pop();
        }
         while(!mpq.empty())
        {
                        tem2->val=mpq.top().second;
                        tem2=tem2->next;
                        mpq.pop();
        }
        return head;
       

    }
};