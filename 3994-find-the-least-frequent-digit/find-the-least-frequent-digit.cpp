class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int,int>m;
        while(n)
            {
                  m[n%10]++;
                n=n/10;
            }
        int f=INT_MAX;
        int ans=0;
        for(auto a1:m)
            {
                if(a1.second<f)
                {
                      f=a1.second;
                    ans=a1.first;
                }
            }
        return ans;
    }
};