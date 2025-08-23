class Solution {
public:
vector<vector<int>>ans;
   void nextper(vector<int>& nums)
   {
          int r=nums.size()-2;
            while(r>=0)
            {
                  if(nums[r]<nums[r+1]){
                    break;
                  }
                  r--;
                   
            }
            if(r<0)
            return;
            int l=nums.size()-1;
             while(l>r)
            {
                  if(nums[r]<nums[l]){
                    break;
                  }
                  l--;
                   
            }
            swap(nums[l],nums[r]);
            reverse(nums.begin()+r+1,nums.end());
            ans.push_back(nums);
            nextper(nums);

            


   }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ans.push_back(nums);
        nextper(nums);
        return ans;
    }
};