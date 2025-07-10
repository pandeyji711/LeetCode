class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
            vector<int>v;
           int pre=0;
             int gapcnt=0;
           for(int i=0;i<startTime.size();i++)
           {
                   int val=startTime[i]-pre; // collact the gap for sliding window
                   gapcnt++;
                   v.push_back(val);
                   int meet=endTime[i]-startTime[i];
                   v.push_back(meet);
                   pre=endTime[i];
           }
           v.push_back(eventTime-endTime[endTime.size()-1]);  //last gap
           gapcnt++;
           vector<int>lpresum(v.size()+2,0);
           int k=0;
            int ind=gapcnt;
           for(int i=v.size()-1;i>=0;i--,k++)
           {
                         if(k%2==0)
                         {
                             lpresum[i+1]=max(lpresum[i+2],v[i]);
                             
                         }else
                        lpresum[i+1]=lpresum[i+2];
           }
           int maxx=0;
           int ans=0;
           for(int i=0;i<v.size()-2;i=i+2)
           {
                   int l=v[i];
                   int meet=v[i+1];
                   int r=v[i+2];
                //    cout<<l<<" "<<meet<<" "<<r<<endl;
                   if(maxx>=meet||lpresum[i+4]>=meet)
                   {
                      
                       ans=max(ans,l+meet+r);
                    //    cout<<ans<<" "<<lpresum[i+4]<<" "<<maxx<<endl;
                   }else
                   ans=max(ans,l+r);
                   maxx=max(maxx,l);

           }
        return ans;
    }
};