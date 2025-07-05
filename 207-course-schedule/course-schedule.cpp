class Solution {
public:
 

   bool cyc(  unordered_map<int,vector<int>>&adj,int root,vector<int>&vis)
   {
               if(vis[root]==1)return true;
                
                vis[root]=1;
                bool a=false;
                for(int node:adj[root])
                {
                       if(vis[node]==0)
                       {
                          a=a||cyc(adj,node,vis);
                       }else if(vis[node]==1)
                       return true;
                }
                vis[root]=2;
                return a;
   }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)return true;
        vector<int>dig(numCourses,0);

        unordered_map<int,vector<int>>adj;
           vector<int>orvis(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
                    dig[prerequisites[i][0]]++;
                    adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
       
     vector<int>vis(numCourses,0);
     bool ans=true;
        for(int i=0;i<numCourses;i++)
        {
            // cout<<dig[i]<<" ";
             
               ans=ans&&!cyc(adj,i,vis);
              

        }
       
        return ans;
    }
};