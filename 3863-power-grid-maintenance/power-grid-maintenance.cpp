class Solution {
public:
  void bfs(  unordered_map<int,vector<int>>&adj, unordered_map<int,int>&cm,  unordered_map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>>&mpq,int &com,vector<int>&vis,int root)
  {
           queue<int>q;
           q.push(root);
    vis[root]=1;
    cm[root]=com;
     mpq[com].push({0,root});
           while(!q.empty())
           {
                 int n=q.size();
                 for(int i=0;i<n;i++)
                 {
                      int r=q.front();
                      q.pop();
                       for(int node:adj[r])
                       {
                               if(vis[node]==0)
                               {
                                    vis[node]=1;
                                    q.push(node);
                                    cm[node]=com;
                                    mpq[com].push({0,node});

                               }
                       }
                 }

           }

  }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
          unordered_map<int,int>cm;
          unordered_map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>>mpq;
        vector<int>ov(c+2,0);
          unordered_map<int,vector<int>>adj;
          for(int i=0;i<connections.size();i++)
          {
                  adj[connections[i][0]].push_back(connections[i][1]);
                  adj[connections[i][1]].push_back(connections[i][0]);

          }
          vector<int>vis(c+2,0);
          int com=1;
          for(int i=1;i<=c;i++)
          {
                   if(vis[i]==0)
                   {
                       bfs(adj,cm,mpq,com,vis,i);
                       com++;
                    //    cout<<i<<" ";
                   }
          }
vector<int>ans;
//    cout<<mpq[1].size();
//   cout<<ov[2]<<endl;
   for(int i=0;i<queries.size();i++)
   {
                  if(queries[i][0]==1)
                  {

                       if(ov[queries[i][1]]==0)
                       {
                            ans.push_back(queries[i][1]);
                       }else{

                                while(!mpq[cm[queries[i][1]]].empty()&&(mpq[cm[queries[i][1]]].top().first!=ov[mpq[cm[queries[i][1]]].top().second]||mpq[cm[queries[i][1]]].top().first==1)){
                                    // cout<<mpq[cm[queries[i][1]]].top().first<<" "<<ov[queries[i][1]]<<endl;
                                   mpq[cm[queries[i][1]]].pop();


                                }
                               
                                //  cout<<mpq[cm[queries[i][1]]].size()<<" "<<i<<endl;
                               if(!mpq[cm[queries[i][1]]].empty()&&mpq[cm[queries[i][1]]].top().first==0)
                               {
                                  ans.push_back(mpq[cm[queries[i][1]]].top().second);
                               }else{
                                  ans.push_back(-1);
                               }
                       }
                  }else{


                           ov[queries[i][1]]=1;
                            // mpq[cm[queries[i][1]]].push({});

                  }

   }
   return ans;

    }
};