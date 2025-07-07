class Solution {
public:
  bool co(string &s)
  {
           for(int i=0;i<s.length();i++)
           {
                 if(isdigit(s[i])||isalpha(s[i])||s[i]=='_')continue;
                 else
                 return false;
           }
           return true;
  }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>ans;
        for(int i=0;i<code.size();i++)
        {
               if(code[i].size()==0||!co(code[i]))
               continue;
               if(businessLine[i]=="invalid")
               continue;
               if(!isActive[i])
               continue;
               ans.push_back({businessLine[i],code[i]});
        }
        sort(ans.begin(),ans.end());
        vector<string>v;
        for(int i=0;i<ans.size();i++)
        {
               v.push_back(ans[i].second);
        }
        return v;
    }
};