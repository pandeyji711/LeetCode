class Solution {
public:
int dp[21][21];
  bool solve(string s, string p,int ind1,int ind2)
  {
         if(ind1==s.length()-1&&ind2==p.length()-1)
         {
                if(p[ind2]!='.'&&p[ind2]!='*')
                {
                         if(p[ind2]!=s[ind1])
                         return dp[ind1][ind2]=0;
                         else
                         return dp[ind1][ind2]=1;
                }else
                return dp[ind1][ind2]= 1;
         }
         if(ind1>=s.length()&&ind2>=p.length())return 1;
         if(ind2>=p.length())return 0;
         bool a=false;
          if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
          }
          if(p[ind2]!='*'&&p[ind2]!='.'&&(ind1>=s.length()||s[ind1]!=p[ind2]))
          {
                  
                  if(p[ind2+1]=='*')
                  {
                    a=a|solve(s,p,ind1,ind2+2);
                  }else
                  return dp[ind1][ind2]= false;
          }
          else if(p[ind2]=='.')
          {
               if(p[ind2+1]=='*')
               {
                     for(int i=ind1;i<=s.length();i++)
                     {
                         a=a|solve(s,p,i,ind2+2);
                     }
               }else if(ind1<s.length()){
                a=a|solve(s,p,ind1+1,ind2+1);
               }else
               return dp[ind1][ind2]= 0;
               
          }
          else if(ind1<s.length()&&p[ind2]==s[ind1])
          {
                 if(p[ind2+1]=='*')
                 {
                       int i=ind1;
                       a=a|solve(s,p,i,ind2+2);
                       while(i<s.length()&&s[i]==p[ind2])
                       {
                         a=a|solve(s,p,i+1,ind2+2);
                         i++;
                       }
                 }else
                 {
                    a=a|solve(s,p,ind1+1,ind2+1);
                 }
          }
          return dp[ind1][ind2]=a;
  }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
       return solve(s,p,0,0);
    }
};