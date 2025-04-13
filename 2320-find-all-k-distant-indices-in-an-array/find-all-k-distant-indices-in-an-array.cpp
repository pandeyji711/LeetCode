class Solution {
public:
  void mark(vector<int>&vis, int ind,int k)
  {
            //left
            int left=max(0,ind-k);
          for(int i=ind;i>=left;i--)
          {

               vis[i]=1;
          }
          //right
         int n=vis.size()-1;
          int right=min(n,ind+k);
          for(int i=ind+1;i<=right;i++)
          {
              vis[i]=1;
          }
  }
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>vis(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
               if(nums[i]==key)
               {
                       //left
            int left=max(0,i-k);
          for(int l=i;l>=left;l--)
          {

               vis[l]=1;
          }
          //right
         int n=vis.size()-1;
          int right=min(n,i+k);
          for(int l=i+1;l<=right;l++)
          {
              vis[l]=1;
          }
               }
        }
        vector<int>ans;
        for(int i=0;i<vis.size();i++)
        {
              if(vis[i]==1)
              ans.push_back(i);
        }
        return ans;
    }
};