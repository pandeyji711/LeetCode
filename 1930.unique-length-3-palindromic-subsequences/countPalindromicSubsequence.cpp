class Solution {
public:
unordered_map<string ,int>m;
    int solve(string s,int ind, string str)
    {
              if(str.length()==3&&m.find(str)==m.end()){
               m[str]++; 
              return 1;
              } 
              if(ind>=s.length())
              return 0;
            
              int x=0;
              int y=0;
              //pic
              int num=s[ind]-'a';
              if(str.length()==0)
              x=x+solve(s,ind+1,str+s[ind]);
              else if(str.length()==1)
              x=x+solve(s,ind+1,str+s[ind]);
              else if(str.length()==2&&str[0]==s[ind])
              x=x+solve(s,ind+1,str+s[ind]);
             // not pick
              y=solve(s,ind+1,str);
              return x+y;
              
    }
    int countPalindromicSubsequence(string s) {
        string str;
        int n=s.length();
        unordered_map<char,pair<int,int>>m;
        for(int i=0;i<s.length();i++)
        {
                if(m.find(s[i])==m.end())
                {
                    m[s[i]]={i,-1};
                }else
                {
                       m[s[i]].second=i;
                }
               
                // cout<<sum[i+1]<<" ";
        }
         int ans=0;
       for( auto a1:m)
       {
             if(a1.second.second!=-1)
             {
             unordered_map<char,int>m;
             for(int i=a1.second.first+1;i<a1.second.second;i++)
             {
                    m[s[i]]++;
             }
             ans+=m.size();
             }
                   

       }
       return ans;
        
          


    }
};