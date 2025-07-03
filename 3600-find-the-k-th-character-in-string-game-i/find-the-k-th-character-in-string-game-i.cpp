class Solution {
public:
  string solve(string str)
  {

    string ans;
    for(int i=0;i<str.length();i++)
    {
             if(str[i]=='z')
             ans.push_back('a');
             else{
                   char c=str[i];
                   c++;
                   ans.push_back(c);
             }
    }
    return ans;
  }
    char kthCharacter(int k) {
        string ans="a";
        while(ans.size()<k)
        {
              ans+=solve(ans);
        }
      return   ans[k-1];
    }
};