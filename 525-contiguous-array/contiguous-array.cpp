class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         unordered_map<int,int>meo;
         unordered_map<int,int>moe;
         unordered_map<int,int>m;
         int e=0;
         int o=0;
         int ans=0;
        //  meo

         for(int i=0;i<nums.size();i++)
         {
              if(nums[i]%2==0)e++;
              else
              o++;
             
              if(e>o)
              {
                
                  if(meo.count(e-o))
                  {
                    
                       ans=max(ans,(i-meo[e-o]));
                      
                  }else{
                       meo[e-o]=i;
                  }
              }else if(o>e){
                       if(moe.count(o-e))
                  {
                       ans=max(ans,(i-moe[o-e]));
                     
                  }else{
                       moe[o-e]=i;
                  }
              }else{
                 ans=max(ans,i+1);
                //  cout<<i<<"k";
              }
            //   cout<<i<<" "<<ans<<endl;
               
         }
         return ans;
    }
};