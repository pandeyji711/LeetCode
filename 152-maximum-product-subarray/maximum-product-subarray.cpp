class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // vector<int>pre(nums.size()+1,1);
        // vector<int>suff(nums.size()+1,1);
        // pre[1]=nums[0];
        // for(int i=1;i<nums.size();i++)
        // {
        //       pre[i]=pre[i-1]*nums[i];
        // }
        int n=nums.size();
        // suff[n-1]=nums[n-1];

        // for(int i=n-2;i>=0;i--)
        // {
        //      pre[i]=pre[i+1]*nums[i];
        // }
         int curr=nums[0];
         int ans=nums[0];
         int pre=nums[0];
         for(int i=1;i<nums.size();i++)
         {
               if(curr==0)
               {
                   curr=nums[i];
                   pre=nums[i];
               }
              else if(nums[i]==0)
               {
                   ans=max(ans,nums[i]);
                  
                   curr=INT_MIN;
                   pre=INT_MIN;
                 
               }else{
                     if(curr<0&&nums[i]<0)
                     {
                        if(curr==INT_MIN){
                        
                         curr=nums[i];

                         }else
                         curr*=nums[i];
                     }else if(curr>0&&nums[i]<0){
                       
                           curr=INT_MIN;
                     }else if(curr<0&&nums[i]>0)
                     {
                        curr=nums[i];
                     }
                     else if(curr>0&&nums[i]>0)
                     {
                           curr*=nums[i];
                     }
                     if(pre==INT_MIN){
                     pre=1;
                     pre*=nums[i];
                     }
                     else
                       pre*=nums[i];
                     if(pre>curr)
                     curr=pre;
                    //  cout<<curr<<" ";
                     
               }
               ans=max({ans,curr});
         }
           curr=nums[n-1];
          ans=max(ans,nums[n-1]);
          pre=nums[n-1];
           for(int i=n-2;i>=0;i--)
         {
               if(curr==0)
               {
                   curr=nums[i];
                   pre=nums[i];
               }
              else if(nums[i]==0)
               {
                   ans=max(ans,nums[i]);
                  
                   curr=INT_MIN;
                   pre=INT_MIN;
                 
               }else{
                     if(curr<0&&nums[i]<0)
                     {
                         if(curr==INT_MIN){
                        
                         curr=nums[i];

                         }else
                         curr*=nums[i];
                     }else if(curr>0&&nums[i]<0){
                       
                           curr=INT_MIN;
                     }else if(curr<0&&nums[i]>0)
                     {
                        curr=nums[i];
                     }
                     else if(curr>0&&nums[i]>0)
                     {
                           curr*=nums[i];
                     }
                     if(pre==INT_MIN){
                     pre=1;
                     pre=nums[i];
                     }
                     else
                       pre*=nums[i];
                     if(pre>curr)
                     curr=pre;
                   
                     
               }
                //  cout<<curr<<" "<<pre<<endl;
                  ans=max({ans,curr});
         }
         return ans;


    }
};