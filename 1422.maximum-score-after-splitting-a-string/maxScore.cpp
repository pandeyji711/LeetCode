class Solution {
public:
    int maxScore(string s) {
        
        int cnt1=0;
        int cnt0=0;
        for( int i=0;i<s.length();i++)
        {
               if(s[i]=='1')
               cnt1++;
               else
               cnt0++;
        }
        int ans=0;
        int tem1=0;
        int tem0=0;
        for(int i=0;i<s.length()-1;i++)
        {
               if(s[i]=='1')
               tem1++;
               else
               tem0++;
               int rem1=cnt1-tem1;
               ans=max(ans,tem0+rem1);
                
        }
        return ans;
    }
};