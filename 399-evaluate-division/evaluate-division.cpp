class Solution {
public:
  struct data{
        string str;
        double val;
  };
 double  bfs( unordered_map<string,vector<data>>&adj,string root,string des)
    {
           unordered_map<string,int>vis;
             double ans=0.0;
            queue<data>q;
            data tem;
            tem.str=root;
            tem.val=1;
             q.push(tem);
            vis[root]=1;
            while(!q.empty())
            {
                  int n=q.size();
                  for(int i=0;i<n;i++)
                  {
                         data x=q.front();
                         q.pop();

                         for(auto nab:adj[x.str])
                         {
                                  if(vis.find(nab.str)==vis.end())
                                  {
                                           double y=x.val*nab.val;
                                           cout<<y<<endl;
                                           data d;
                                           d.str=nab.str;
                                           d.val=y;
                                           q.push(d);
                                           vis[nab.str]=1;
                                  }
                                  if(nab.str==des)
                                  return x.val*nab.val;
                         }
                  }
            }
            return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<data>>adj;
        for(int i=0;i<equations.size();i++)
        {
               data tem1;
               tem1.str=equations[i][1];
               tem1.val=values[i];
                   adj[equations[i][0]].push_back(tem1);
                     data tem2;
               tem2.str=equations[i][0];
               tem2.val=double(1.0/values[i]);
                   adj[equations[i][1]].push_back(tem2);

        }
        vector<double>ans;
        for(int i=0;i<queries.size();i++)
        {
               ans.push_back(bfs(adj,queries[i][0],queries[i][1]));
        }
        // cout<<bfs(adj,"a","e");
        return ans;
    }
};

