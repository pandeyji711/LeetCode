class Solution {
public:
   int solve(vector<vector<int>>& matrix,int x,int y,   vector<vector<int>>&sc,   vector<vector<int>>&vis, queue<pair<int,int>>&pq)
   {
    
      int n=matrix.size();
      int m=matrix[0].size();
    //    if(x>n-1||y>m-1)return -1;
         
           pq.push({x,y});
           int ans=1;
            vis[x][y]=sc[x][y];
        //    vector<vector<int>>vis(n,vector<int>(m,-1));
           while(!pq.empty())
           {
            
                   int x1=pq.front().first;
                   int y1=pq.front().second;
                //    cout<<pq.top()[0]<<" "<<x1<<" "<<y1<<endl;
                 
                   pq.pop();
                     //up
                     if(x1-1>=0&&matrix[x1][y1]<matrix[x1-1][y1])
                     {
                             int pre=sc[x1-1][y1];
                             if(pre<sc[x1][y1]+1)
                             {
                                   pq.push({x1-1,y1});
                                    vis[x1-1][y1]=1;
                                   sc[x1-1][y1]=sc[x1][y1]+1;
                                   ans=max(ans, sc[x1-1][y1]);
                             }
                     }
                     //down
                       if(x1+1<=n-1&&matrix[x1][y1]<matrix[x1+1][y1])
                     {
                             int pre=sc[x1+1][y1];
                             if(pre<sc[x1][y1]+1)
                             {
                                   pq.push({x1+1,y1});
                                    vis[x1+1][y1]=1;
                                   sc[x1+1][y1]=sc[x1][y1]+1;
                                    ans=max(ans, sc[x1+1][y1]);
                             }
                     }
                     //left
                       if(y1-1>=0&&matrix[x1][y1]<matrix[x1][y1-1])
                     {
                        //  cout<<"j";
                             int pre=sc[x1][y1-1];
                             if(pre<sc[x1][y1]+1)
                             {
                                 vis[x1][y1-1]=1;
                                   pq.push({x1,y1-1});
                                   sc[x1][y1-1]=sc[x1][y1]+1;
                                    ans=max(ans, sc[x1][y1-1]);
                             }
                     }
                     //right
                       if(y1+1<=m-1&&matrix[x1][y1]<matrix[x1][y1+1])
                     {
                             int pre=sc[x1][y1+1];
                             if(pre<sc[x1][y1]+1)
                             {
                                 vis[x1][y1+1]=1;
                                   pq.push({x1,y1+1});
                                   sc[x1][y1+1]=sc[x1][y1]+1;
                                    ans=max(ans, sc[x1][y1+1]);
                             }
                     }


           }
           return ans;

   }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
 int n=matrix.size();
      int m=matrix[0].size();   
        
          int ans=1;
         
           vector<vector<int>>sc(matrix.size(),vector<int>(matrix[0].size(),1));
              vector<vector<int>>vis(n,vector<int>(m,-1));
               queue<pair<int,int>>pq;
          for(int i=0;i<matrix.size();i++)
          {
              for(int j=0;j<matrix[0].size();j++)
              {
                  
                     if(vis[i][j]==-1)
                      ans=max(ans,solve(matrix,i,j,sc,vis,pq));
              }
          }
        
        //   cout<<solve(matrix,0,0,pq,sc,vis);
          return ans;
    }
};