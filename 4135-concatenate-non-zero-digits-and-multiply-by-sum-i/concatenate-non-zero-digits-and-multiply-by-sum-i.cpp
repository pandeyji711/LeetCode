class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>v;
        int sum=0;
        long long ans=0;
        while(n)
        {
              if(n%10!=0)
               v.push_back(n%10);
              sum+=n%10;
               n=n/10;
              

        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
               ans=ans*10+v[i];
        }
       
        return ans*sum;      
    }
};