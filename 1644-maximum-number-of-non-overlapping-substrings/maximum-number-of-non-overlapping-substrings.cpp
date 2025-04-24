class Solution {
public:
  int  ch( string &str,int ind,unordered_map<char,pair<int,int>>&m)
  {
      int end=m[str[ind]].second;
         for(int i=ind;i<=end;i++)
         {
                if(m[str[i]].first<ind)return -1;
                end=max(end,m[str[i]].second);
         }
         return end;
  }
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char,pair<int,int>>m;
        for(int i=0;i<s.length();i++)
        {
                if(m.find(s[i])==m.end())
                {
                       m[s[i]]={i,i};
                }else
                {
                     m[s[i]].second=i;
                }
        }
        int right=-1;
        vector<string>ans;
       for(int i=0;i<s.length();i++)
       {
                 if(m[s[i]].first==i)
                 {
                      int ed=ch(s,i,m);
                    //   cout<<i<<" "<<ed<<endl;
                         if(ed!=-1)
                         {
                                   if(i>right)
                                   ans.push_back("");
                                   right=ed;
                                   ans.back()=s.substr(i,ed-i+1);

                         }
                 }
       }
        return ans;
    }
};