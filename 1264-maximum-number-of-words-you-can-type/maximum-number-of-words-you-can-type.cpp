class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        unordered_map<char,int>m;
         for(char a:brokenLetters)
         {
                m[a]=1;
         }
         string tem;
         int ans=0;
         while(ss>>tem)
         {
              bool yea=true;
                for(char a:tem)
                {
                     if(m.count(a))
                     {
                         yea=false;
                         break;
                     }
                }
                if(yea)
                ans++;
         }
         return ans;
    }
};