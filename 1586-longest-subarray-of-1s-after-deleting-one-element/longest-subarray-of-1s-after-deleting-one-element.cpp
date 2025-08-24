class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>>vp;
        int dub=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++)
        { 
                if(dub!=nums[i])
                {
                      vp.push_back({cnt,dub});
                      cnt=0;
                     
                      dub=nums[i];
                }
                cnt++;
        }
         vp.push_back({cnt,dub});
         int ans=0;
         bool de=false;
         for(int i=0;i<vp.size();i++)
         {
              if(vp[i].second==1&&ans<vp[i].first){
                 de=false;
                 ans=vp[i].first;

              }
                  if(i+2<vp.size())
                  {
                       if(vp[i].second==1&&vp[i+1].second==0&&vp[i+2].second==1)
                       {
                              if(vp[i+1].first==1)
                              {
                                   if(ans<=vp[i].first+vp[i+2].first)
                                     {
                                          ans=vp[i].first+vp[i+2].first;
                                          de=true;
                                     }
                              }
                       }
                  }
         }
         if(ans==0)
         return ans;
           if(vp.size()==1)
         return ans-1;
         
         return ans;
       


    }
};