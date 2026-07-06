class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        for(int i=0;i<intervals.size();i++)
        { 
             int a=intervals[i][0];
             int b=intervals[i][1];
               for(int j=0;j<intervals.size();j++)
               {
                    if(i==j||intervals[j][0]==-1)continue;

                      if(intervals[j][0]<=a&&intervals[j][1]>=b)
                      {
                           intervals[i][0]=-1;
                           intervals[i][0]=-1;
                           ans++;
                        //    cout<<j<<" "<<i<<endl;
                           break;
                      }
               }
        }
        return intervals.size()-ans;
    }
};