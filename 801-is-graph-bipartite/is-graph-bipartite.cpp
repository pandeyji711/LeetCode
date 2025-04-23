class Solution {
public:
 bool issafe(vector<vector<int>>& m,vector<int>&v,int root,int col)
 {
                       for(int a1:m[root])
                       {
                             if(col==v[a1])return false;
                       }
                       return true;
 }
// to cheak bipartite cheak weather graph is possible to color with two color 
  bool dfs( vector<vector<int>>& m,vector<int>&v,int root,int col)
  {
                 v[root]=col;
                 bool x=true;
                    for( int a1:m[root])
                    {
                          if(v[a1]==-1){
                            if(!issafe(m,v,a1,!col))return false;
                            else
                          x=  dfs(m,v,a1,!col);
                          }
                    }
                    return true&x;
  }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>v(graph.size(),-1);
        int col=1;
        bool ans=true;
        for(int i=0;i<v.size();i++)
        {
            //  cout<<v[i]<<" ";
                // if(v[i]==v[i+1])return 0;
                if(v[i]==-1)
                {
                     ans=ans&dfs(graph,v,i,col);
                }
        }
        return ans;
    }
};