class Solution {
public:
    int hIndex(vector<int>& citations) {
        unordered_map<int,int>m;
        for(int i=1;i<=citations.size();i++)
        {
               int tem=i;
               for(int j=0;j<citations.size();j++)
               {
                     if(citations[j]>=tem)
                     {
                               m[tem]++;
                     }
               }
        }
        int ans=0;
        for(auto a1:m)
        {
               if(a1.first<=a1.second)
               {
                  ans=max(a1.first,ans);
               }
        }
        return ans;
    }
};