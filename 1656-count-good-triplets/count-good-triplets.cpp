class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
       int ans=0;
        for(int i=0;i<arr.size();i++)
        {
                  
                  for(int j=i+1;j<arr.size();j++)
                  {
                       for(int k=j+1;k<arr.size();k++)
                       {
                               int a1=abs(arr[i] - arr[j]);
                               int b1=abs(arr[j] - arr[k]);
                               int c1=abs(arr[i] - arr[k]);
                               if(a1<=a&&b1<=b&&c1<=c)ans++;
                       }
                  }
        }
        return ans;
    }
};