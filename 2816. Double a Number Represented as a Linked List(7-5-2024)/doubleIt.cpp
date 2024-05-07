 struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<int>v;
         vector<int>v1;
        struct ListNode* tem=head;
        while(tem!=NULL)
        {
            v.push_back(tem->val);
            tem=tem->next;
        }
        reverse(v.begin(),v.end());
        struct ListNode* tem1=head;
        int i=0;
        while(tem1!=NULL)
        {
            tem1->val=v[i];
            tem1=tem1->next;
            i++;
        }
        int sum=0,cary=0;
        struct ListNode* tem2=head;
        struct ListNode* pre=head;

        while(tem2!=NULL)
        {
            int x=tem2->val;
            x=x*2+cary;
            tem2->val=x%10;
            cary=x/10;
            pre=tem2;
           tem2= tem2->next;
        }
        if(cary)
        {  
            ListNode* last= new ListNode(cary);
            pre->next=last; 

        }
         struct ListNode* tem3=head;
        while(tem3!=NULL)
        {
            v1.push_back(tem3->val);
            tem3=tem3->next;
        }
        reverse(v1.begin(),v1.end());
        struct ListNode* tem4=head;
         i=0;
        while(tem4!=NULL)
        {
            tem4->val=v1[i];
            tem4=tem4->next;
            i++;
        }

        return head;


    }
};