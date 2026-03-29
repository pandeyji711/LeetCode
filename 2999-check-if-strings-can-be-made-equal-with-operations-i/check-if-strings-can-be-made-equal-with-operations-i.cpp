class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<s1.length();i++)
        {
                 if(s1[i]!=s2[i])
                 {
                     if(i+2>=s1.length()||s1[i+2]!=s2[i])return false;
                    swap(s1[i],s1[i+2]);
                 }
        }
        return true;
    }
};