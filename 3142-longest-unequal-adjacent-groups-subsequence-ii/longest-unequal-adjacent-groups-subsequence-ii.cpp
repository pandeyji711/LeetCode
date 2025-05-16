class Solution {
public:
   bool diff(string str1,string str2)
   {
        if(str1.length()!=str2.length())return false;
     int cnt=0;

            for(int i=0;i<str1.length();i++)
            {
                    if(str1[i]!=str2[i])
                    cnt++;
                    if(cnt>1)return false;
            }
            return cnt==1;
   }

     
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
     
      vector<int>dp1(words.size()+1,1);
      vector<int>ind(words.size()+1,-1);
      int ans=1;
      int stind=0;
        for(int i=1;i<words.size();i++)
        {
              for(int j=0;j<i;j++)
              {
                      if(groups[i]!=groups[j]&&diff(words[i],words[j]))
                      {
                           if(dp1[i]<dp1[j]+1)
                           {
                               ind[i]=j;
                           }
                           dp1[i]=max(dp1[j]+1,dp1[i]);
                           
                        //    cout<<i<<" "<<dp1[i]<<endl;
                           if(ans<dp1[i])
                           {
                                stind=i;
                           }
                           ans=max(ans,dp1[i]);
                      }
              }
        }
          vector<string>res;
          res.push_back(words[stind]);
          int next=ind[stind];
          while(next!=-1)
          {
                  res.push_back(words[next]);
                  next=ind[next];


          }
        //   for(int i=stind;i>=)
    //   int x=solve(words,groups,0,-1,dp);
        reverse(res.begin(),res.end());
// cout<<ans;
//   int l=0;
//   int r=0;
//   int n=words.size();
//   vector<string>ans;

      return res;
    }
};