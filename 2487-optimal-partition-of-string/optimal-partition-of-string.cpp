class Solution {
public:
    int partitionString(string s) {
        // int l=0;
        // int r=0;
        vector<int>m(26,0);
        // unordered_map<char,int>m;
        // char uni=s[0];
  int ans=0;
        for(int i=0;i<s.length();i++)
        {
             m[s[i]-'a']++;
                  if(m[s[i]-'a']>1)
                  {
                       ans++;
                      fill(m.begin(), m.end(), 0);
                       m[s[i]-'a']++;

                  }
        }
        return ans+1;
    }
};