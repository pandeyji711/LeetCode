class Solution {
public:
   void dfs(unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&vis,int root,int &mid)
   {
                      vis[root]=1;
                      for(auto &node:adj[root])
                      {
                             if(node.second>mid||vis[node.first]==1)continue;
                             dfs(adj,vis,node.first,mid);

       
       
                      }
   }

    bool solve(int n,vector<vector<int>>&edges, int &k,int &mid,unordered_map<int,vector<pair<int,int>>>&adj){
               
         int k1=0;
         vector<int>vis(n,0);
         for(int i=0;i<n;i++)
         {
                if(vis[i]==0)
                {
                     k1++;
                     dfs(adj,vis,i,mid);
                }
         }
        return k1<=k;

    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
    //    sort(edges.begin(),edges.end());
       unordered_map<int,vector<pair<int,int>>>adj;
       for(int i=0;i<edges.size();i++)
       {
                adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
                adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
       }
       int l=0;
      int r=1000000;
      int ans=0;
    //   cout<<solve(n,edges,k,82);
       while(l<=r)
       {
           int mid=l+(r-l)/2;
           if(solve(n,edges,k,mid,adj))
           {
               ans=mid;
               r=mid-1;
           }else
           l=mid+1;
       }
        return ans;



    }
};