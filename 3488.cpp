class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            vector<int>ans(queries.size(),-1);
            unordered_map<int,vector<int>>adj;
            for(int i=0;i<nums.size();i++)
            {
                  adj[nums[i]].push_back(i);
            }
            for(int i=0;i<queries.size();i++)
            {
                   int qind=queries[i];
                   int qnum=nums[queries[i]];
                         if(adj[qnum].size()<2){
                            continue;
                         }
                           auto it=lower_bound(adj[qnum].begin(),adj[qnum].end(),queries[i]);
                           int ind=it-adj[qnum].begin();
                           if(ind==0)
                           {
                                int lastind=nums.size()-1;
                                int clock=adj[qnum][ind+1]-adj[qnum][ind];
                                int anti=lastind-adj[qnum][adj[qnum].size()-1]+1+adj[qnum][ind];
                                ans[i]=min(clock,anti);
                           }
                           else if(ind==adj[qnum].size()-1)
                           {
                              int lastind=nums.size()-1;
                                        int anti=adj[qnum][ind]-adj[qnum][ind-1];
                                        int clock=adj[qnum][0]+lastind-adj[qnum][ind]+1;
                                        ans[i]=min(clock,anti);
    
                           }
                           else{
                                     int left=adj[qnum][ind]-adj[qnum][ind-1];
                                     int right=adj[qnum][ind+1]-adj[qnum][ind];
                                     ans[i]=min(left,right);
    
                           }
            }
            return ans;
             
        }
    };