class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sum=0;
        int one=0;
        int zero=0;
        for(int i=0;i<s.length();i++)
        {
                if(s[i]=='0')
                zero++;
        }
        int p=0;
        for(int i=s.length()-1;i>=0;i--)
        {
                 if(s[i]=='1')
                 {
                        if(sum+pow(2,p)>k)
                        continue;
                        else
                        sum+=pow(2,p);
                        one++;
                 }
                 p++;
                 if(pow(2,p)>k)
                 break;
        }
        return  zero +one;
    }
};