class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n=nums.size();
            unordered_map<int,int>m;
            int ele=0;
            for(int i=0;i<nums.size();i++)
            {
                   m[nums[i]]++;
                   if(m[nums[i]]*2>n)
                   {
                       ele=nums[i];
                       break;
                   }
            }
            vector<int>prefor(n+1,0);
             vector<int>preback(n+1,0);
            for(int i=0;i<n;i++)
            {
                  if(nums[i]==ele)
                  {
                      prefor[i+1]=prefor[i]+1;
                  }else
                  prefor[i+1]=prefor[i];
            }
              for(int i=n-1;i>=0;i--)
            {
                  if(nums[i]==ele)
                  {
                      preback[i]=preback[i+1]+1;
                  }else
                  preback[i]=preback[i+1];
            }
            // int ans=-1;
             for(int i=0;i<n;i++)
            {
                  int siz1=i+1;
                  int siz2=n-i-1;
                
                  int cnt1=prefor[i+1];
                  int cnt2=preback[i+1];
                //   cout<<cnt1<<" "<<cnt2<<endl;
                  if((cnt1*2>siz1)&&(cnt2*2>siz2))return i;
            }
            return -1;
        }
    };