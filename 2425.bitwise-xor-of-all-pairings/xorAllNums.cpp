class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long  ,long long >m;
        int n=nums1.size();
        int m1=nums2.size();
        for(int i=0;i<n;i++)
        {
              m[nums1[i]]+=m1;
        }
         for(int i=0;i<m1;i++)
        {
              m[nums2[i]]+=n;
        }
        int ans=0;
        for(auto a:m)
        {
            //    cout<<a.first<<" "<<a.second<<endl;
               if(a.second%2!=0)
               ans=ans^a.first;
        }
        return ans;
    }
};