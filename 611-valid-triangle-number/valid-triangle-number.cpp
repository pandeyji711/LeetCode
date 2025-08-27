class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        
        int ans=0;
        if(arr.size()<3)return 0;
        sort(arr.begin(),arr.end());
         for(int i=0;i<arr.size()-2;i++)
         {
               for(int j=i+1;j<arr.size()-1;j++)
               {
                      int sum=arr[i]+arr[j];
                      auto it =lower_bound(arr.begin()+j+1,arr.end(),sum);
                      int cnt=0;
                      if(it==arr.end())
                      {
                             cnt=arr.size()-j-1;
                      }else
                      {
                             int ind=it-arr.begin();
                             cnt=ind-j-1;
                      }
                    //   cout<<cnt <<" ";
                      ans+=cnt;
               }
         }
         return ans;
    }
};