class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n=heights.size();
        vector<int>rs(heights.size(),n);
        vector<int>ls(heights.size(),-1);
        stack<int>st;
          st.push(0);
          for(int i=1;i<heights.size();i++)
          {
                   while(!st.empty()&&heights[st.top()]>heights[i])
                   {
                         rs[st.top()]=i;
                        
                        //  cout<< rs[st.top()]<<" ";
                          st.pop();
                   }
                   st.push(i);
          }
          stack<int>st1;

          st1.push(n-1);
          for(int i=n-2;i>=0;i--)
          {
                   while(!st1.empty()&&heights[st1.top()]>heights[i])
                   {
                         ls[st1.top()]=i;
                        
                        //  cout<< rs[st.top()]<<" ";
                          st1.pop();
                   }
                   st1.push(i);
          }

int ans=0;
       for(int i=0;i<n;i++)
       {
             int left=i-(ls[i]+1);
             int right=(rs[i]-1)-i;
               int h=heights[i]*(left+right+1);
               ans=max(ans,h);
       }
          return ans;
    }
};