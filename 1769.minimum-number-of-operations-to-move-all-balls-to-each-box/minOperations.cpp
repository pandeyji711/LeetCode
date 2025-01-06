class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.length());
        for(int i=0;i<boxes.length();i++)
        {
             int cnt=0;
              //right
              for( int j=i+1;j<boxes.length();j++)
              {
                     if(boxes[j]=='1')
                     {
                         cnt+=(j-i);
                     }
              }
              //left
                for( int j=i-1;j>=0;j--)
              {
                     if(boxes[j]=='1')
                     {
                         cnt+=(i-j);
                     }
              }
              ans[i]=cnt;
        }
        return ans;
    }
};