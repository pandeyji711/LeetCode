class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>ans(s.length()+1);
      
        // int num=0;
        int l=0;
        int r=s.length();

        // ans[0]=0;
        for(int i=0;i<s.length();i++)
        {
              if(s[i]=='I')
              {
                   ans[i]=l;
                   l++;
              }else
              {
                     ans[i]=r;
                     r--;
              }
        }
        ans[s.length()]=r;
        return ans;
    }
};