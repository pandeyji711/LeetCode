class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>m;
        if(k>s.length())
        return false;
        for(int i=0;i<s.length();i++)
        {
               m[s[i]]++;
        }
        int odd=0;
        int even=0;
        for(auto a1:m )
        {
               if(a1.second%2!=0)
               odd++;
               else
               even++;
        }
        if(odd>k)
        return false;
        return true;
    }
};