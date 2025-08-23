class Solution {
public:
vector<vector<int>>ans;
map<vector<int>,int>m;
    void solve(vector<int>& candidates, int target,int ind,vector<int>&tem)
    {
               if(target==0)
               {
                //   if(!m.count(tem)){
                   ans.push_back(tem);
                        // m[tem]=1;
                //   }
                   return ;
               }
               if(ind>=candidates.size())return ;
               //take
               if(target-candidates[ind]>=0)
               {
                  tem.push_back(candidates[ind]);
                   solve(candidates,target-candidates[ind],ind+1,tem);
                   tem.pop_back();
               }
               int next=ind+1;
               while(next<candidates.size()&&candidates[ind]==candidates[next])
               {
                   next++;
               }
            //    if(ind<candidates.size()&&candidates[ind]!=candidates[ind+1])
               solve(candidates,target,next,tem);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>tem;
        solve(candidates,target,0,tem);
        return ans;

    }
};