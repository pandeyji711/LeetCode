class Solution {
public:
    vector<string> partitionString(string s) {
        string str;
        unordered_map<string,int>sm;
        vector<string>ans;
        for(int i=0;i<s.length();i++)
        {
             
                 str.push_back(s[i]);
                 if(str!=""&&sm.find(str)==sm.end())
                 {
                       ans.push_back(str);
                       sm[str]=1;
                       str="";
                 }
        }
        if(str!=""&&sm.find(str)==sm.end())
                 {
                       ans.push_back(str);
                       str="";
                 }
        return ans;

    }
};