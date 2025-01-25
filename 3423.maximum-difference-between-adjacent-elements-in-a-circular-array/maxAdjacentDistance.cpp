class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
       int maxx=INT_MIN;
        for(int i=0;i<2*nums.size();i++)
        {
                int ind=i%nums.size();
                int ind1=(i+1)%nums.size();
                int num=abs(nums[ind]-nums[ind1]);
                maxx=max(maxx,num);

        }
        return maxx;
    }
};