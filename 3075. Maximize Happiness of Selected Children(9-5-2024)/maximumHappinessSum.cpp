class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.begin(),happiness.end(),greater<int>());
       int cnt=0;
       for(int i=0;i<k;i++)
       {
             if(happiness[i]-cnt>=0)
             {  happiness[i]-=cnt;
                cnt++;
                ans+= happiness[i];
             }
       }
       return ans;
       
    }
};