class Solution {
public:
   vector<string> solve(vector<string>& words, vector<int>& groups,int ind)
   {
                          vector<string>ans;
                          int dub=groups[ind];
                          ans.push_back(words[ind]);
                          for(int i=ind+1;i<words.size();i++)
                          {
                                  if(dub!=groups[i])
                                  {
                                      ans.push_back(words[i]);
                                      dub=groups[i];
                                  }
                          }
                          return ans;
   }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<vector<string>>ans;
        for(int i=0;i<groups.size();i++ )
        {
               vector<string> tem=solve(words,groups,i);
               if(ans.empty()||tem.size()>ans[0].size())
               {
                   if(!ans.empty())
                    ans.pop_back();
                    ans.push_back(tem);
               }
        }
        return ans[0];

    }
};