class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>ans(s.length()+1);
        vector<int>v;
        for(int i=0;i<=s.length();i++)
        {
               v.push_back(i);
        }
        // int num=0;
        int l=0;
        int r=s.length();

        // ans[0]=0;
        for(int i=0;i<s.length();i++)
        {
              if(s[i]=='I')
              {
                   ans[i]=v[l];
                   l++;
              }else
              {
                     ans[i]=v[r];
                     r--;
              }
        }
        ans[s.length()]=v[r];
        return ans;
    }
};