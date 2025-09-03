class Solution {
public:
  vector<int>ans;
  int diff=INT_MAX;
  void solve(vector<int>&div,int k,int n,vector<int>&curr)
  {
          if(k==1)
          {
               curr.push_back(n);
               int minn=*min_element(curr.begin(),curr.end());
               int maxx=*max_element(curr.begin(),curr.end());
               if(maxx-minn<diff)
               {
                  diff=maxx-minn;
                  ans=curr;
               }
                if(curr.size()>0)
               curr.pop_back();
               return ;

          }
          for(int d:div)
          {  
                   if(d>n)break;
               if(n%d==0)
               {
                  curr.push_back(d);
                    solve(div,k-1,n/d,curr);
                    curr.pop_back();
               }
          }

                 
  }

    vector<int> minDifference(int n, int k) {
         vector<int>div;
         div.push_back(1);
      for(int i=2;i<=n;i++)
      {
          if(n%i==0){
          div.push_back(i);
               
          }

      }
      vector<int>curr;
    solve(div,k,n,curr);
        return ans;
    }
};