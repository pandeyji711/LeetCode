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
    queue<pair<int,int>>q;
        for(int i=0;i<nums.size();i++)
        {
              if(nums[i]==key)
                 q.push({i-k,i+k+1});
        }
   queue<int>q2;
    vector<int>ans;
     for(int  i=0;i<nums.size();i++)
     {
                while(!q.empty()&&q.front().first<=i)
                { 
                    q2.push(q.front().second);
                    // cout<<i<<" ";
                    q.pop();
                }
                while(!q2.empty()&&q2.front()<=i)
                {
                      q2.pop();
                }
                if(q2.size()>0)
                ans.push_back(i);
     }

        // for(int i=0;i<nums.size();i++)
        // {
        //        if(nums[i]==key)
        //        {
        //                //left
        //     int left=max(0,i-k);
        //   for(int l=i;l>=left;l--)
        //   {
        //     //    if(vis[l]==1)break;
        //        vis[l]=1;
        //   }
        //   //right
        //      int n=vis.size()-1;
        //   int right=min(n,i+k);
        //   for(int l=i+1;l<=right;l++)
        //   {
        //     //   if(vis[l]==1)break;
        //       vis[l]=1;
        //   }
        //        }
        // }
        // vector<int>ans;
        // for(int i=0;i<vis.size();i++)
        // {

        //       if(vis[i]==1)
        //       ans.push_back(i);
        // }
        return ans;
    }
};