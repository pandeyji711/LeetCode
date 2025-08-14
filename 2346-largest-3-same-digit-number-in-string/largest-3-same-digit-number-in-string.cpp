class Solution {
public:
 bool same(string &s)
 {
        if(s[0]==s[1]&&s[1]==s[2])return 1;
        else{
            return 0;
        }
 }
    string largestGoodInteger(string num) {
        int l=0;
        int r=0;
        vector<string>ans;
        for(int i=0;i<num.length()-2;i++)
        {
             string str=num.substr(i,3);
               if(same(str))
               {
                      ans.push_back(str);
               }
        }
        if(ans.size()==0)return "";
        sort(ans.rbegin(),ans.rend());
        return ans[0];
    }
};