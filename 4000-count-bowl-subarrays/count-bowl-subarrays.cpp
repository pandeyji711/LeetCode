class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long  ans=0;
      
        stack<pair<int,int>>st;
      
        for(int i=0;i<nums.size();i++)
        {
                 while(!st.empty()&&st.top().first<nums[i])
                  {
                       
                            if(i-st.top().second+1>=3)
                              ans++;
                              st.pop();
                    
                    
                  }
               
                  st.push({nums[i],i});

        }
        
        stack<pair<int,int>>st1;
        int n=nums.size();
       for(int i=n-1;i>=0;i--)
        {
            
                 while(!st1.empty()&&st1.top().first<nums[i])
                  {
                          if(abs(st1.top().second-i+1>=3))
                              ans++;
                              st1.pop();
                    
                      
                  }
                 
                  st1.push({nums[i],i});

        }
        return ans;

    }
};