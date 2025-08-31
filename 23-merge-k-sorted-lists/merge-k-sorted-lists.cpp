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
  ListNode*  solve(vector<ListNode*>& lists,int ind)
  {
         if(ind==lists.size()-1)
         return lists[ind];


          ListNode* ne=solve(lists,ind+1);
          if(ne==nullptr){
             
             if(lists[ind])
             return lists[ind];
             else
             return nullptr;
             
          }
          if(lists[ind]==nullptr)
          {
                 if(ne)
                 return ne;
                else
                 return nullptr;
          }
       
            ListNode* curr=lists[ind];
             int val1=0;
            if(curr->val<ne->val)
                 {
                      val1=curr->val;
                      curr=curr->next;
                 }else{
                     val1=ne->val;
                     ne=ne->next;
                 }
                ListNode* tem=new ListNode(val1);
                  ListNode* tem1=tem;
          while(curr&&ne)
          {
              int val=0;
                 if(curr->val<ne->val)
                 {
                       val=curr->val;
                       curr=curr->next;

                 }else{
                     val=ne->val;
                       ne=ne->next;
                 }
                 tem1->next=new ListNode(val);
                 tem1=tem1->next;
          }
          while(curr)
          {
                 tem1->next=new ListNode(curr->val);
                  tem1=tem1->next;
                  curr=curr->next;
          }
             while(ne)
          {
                 tem1->next=new ListNode(ne->val);
                   tem1=tem1->next;
                  ne=ne->next;
          }
          return tem;
  }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        vector<int>v;
        for(int i=0;i<lists.size();i++)
        {
             ListNode* tem=lists[i];
                   while(tem)
                   {
                       v.push_back(tem->val);
                       tem=tem->next;
                   }
        }
         if(v.size()==0)
             return nullptr;
        sort(v.begin(),v.end());
         ListNode* node= new  ListNode(v[0]);
          ListNode* ans=node;
        for(int i=1;i<v.size();i++)
        {
                  node->next=new  ListNode(v[i]);
                  node=node->next;
        }   
        return ans;
    }
};