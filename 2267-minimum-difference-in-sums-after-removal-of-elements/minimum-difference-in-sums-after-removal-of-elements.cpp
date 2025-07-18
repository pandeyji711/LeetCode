class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        
              int n=nums.size()/3;
              //leftsum
              priority_queue<int>leftq;
              vector<long long>leftpre(3*n,LLONG_MAX);
              long long leftsum=0;
              for(int i=0;i<3*n;i++)
              {
                    leftsum+=nums[i];
                      leftq.push(nums[i]);
                      if(leftq.size()>n)
                      {
                           leftsum-=leftq.top();
                           leftq.pop();
                      } if(leftq.size()==n)
                       {
                            leftpre[i]=leftsum;
                       }
              }
                 //rightsum
              priority_queue<int,vector<int>,greater<int>>rightq;
              vector<long long>rightpre(3*n,LLONG_MIN);
              long long rightsum=0;
              for(int i=3*n-1;i>=n;i--)
              {
                    rightsum+=nums[i];
                      rightq.push(nums[i]);
                      if(rightq.size()>n)
                      {
                           rightsum-=rightq.top();
                           rightq.pop();
                      }if(rightq.size()==n)
                       {
                            rightpre[i]=rightsum;
                       }

              }
  long long  ans=LLONG_MAX;
              for(int i=n-1;i<2*n;i++)
              {
                    if((leftpre[i]!=LLONG_MAX)&&(rightpre[i+1]!=LLONG_MIN))
                     ans=min(ans,(long long)(leftpre[i]-rightpre[i+1]));
              }
              return ans;
    }
};