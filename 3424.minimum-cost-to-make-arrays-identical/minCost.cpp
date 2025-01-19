class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        if(arr==brr)
        return 0;
      long long ans1=0;
         for(int i=0;i<arr.size();i++)
        {
              long long te=arr[i]-brr[i];
                  int diff=abs(te);
                  ans1+=diff;

        }
        vector<pair<int,int>>v1;
         vector<pair<int,int>>v2;
           for(int i=0;i<arr.size();i++)
        {
               v1.push_back({arr[i],i});

        }
              for(int i=0;i<brr.size();i++)
        {
               v2.push_back({brr[i],i});

        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        long long ans=0;
        bool is=false;
        for(int i=0;i<v1.size();i++)
        {
               long long te=v1[i].first-v2[i].first;
                int diff=abs(te);
                if(v1[i].second!=v2[i].second)
                is=true;
                ans+=diff;

        }
        long long  tem1=min(ans1, ans+k);
        long long tem2=min(ans,ans1);
    if(is)
      return tem1;
      return tem2;
        // return arr.size()>1?ans+k:ans;
    }
};