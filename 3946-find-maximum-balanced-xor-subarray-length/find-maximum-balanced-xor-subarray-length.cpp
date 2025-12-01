class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        vector<int>prezor(nums.size()+1,0);
        int zor=0;
        vector<pair<int,int>>pre_even_odd(nums.size()+1,{0,0});
         map<pair<int,int>,int>m;
        int ans=INT_MIN;
        int diff=0;
        m[{0,0}]=-1;
        for(int i=0;i<nums.size();i++)
        {
              
                
                zor=zor^nums[i];
                if(nums[i]%2==0)
                {
                    
                       diff++;
                }
                else{
                        
                   
                       diff--;
                

                }
                 if(m.count({zor,diff}))
                 {
                    //  cout<<"k"<<;
                       ans=max(ans,i-m[{zor,diff}]);
                 }else{
                       m[{zor,diff}]=i;
                 }
            //      int ind=m[prezor[i+1]];
            //         int o=pre_even_odd[i+1].second-pre_even_odd[ind+1].second;
            //         int e=pre_even_odd[i+1].first-pre_even_odd[ind+1].first;
            //      if(m.count(prezor[i+1]))
            //    {
                  
            //         if(e==o)
            //          ans=max(ans,i-m[prezor[i+1]]);
                  
            //    }
            //     else if(o==e)
            //    {
                  
            //         if(m.count(prezor[i+1]))
            //          ans=max(ans,i-m[prezor[i+1]]);
            //          else{
            //                m[prezor[i+1]]=i;
            //          }
            //    }

                //  cout<<prezor[i+1]<<" "<<pre_even_odd[i+1].first<<" "<<pre_even_odd[i+1].second<<endl;
        }
        return ans==INT_MIN?0:ans;
    }
};
