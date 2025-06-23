class Solution {
public:
  bool isprime(int n)
  {
       if(n<=1)return false;
       if(n==2)return true;
       if(n%2==0)return false;
       for(int i=3;i*i<=n;i++)
       {
           if(n%i==0)return false;
       }
       return true;
  }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
                   m[nums[i]]++;
        }
        for(auto &a1:m)
        {
              if(isprime(a1.second))return true;
        }
        return false;
    }
};