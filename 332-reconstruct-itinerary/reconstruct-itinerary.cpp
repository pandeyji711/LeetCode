class Solution {
public:
 unordered_map<string,vector<string>>adj;
  vector<string>ans;
     void dfs(string &node)
     {
              auto &vec=adj[node];
               while(vec.size()>0)
               {
                      string tem=vec.back();
                      vec.pop_back();
                      dfs(tem);

               }
               ans.push_back(node);

     }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       
        for(int i=0;i<tickets.size();i++)
        {
                adj[tickets[i][0]].push_back(tickets[i][1]);
                sort(adj[tickets[i][0]].rbegin(),adj[tickets[i][0]].rend());


        }
        // queue<string>q;
        // q.push("JFK");
        // vector<string>ans;
        // ans.push_back("JFK");
        //  while(!q.empty())
        //  {
                
        //              string node=q.front();
        //              q.pop();
        //              if(adj[node].size()>0){
        //                 ans.push_back(adj[node].back());
        //              q.push(adj[node].back());
        //              adj[node].pop_back();
        //              }

        //  }
        string start="JFK";
        dfs(start);
        reverse(ans.begin(),ans.end());
         return ans;
    }
};