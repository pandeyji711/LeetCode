class Solution {
public:
  bool solve(string str,unordered_map<char,int>m)
  {
                   unordered_map<char,int>m1;
                   for(int i=0;i<str.length();i++)
                   {
                          m1[str[i]]++;
                   }
                   for( auto a1:m)
                   {
                             if(m1.find(a1.first)==m1.end()||m1[a1.first]<a1.second)
                             return false;
                   }
                   return true;
  }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        // vector<
        unordered_map<char,int>m;
         for(int i=0;i<words2.size();i++)
                {
                      unordered_map<char,int>m2;
                      for(int j=0;j<words2[i].length();j++)
                      {
                             m2[words2[i][j]]++;
                             m[words2[i][j]]=max(m[words2[i][j]],m2[words2[i][j]]);
                      }      
                } 
        for(int i=0;i<words1.size();i++)
        {
                if(solve(words1[i],m))
                ans.push_back(words1[i]);
        }
        return ans;
    }
};