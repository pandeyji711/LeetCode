class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
          long long ans=0;
          long long cost=max(1,brightness%3==0?brightness/3:brightness/3+1);
        sort(intervals.begin(),intervals.end());
        int st=intervals[0][0];
        int end=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++)
        {
             if(intervals[i][0]>end)
             {
                ans=ans+(end-st+1)*cost;
                 st=intervals[i][0];
                 end=intervals[i][1];
             }else{
                  end=max(end,intervals[i][1]);
             }
        }
         ans=ans+1LL*(end-st+1)*1LL*cost;

 return ans;

    }
};

// 0 1 0 0 

