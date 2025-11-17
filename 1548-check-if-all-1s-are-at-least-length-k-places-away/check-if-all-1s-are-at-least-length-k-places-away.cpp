class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last=-1;
        for(int i=0;i<nums.size();i++)
        {
                if(nums[i]==1)
                {
                    
                  if(last==-1)
                  {
                     last=i;
                     continue;
                  }
                  int dis=abs(last-i)-1;
                     if(dis<k)
                     {
                      
                        return 0;

                     }
                     last=i;
                    
                }

        }
        return 1;
    }
};