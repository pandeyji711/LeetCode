class Solution {
public:

    vector<int>parent;
    int find(int node)
    {
           if(parent[node]==node)return node;
        
             return find(parent[node]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n=edges.size();
        parent.resize(n,-1);
        for(int i=0;i<n;i++)
        {
              parent[i]=i;
        }
        vector<vector<int>>ans;
        ans.push_back({});
        for(int i=0;i<edges.size();i++)
        {
                int p1=find(edges[i][0]-1);
                int p2=find(edges[i][1]-1);
                if(p1==p2)
                {
                     ans.pop_back();
                    ans.push_back({edges[i][0],edges[i][1]});
                     
                    
                }else{
                       parent[p1]=parent[p2];
                }
        }
        return ans[0];

    }
};