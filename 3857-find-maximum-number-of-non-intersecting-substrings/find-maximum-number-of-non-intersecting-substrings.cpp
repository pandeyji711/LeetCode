class Solution {
public:
    int maxSubstrings(string s) {
        unordered_map<char,int>m;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
                if(m.find(s[i])!=m.end()&&m[s[i]]<=i)
                {
                       ans++;
                       m.clear();
                }else if(m.find(s[i])==m.end()){
                      m[s[i]]=i+3;
                }
        }
        return ans;
    }
};