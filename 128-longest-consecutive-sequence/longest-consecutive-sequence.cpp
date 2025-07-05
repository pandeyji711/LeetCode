class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
                    if(set.find(nums[i]-1)==set.end())
                    {
                            int cnt=1;
                            int tem=nums[i];
                            while(set.find(tem+1)!=set.end())
                            {
                                  cnt++;
                                  tem++;

                            }
                            if(cnt>=(nums.size()+1)/2)return cnt;
                            ans=max(ans,cnt);
                    }
        }
        
        return ans;
    }
};