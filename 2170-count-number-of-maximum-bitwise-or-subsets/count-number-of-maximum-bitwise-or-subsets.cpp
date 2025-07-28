class Solution {
public:
  int ans=0;
  int maxx=0;
  void solve(vector<int>& nums,int ind,int o)
  {
          if(ind>=nums.size()){
            // cout<<o<<" "; 
           if(o>maxx)
           {
              ans=1;
              maxx=o;
           }else if(o==maxx) {
                    ans++;
           }
          return ;

          }
          solve(nums,ind+1,o|nums[ind]);
          solve(nums,ind+1,o);
  }
    int countMaxOrSubsets(vector<int>& nums) {
          solve(nums,0,0);
          return ans;
    }
};