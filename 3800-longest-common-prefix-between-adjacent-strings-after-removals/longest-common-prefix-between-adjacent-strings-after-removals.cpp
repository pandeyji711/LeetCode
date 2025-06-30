class Solution {
public:
  int prefix(string &str1,string &str2)
  {
          int ans=0;
               int l=min(str1.length(),str2.length());
               for(int i=0;i<l;i++)
               {
                    if(str1[i]!=str2[i])
                    return ans;
                    ans++;
               }
               return ans;
  }
    vector<int> longestCommonPrefix(vector<string>& words) {
        vector<int>prel(words.size()-1,0);
          vector<int>prer(words.size()-1,0);
        int maxx=0;
         for(int i=0;i<words.size()-1;i++)
         {
                   maxx=max(maxx,prefix(words[i],words[i+1]));
                   prel[i]=maxx;
         }
         maxx=0;
           for(int i=words.size()-2;i>=0;i--)
         {
                   maxx=max(maxx,prefix(words[i],words[i+1]));
                   prer[i]=maxx;
                //    cout<<i<<" "<<maxx<<endl;
         }

         vector<int>ans;
         for(int i=0;i<words.size();i++)
         {
                  //remove i
                  int preleft=i-2;
                  int left=i-1;
                  int right=i+1;
                  int maxxleft=0;
                  int maxxx=0;
                  if(preleft>=0)
                  {
                        maxxleft=prel[preleft];
                        maxxx=max(maxxx,maxxleft);
                  }
                  if(left>=0&&right<words.size())
                  {
                               maxxx=max(maxxx,prefix(words[left],words[right]));
                            //    if(i==1)
                            //    cout<<maxxx<<endl;
                  }
                  if(right<words.size()-1)
                  {
                         maxxx=max(maxxx,prer[right]);
                  }
                  ans.push_back(maxxx);
         }
         return ans;

    }
};