class Solution {
public:
   bool check_prime(long long num)
   {
           if(num<=1)return false;
           if(num==2)return true;
           if(num%2==0)return false;
           for(long long  i=3;i*i<=num;i=i+2)
           {
                   if(num%i==0)return false;
           }
           return true;

   }
    long long sumOfLargestPrimes(string s) {
        
          long long ans=0;
        map<long long,int>v;
          for(int i=0;i<s.length();i++)
          {
                 long long tem=0;
                  for(int j=i;j<s.length();j++)
                  {
                       tem=tem*10+(s[j]-'0');
                       if(check_prime(tem)){
                    //    cout<<tem<<" ";
                       v[tem]++;
                       }
                  }
          }
          vector<long long>v1;
        //   sort(v.rbegin(),v.rend());
        for(auto a1:v)
        {
              v1.push_back(a1.first);
        }
          sort(v1.rbegin(),v1.rend());
          int t=3;
          int siz=v.size();
          t=min(3,siz);
          int ind=0;
          while(t--)
          {
                ans+=v1[ind];
                ind++;
          }
          return ans;
    }
};