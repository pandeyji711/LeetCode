class Solution {
public:
    int partitionString(string s) {
        // int l=0;
        // int r=0;
        unordered_map<char,int>m;
        // char uni=s[0];
  int ans=0;
        for(int i=0;i<s.length();i++)
        {
             m[s[i]]++;
                  if(m[s[i]]>1)
                  {
                       ans++;
                       m.clear();
                       m[s[i]]++;

                  }
        }
        return ans+1;
    }
};