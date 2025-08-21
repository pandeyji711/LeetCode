class Solution {
public:
  vector<vector<int>>ans;
  map<vector<int>,int>m;
   void solve(vector<int>& nums,int ind, vector<int>tem)
   {
       if(ind>=nums.size())
       {
        //   sort(tem.begin(),tem.end());
            if(!m.count(tem)){
            ans.push_back(tem);
               m[tem]=1;
            }
            
            return;
       }
       tem.push_back(nums[ind]);
       solve(nums,ind+1,tem);
       tem.pop_back();
       solve(nums,ind+1,tem);

   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>tem;
        sort(nums.begin(),nums.end());
        solve(nums,0,tem);
        return ans;
    }
};