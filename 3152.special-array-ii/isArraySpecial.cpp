class Solution {
public:
  void fill(vector<int>& nums,vector<bool>&v)
  {
             for(int i=0;i<nums.size()-1;i++)
             {
                  if(nums[i]%2==0&&nums[i+1]%2==0)
                  v[i+1]=0;
                  else if(nums[i]%2!=0&&nums[i+1]%2!=0)
                  v[i+1]=0;
             }
             
  }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
             int n=nums.size();
            vector<bool>v(n,1);
             vector<bool>ans;
            fill(nums,v);
            vector<int>psum;
            psum.push_back(v[0]);
            // cout<<v[0]<<" ";
            for( int i=1;i<v.size();i++)
            {
                    psum.push_back(psum[i-1]+v[i]);
                    // cout<<psum[i]<<" ";
            }
            for(int i=0;i<queries.size();i++)
            {
                      int dis=queries[i][1]-queries[i][0];
                      int sum=psum[queries[i][1]]-psum[queries[i][0]];
                     ans.push_back(dis==sum);

            }
            return ans;
    }
};