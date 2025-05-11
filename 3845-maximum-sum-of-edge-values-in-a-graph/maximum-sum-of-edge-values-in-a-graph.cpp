class Solution {
public:
       bool dfs( unordered_map<int ,vector<int>>&adj,int par,int root,vector<int>&vis,int &cnt)
       {
                       vis[root]=1;
                       cnt++;
                         for(int nab:adj[root])
                         {
                                 if(vis[nab]!=1)
                                 {
                                      if(dfs(adj,root,nab,vis,cnt))
                                      {
                                           return true;
                                      }
                                 }else if(par!=nab)
                                 return true;
                         }
                         return false;
       }
         long long scr(queue<int>&q,int siz,int cy)
         {
                    if(siz==1)
                    {
                        long long  x=q.front();
                        q.pop();
                        return 0;
                    }
                    if(siz==2)
                    {
                          long long x1=q.front();
                          q.pop();
                          long long x2=q.front();
                          q.pop();
                           long long x=1LL*x1*x2;
                           return x;
                    }
                     vector<long long >cost(siz,0);
                    int mid=(siz-1)/2;
                    int r=mid+1;
                    int l=mid-1;
                    cost[mid]=q.front();
                    q.pop();
                    int n=siz-1;
                    while(l>=0&&r<siz)
                    {
                          int ri=q.front();
                          q.pop();
                          int lf=q.front();
                          q.pop();
                          cost[r]=ri;
                          cost[l]=lf;
                          r++;
                          l--;
                          
                          n-=2;
                        //   cout<<r<<" "<<l<<" "<<n<<endl;
                    }
                    if(r<siz){
                    cost[r]=q.front();
                    q.pop();
         }else if(l>=0)
         {
             cost[l]=q.front();
                    q.pop();

         }
                    long long ans=0;
                    for(int i=0;i<siz-1;i++)
                    {
                        ans+=1LL*(cost[i+1]*cost[i]);
                    }
                    if(cy==1)
                    ans+=1LL*(cost[0]*cost[siz-1]);
                    return ans;


         }
    long long maxScore(int n, vector<vector<int>>& edges) {
        unordered_map<int ,vector<int>>adj;
        for(int i=0;i<edges.size();i++)
        {
                     adj[edges[i][0]].push_back(edges[i][1]);
                     adj[edges[i][1]].push_back(edges[i][0]);


        }
        
        vector<int>vis(n,0);
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<vis.size();i++)
        {
                    if(vis[i]==0)
                    {
                          int cnt=0;
                          bool cyc=dfs(adj,-1,i,vis,cnt);
                           if(cyc)
                           {
                               pq.push({1,cnt});
                           }else
                           pq.push({0,cnt});
                    }
        }
        queue<int>q;
        for(int i=n;i>=1;i--)
        {
            q.push(i);
        }
        long long ans=0;
        while(!pq.empty())
        {
                  int cnt=pq.top().second;
                  int cyc=pq.top().first;
                //   cout<<cnt<<" "<<cyc<<endl;
                  pq.pop();
                  long long x=scr(q,cnt,cyc) ;
                  ans+=x;
                //   cout<<ans<<" ";
        }
        return ans;



    }
};