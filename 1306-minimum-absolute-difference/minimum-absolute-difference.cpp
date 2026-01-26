class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int ans=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++)
        {
                ans=min(ans,abs(arr[i+1]-arr[i]));
        }
        vector<vector<int>>v;
        for(int i=0;i<arr.size()-1;i++)
        {
                int tem=abs(arr[i+1]-arr[i]);
                if(tem==ans)
                {
                      v.push_back({arr[i],arr[i+1]});
                }
        }
        return v;
    }
};