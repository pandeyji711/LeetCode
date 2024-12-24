class Solution {
public:
 bool cheak( int ind ,vector<int>& nums)
 {
          unordered_map<int,int>m;
          for( int i=ind*3;i<nums.size();i++)
          {
                  m[nums[i]]++;
                  if(m[nums[i]]>1)
                  return false;
          }
               return true;
 }
    int minimumOperations(vector<int>& nums) {
            
            int ans=0;
            int ind=0;
            if(nums.size()<3)
            {
                  if(cheak(0,nums))
                  return 0;
                  else 
                  return 1;
            }
            while(ind<nums.size()-2)
            {
                    
                    if( cheak(ind,nums))
                     {
                        return ans;
                     }
                     else
                     ans++;
                     ind++;
            }
            return ans;
    }
};