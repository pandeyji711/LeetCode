class Solution {
public:
    string majorityFrequencyGroup(string s) {
        
        unordered_map<char,int>m;
        for(char c:s)
        {
               m[c]++;
        }
        map<int,string>ms;
        for(auto a1:m)
        {
             ms[a1.second].push_back(a1.first); 
        }
        string ans;
        int siz=0;
        for(auto a1:ms)
        {
               if(a1.second.length()>=siz)
               {
                 ans=a1.second;
                    siz=a1.second.length();
               }
        }
        return ans;

    }
};