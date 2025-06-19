class Solution {
public:
     bool sum(vector<int>& nums,int win,int t)
     {
        int sum=0;
                 for(int i=0;i<win;i++)
                 {
                    sum+=nums[i];    
                 }
                 if(sum>=t)return true;
                 int l=0;
                 int r=win;
                 while(r<nums.size())
                 {
                         sum-=nums[l];
                         sum+=nums[r];
                         if(sum>=t)return true;
                         l++;
                         r++;


                 }
                 return false;
     }
    int minSubArrayLen(int target, vector<int>& nums) {
        // vector<int>pres(nums.size()+1,0);
        // unordered_map<int,int>m;
        // for(int i=0;i<nums.size();i++)
        // {
        //               pres[i+1]=pres[i]+nums[i];
        //             //   cout<<pres[i+1]<<" ";
        // }
        // // cout<<endl;
        // int ans=INT_MAX;
        //  for(int i=0;i<nums.size()+1;i++)
        // {
        //     //   cout<<abs(pres[i]-target)<<" ";
        //          if(m.find((pres[i]-target))!=m.end())
        //          {
        //             //  cout<<"k";
        //              cout<<(pres[i]-target)<<" "<<i<<" "<<(i-1)-m[pres[i]-target]<< endl;

        //                 ans=min(ans,(i-1)-m[pres[i]-target]);
        //          }
        //          m[pres[i]]=i-1;
        // }
        int ans=INT_MAX;
      int l=1;
      int  r=nums.size();
      while(l<=r)
      {
           int mid=l+(r-l)/2;
           if(sum(nums,mid,target))
           {
              ans=mid;
              r=mid-1;
           }
             else{
                    l=mid+1;
             }
            //  cout<<"k";
      }
        return ans==INT_MAX?0:ans;

    }
};