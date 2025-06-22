#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool isPrime(int n)
     {
          if(n<=1)return false;
          if(n==2)return true;
          if(n%2==0)return false;
          for(int i=3;i*i<=n;i=i+2)
          {
               if(n%i==0)return false;
          }
          return true;
     }

    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, ans = 0;
      
        multiset<int> primeSet;
           int firstprime=-1;
           int secondprime=-1;
        for (int r = 0; r < n; ++r) {
            if (isPrime(nums[r])){
             
                primeSet.insert(nums[r]);
                 firstprime=secondprime;
                   secondprime=r;
                
                
            
            }
            while (primeSet.size() >= 2 && (*primeSet.rbegin() - *primeSet.begin()) > k) {
                if (isPrime(nums[l]))
                    primeSet.erase(primeSet.find(nums[l]));
                ++l;
            }

            if (primeSet.size() >= 2)
                
                ans += (firstprime - l + 1); 
        }

        return ans;
    }
};
