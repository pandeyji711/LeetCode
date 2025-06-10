class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
                m[s[i]]++;
        }
        int even=INT_MAX;
        int odd =INT_MIN;
        for(auto &a1:m)
        {
                 if(a1.second%2==0)
                 {
                        even=min(even,a1.second);
                 }else
                 {
                            odd=max(odd,a1.second);
                 }
        }
        if(even==INT_MAX)
        {
            return odd;
        }else if(odd==INT_MIN)
        {
              return (-1)*even;
        }
        return odd-even;
    }
};