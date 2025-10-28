class Solution {
public:
  int move(vector<int>nums,int  r,int ind,int sum)
  {
     
         while(true)
         {
               while(r==true&&ind<nums.size())
               {
                      if(nums[ind]>0)
                      {
                         nums[ind]--;
                         sum--;
                         r=!r;
                         break;
                      }
                      ind++;
                      if(ind==nums.size()){
                          if(sum==0)return 1;
                          else
                          return 0;
                      }

               }
                while(r==false&&ind>=0)
               {
                      if(nums[ind]>0)
                      {
                         nums[ind]--;
                         r=!r;
                         sum--;
                         break;
                      }
                      ind--;
                      if(ind<0){
                          if(sum==0)return 1;
                          else
                          return 0;
                      }

               }
         }
         return 0;
  }
    int countValidSelections(vector<int>& nums) {
            int ans=0;
            int sum=0;
            vector<int>preright(nums.size()+1,0);
            vector<int>preleft(nums.size()+1,0);
   preleft[0]=0;
              for(int i=0;i<nums.size();i++)
                {
                    preleft[i+1]=preleft[i]+nums[i];
                }
                preright[nums.size()]=0;
              for(int i=nums.size()-1;i>=0;i--)
                {
                    preright[i]=preright[i+1]+nums[i];
                }
              for(int i=0;i<nums.size();i++)
              {
                   if(nums[i]==0)
                   {
                        int left=preleft[i];
                        int right=preright[i];
                        if(left==right)
                        ans+=2;
                        else if(abs(left-right)==1)
                        ans+=1;
                        cout<<i<<" "<<ans<<endl;
                   }
              }
                return ans;
    }
};