class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>left(nums.size()+1,0);
        vector<int>right(nums.size()+1,0);
        // left->right
        for(int i=0;i<nums.size();i++)
        {
             left[i+1]=left[i]+nums[i];
        }
        // right->left
        for(int i=nums.size()-1;i>=0;i--)
        {
             right[i]=right[i+1]+nums[i];
        }
        vector<int>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            //  cout<<right[i]<<" "<<left[i]<<endl;
             ans[i]=abs(right[i+1]-left[i]);
        }
        return ans;
    }
};