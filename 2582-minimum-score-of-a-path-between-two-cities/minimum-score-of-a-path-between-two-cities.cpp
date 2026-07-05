class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
      
        
        queue<pair<int,int>>q;
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<roads.size();i++)
        {
                adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
                adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});

        }
        q.push({1,INT_MAX});
        vector<int>res(n+1,INT_MAX);
        res[1]=INT_MAX;
        while(!q.empty()){
                
                int n=q.size();
                for(int i=0;i<n;i++)
                {
                     auto node=q.front();
                     q.pop();
                     for(auto a1:adj[node.first])
                     {
                          int curr=res[a1.first];
                           int now=min(node.second,a1.second);
                           if(curr>now)
                           {
                               res[a1.first]=now;
                               q.push({a1.first,now});
                           }

                     }
                     
                     
                }
        }
        return res[n];


    }
};