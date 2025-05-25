class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>dm;
        for(int i=0;i<words.size();i++)
        {
                   if(words[i][0]!=words[i][1])
                  dm[words[i]]++;
        }
        int diff=0;
        unordered_map<string ,int>mvis;
        for(auto a1:dm)
        {
               string str=a1.first;
               sort(str.begin(),str.end());
               if(mvis.find(str)!=mvis.end())continue;

               mvis[str]++;
               int x=a1.second;
               string st=a1.first;
               reverse(st.begin(),st.end());
               int y=dm[st];
               diff+=min(x,y);


        }

         unordered_map<string,int>sm;
        for(int i=0;i<words.size();i++)
        {
                   if(words[i][0]==words[i][1])
                  sm[words[i]]++;
        }
        int same=0;
        int odd=0;
        for(auto a1:sm)
        {
                if(a1.second%2!=0)
                {
                      odd=1;
                          same+=a1.second-1;

                }else{
                    same+=a1.second;
                }
        }
        return diff*4+same*2+odd*2;

    }
};