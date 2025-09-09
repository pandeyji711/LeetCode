class Solution {
public:
 bool ch(int n)
 {
       while(n)
       {
            if(n%10==0)return false;
            n=n/10;
       }
       return true;
 }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n;i++)
        {
              if(ch(i)&&ch(n-i))
              return {i,n-i};
        }
        return {};
    }
};