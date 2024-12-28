class Solution {
public:
   
   int solve(string &word1, string &word2, int ind1,int ind2,vector<vector<int>>&dp)
   {
                  if (ind1 >= word1.length())
                   return word2.length() - ind2; 
                  if (ind2 >= word2.length()) 
                  return word1.length() - ind1;
                 int res=INT_MAX;
                 if(dp[ind1][ind2]!=-1)
                 return dp[ind1][ind2];
                   if(word1[ind1]==word2[ind2])
                   {
                       return dp[ind1][ind2]=solve(word1,word2,ind1+1,ind2+1,dp);
                   }else{

                         int  x=1+solve(word1,word2,ind1,ind2+1,dp);
                            int y=1+solve(word1,word2,ind1+1,ind2,dp);
                             int z=1+solve(word1,word2,ind1+1,ind2+1,dp);
                    res=min({res,x,y,z});
                        
                   }
                   return dp[ind1][ind2]=res;
   }
    int minDistance(string word1, string word2) {
       int n=word1.length();
       int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        return solve(word1,word2,0,0,dp);
    }
};