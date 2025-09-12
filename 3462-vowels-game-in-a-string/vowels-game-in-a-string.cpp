class Solution {
public:
 bool isvoval(char s)
 {
         if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
         return true;
         return false;
 }
    bool doesAliceWin(string s) {
        int cnt=0;
        for(char a:s)
        {
             if(isvoval(a))
             cnt++;
        }
        if(cnt==0)return false;
        return true;
    }
};