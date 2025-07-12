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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
          string s;
          while(l1!=nullptr)
          {
               s+=to_string(l1->val);
               l1=l1->next;
          }
           string p;
          while(l2!=nullptr)
          {
               p+=to_string(l2->val);
               l2=l2->next;
          }
             reverse(s.begin(),s.end());
              reverse(p.begin(),p.end());
          int carry=0;
          int inds=s.length()-1;
          int indp=p.length()-1;
          vector<string>ans;
          while(inds>=0||indp>=0)
          {
                int s1=0;
                int p1=0;
                   if(inds>=0)
                   s1=s[inds]-'0';
                   if(indp>=0)
                   p1=p[indp]-'0';
                   int tem=carry+s1+p1;
                   if(tem>=10)
                   {
                     tem=tem-10;
                     carry=1;

                   }else
                   carry=0;
                //    cout<<tem<<" ";
                   ans.push_back(to_string(tem));
                   inds--;
                   indp--;


          }
          if(carry>0)
          ans.push_back(to_string(1));
       
          string fans;
          for(int i=0;i<ans.size();i++)
          {
              fans+=ans[i];
            //   cout<<ans[i]<<" ";
          }
          int inda=0;
          ListNode* head= new ListNode(fans[inda]-'0');
          inda++;
            ListNode* tem=head;
          while(inda<fans.length())
          {
                  tem->next=new  ListNode(fans[inda]-'0');
                  tem=tem->next;
                  inda++;
          }
          return head;
    }
};