class Solution {
public:

  bool solve( unordered_map<int,vector<int>>&adj,int root,vector<int>&vis,int &cnt,int &last,vector<int>&pos,vector<int>&vis1,int &time)
  {
      
            if(vis1[root]!=-1&&vis1[root]<time)
            return 0;
             if(vis[root]==1){
                
                return 1;
                }
             if(vis[root]==2)return 0;
             vis1[root]=time;
             vis[root]=1;
             last=root;
             pos[root]=cnt;
             cnt++;
             
            //  cout<<root<<" ";
             for(int a1:adj[root])
             {
                    if(solve(adj,a1,vis,cnt,last,pos,vis1,time)){
                     
                     return 1;
                    }


             }
             vis[root]=2;
              return 0;
  }
    int longestCycle(vector<int>& edges) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++)
        {
                  if(edges[i]!=-1){
                   adj[i].push_back(edges[i]);
                  }
        }
        vector<int>vis(edges.size(),0);
 int ans=-1;
vector<int>pos(edges.size(),0);
     vector<int>vis1(edges.size(),-1);
     int time=0;
               for(int i=0;i<edges.size();i++)
               {
                   if(vis[i]==0){
                  
                  time++;
                        int cnt=0;
                        int last=-1;
                          if(solve(adj,i,vis,cnt,last,pos,vis1,time)){
                            int y=cnt-pos[adj[last][0]];
                            ans=max(y,ans);
                          }

                   }
                      
               }
               return ans;
    }
};