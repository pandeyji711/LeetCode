class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

      int ans1=INT_MAX;
      int ans2=INT_MAX;
          //case 1 water -> land
          int earliest_finish_water=INT_MAX;
          for(int i=0;i<waterStartTime.size();i++)
          {
                   earliest_finish_water=min(earliest_finish_water,waterStartTime[i]+waterDuration[i]);
          }
          for(int i=0;i<landStartTime.size();i++)
          {
                    if(landStartTime[i]<=earliest_finish_water)
                    {
                             ans1=min(ans1,earliest_finish_water+landDuration[i]);
                    }else{
                           ans1=min(ans1,landStartTime[i]+landDuration[i]);
                    }
          }
        //case 2 land -> water
          int earliest_finish_land=INT_MAX;
          for(int i=0;i<landStartTime.size();i++)
          {
                   earliest_finish_land=min(earliest_finish_land,landStartTime[i]+landDuration[i]);
          }
          for(int i=0;i<waterStartTime.size();i++)
          {
                    if(waterStartTime[i]<=earliest_finish_land)
                    {
                             ans2=min(ans2,earliest_finish_land+waterDuration[i]);
                    }else{
                           ans2=min(ans2,waterStartTime[i]+waterDuration[i]);
                    }
          }


        return min(ans1,ans2);
    }
};