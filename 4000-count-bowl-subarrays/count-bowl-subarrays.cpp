class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long  ans=0;
        queue<int>q;
        stack<pair<int,int>>st;
        int cnt=0;
        int currcnt=0;
        for(int i=0;i<nums.size();i++)
        {
              bool ga=false;
                //   while(!q.empty()&&q.front()==i)
                //   {
                //       cnt++;
                //       q.pop();
                //   }
                 while(!st.empty()&&st.top().first<nums[i])
                  {
                        //  cout<<st.top().first<<" "<<st.top().second<<endl;
                            if(i-st.top().second+1>=3)
                              ans++;
                              st.pop();
                    
                    
                  }
               
                  st.push({nums[i],i});

        }
        // cout<<ans<<endl;
         queue<int>q1;
        stack<pair<int,int>>st1;
        int cnt1=0;
        int currcnt1=0;
        int n=nums.size();
       for(int i=n-1;i>=0;i--)
        {
              bool ga=false;
                //   while(!q1.empty()&&q1.front()==i)
                //   {
                //       cnt1++;
                //       q1.pop();
                //   }
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