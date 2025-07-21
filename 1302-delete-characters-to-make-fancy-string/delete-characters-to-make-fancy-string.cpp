class Solution {
public:
    string makeFancyString(string s) {
        string ans;
         char ch=s[0];
         int cnt=0;
        for(int i=0;i<s.length();i++)
        {
                if(ch!=s[i])
                {
                     ch=s[i];
                     cnt=1;
                     ans.push_back(s[i]);
                }else if(cnt<2)
                {
                    cnt++;
                       ans.push_back(s[i]);
                }
        }
        return ans;
    }
};