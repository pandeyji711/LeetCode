class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        vector<int>vis(64,0);
        priority_queue<int>q;
        while(num2)
        {
               if(num2&1)
               cnt++;
               num2=num2>>1;
        }
         int ind=0;
         while(num1)
         {
               if(num1&1)
               {
                   int x=pow(2,ind);
                   vis[ind]=1;
                   q.push(x);
               }
               num1=num1>>1;
               ind++;
         }
         
         int ans=0;
         while(cnt&&!q.empty())
         {
            //   cout<<q.top();
                 ans+=q.top();
                 q.pop();
                 cnt--;
         }
         ind=0;
        //  cout<<cnt;
         while(cnt>0&&ind<=32)
         {
               if(vis[ind]==0)
               {
                    ans+=pow(2,ind);
                    cnt--;
               }
               ind++;
         }
          return ans;
    }
};