class Solution {
public:
   bool check(vector<int>&bits,int val)
   {
                int p=0;
                 while(val)
                 {
                      if((val&1)&&bits[p]==0)
                      {
                            return false;
                      }
                      p++;
                      val=val>>1;
                 }
                 return true;
   }
    vector<int> smallestSubarrays(vector<int>& nums) {
        int sum=0;
        vector<int>presum(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--)
        {
              sum=sum|nums[i];
                presum[i]=sum;
              
         }
         vector<int>bits(32,0);
         int p=0;
         int siz=0;
        //  cout<<sum<<endl;
        //  while(sum)
        //  {
        //        if(sum&1)
        //        {
        //            m[p]=1;
        //         //    cout<<p<<endl;
        //            siz++;
        //        }
        //        p++;
        //        sum=sum>>1;
        //  }
         int l=0;
         int r=0;
         int maxx=0;
         int ind1=0;
         int ind2=nums.size()-1;
         vector<int>ans;
         int siz1=0;
         while(r<nums.size())
         {
                   int p1=0;
                   int tem=nums[r];
                  while(tem)
                 {
                     if((tem&1))
                      {
                            bits[p1]++;
                      }
                  tem=tem>>1;
                  p1++;
                  }
                  
                   while(l<=r&&check(bits,presum[l]))
                   {
                    //   cout<<l<<" ";
                       ans.push_back(r-l+1);

                                int p2=0;
                   int tem1=nums[l];
                  while(tem1)
                 {
                     if((tem1&1))
                      {
                           bits[p2]--;
                       }
                  tem1=tem1>>1;
                  p2++;
                  }
                    
                         l++;
                   }

                  r++;
         }
        //  if(ans.size()<nums.size())
        //  while(l<r)
        //  {
        //       ans.push_back(r-l);
        //       l++;
        //  }
       
         return ans;
    }
};