class Solution {
public:
int const mod=1e9+7;

int power(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}
  bool isprime(int n)
  {
          if(n<=1)return 0;
          if(n==2)return 1;
          if(n%2==0)return 0;
          for(int i=3;i*i<=n;i+=2)
          {
               if(n%i==0)return 0;
          }
          return 1;
  }
   int primescore(int num)
   {
    int ans=0;
       int num1=num;
               for(int i=2;i*i<=num;i++)
               {
                    if(num1%i==0)
                    {

                            ans++;
                            // int p=1;
                            while(true)
                            {
                                // long long tem=pow(i,p);
                                   if(num1%i!=0)break;
                                num1=num1/i;
                            }
                    }
                   
               }
               if(num1>1)ans++;
               return ans;
   }
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
           vector<int>ps(nums.size(),0);
        //    cout<<isprime(29);
           for(int i=0;i<nums.size();i++)
           {
                  ps[i]=primescore(nums[i]);
                //   cout<<ps[i]<<" ";
           }
           vector<int>pindr(nums.size(),n);
           stack<int>st;
           st.push(0);

           //right next greater
           for(int i=1;i<n;i++)
           {
                       while(!st.empty()&&ps[st.top()]<ps[i])
                       {
                                pindr[st.top()]=i;
                                st.pop();
                       }
                       st.push(i);
           }
           //left next greater
            vector<int>pindl(nums.size(),-1);
           stack<int>st1;
           st1.push(n-1);

     
           for(int i=n-2;i>=0;i--)
           {
                       while(!st1.empty()&&ps[st1.top()]<=ps[i])
                       {
                                pindl[st1.top()]=i;
                                st1.pop();
                       }
                       st1.push(i);
           }




vector<pair<int,long long >>vp;
        for(int i=0;i<n;i++)
        {
               long long  r=pindr[i]-i;
               long long l=i-pindl[i];
               long long fre=1LL*(r*l);
               vp.push_back({nums[i],fre});

        }
     sort(vp.rbegin(),vp.rend());
     int  ans=1;
      for(int i=0;i<vp.size();i++)
      {
         if(k==0)break;
              int lena=min(1LL*k,vp[i].second);
              int num=vp[i].first;
               
              if (k < lena) {
    int x = power(num, k, mod);
    ans = (1LL * ans * x) % mod;
    return ans;
} else {
    int x = power(num, lena, mod);
    ans = (1LL * ans * x) % mod;
    if(lena>=k)return ans;
    k -= lena;
}
      }





        //    int st=ps[0];
        //   int stind=0;
        //   pq.push_back(nums[0]);
        //     for(int i=1;i<nums.size();i++)
        //    {
        //                   if(ps[i]<=st&&nums[stind]>=nums[i])
        //                   {
                              
        //                      pq.push_back(nums[stind]);
                                
        //                   }else{
        //                            pq.push_back(nums[i]);
        //                            st=ps[i];
        //                            stind=i;
        //                   }
        //    }
        //    sort(pq.begin(),pq.end(),greater<int>());
        // int ans=1;
        //    for(int i=0;i<k;i++)
        //    {
        //         // cout<<pq[i]<<" ";
        //            ans=((ans%mod)*pq[i])%mod;
        //    }
           return ans;
    }
};