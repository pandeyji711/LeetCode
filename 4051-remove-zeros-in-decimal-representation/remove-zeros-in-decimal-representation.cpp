class Solution {
public:
    long long removeZeros(long long n) {
        long long ans=0;
        string s=to_string(n);
        for(char &c:s)
        {
              if(c=='0')
              continue;
              ans=ans*10+(c-'0');
        }
        return ans;
    }
};