class Solution {
public:
  void solve( int n,vector<int>&v1,int node, unordered_map<int,vector<int>>&adj)
  { 
    queue<int>q;
     q.push(node);
     v1[node]=0;
     int time=1;
     
    //  vector<int>vis(n,-1)
     while(!q.empty())
     {
            int n1=q.size();
            for(int i=0;i<n1;i++)
            {
                  int nod=q.front();
                  q.pop();
                  for(int x:adj[nod]){
                  if(v1[x]==-1){
                  v1[x]=time;
                  q.push(x);
                  }
                  }
                   
            }
            time++;

     }
             
  }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
       int n=edges.size();
      unordered_map<int,vector<int>>adj;
       for(int i=0;i<n;i++)
       {

            if(edges[i]!=-1)
              adj[i].push_back(edges[i]);
       }
        vector<int>v1(n,-1);
       vector<int>v2(n,-1);
         solve(n,v1,node1,adj);
         solve(n,v2,node2,adj);
        int ans=INT_MAX;
        int ind=-1;
        for(int i=0;i<n;i++)
        {
              if(v1[i]!=-1&&v2[i]!=-1)
              {
                    if(ans>max(v1[i],v2[i]))
                    {
                         ind=i;
                         ans=max(v1[i],v2[i]);
                    }
              }
        }
         return ind;

    }
};