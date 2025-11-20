class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cnta=0;
        int cntb=0;
        for(int i=0;i<s.length();i++)
        {
               if(s[i]=='a')
               cnta++;
               else
               cntb++;
        }
        return abs(cnta-cntb);
    }
};