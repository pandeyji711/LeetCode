class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
           vector<int>v;
           int pre=0;
           for(int i=0;i<startTime.size();i++)
           {
                   int val=startTime[i]-pre;
                   v.push_back(val);
                   pre=endTime[i];
           }
           v.push_back(eventTime-endTime[endTime.size()-1]);
           int wind=k+1;
           int sum=0;
           int ans=0;
           for(int i=0;i<min(wind,(int)v.size());i++)
           {
                    sum+=v[i];
           }
           ans=max(ans,sum);
           int r= wind;
           int l=0;
           while(r<v.size())
           {
                     sum+=v[r];
                     sum-=v[l];
                     ans=max(ans,sum);
                     r++;
                     l++;
           }
           return ans;
    }
};