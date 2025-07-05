class Solution {
public:
 vector<vector<int>> ans;
  void solve(vector<int>& candidates,int ind,int target,vector<int>&tem)
  {
              if(target==0)
              {
                  ans.push_back(tem);
                  return ;
              }
              if(target<0||ind>candidates.size())return ;
              //take;
              for(int i=ind;i<candidates.size();i++)
              {
                      if(target-candidates[i]>=0)
                      {
                          tem.push_back(candidates[i]);
                          solve(candidates,i,target-candidates[i],tem);
                          tem.pop_back();
                      }else{
                        
                      }
              }
     
  }
  
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>tem;
     
        solve(candidates,0,target,tem);
       
        
        return ans;
    }
};