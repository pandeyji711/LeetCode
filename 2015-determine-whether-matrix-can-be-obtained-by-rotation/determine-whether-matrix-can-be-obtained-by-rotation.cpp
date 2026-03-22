class Solution {
public:
//   bool 
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
            if(mat[0].size()!=target.size()||mat.size()!=target[0].size())return false;
             vector<vector<int>>matt(mat.size(),vector<int>(mat[0].size(),0));
             matt=mat;
             int cnt=4;
            while(cnt>0){
                mat=matt;
                bool ok=true;
             for(int i=0;i<mat.size();i++)
             {
                  for(int j=0;j<target[0].size();j++)
                  {

                      cout<<mat[i][j]<<" "<<target[j][target[0].size()-1-i]<<endl;
                       if(mat[i][j]!=target[j][target[0].size()-1-i])
                       {
                         
                        ok= false;
                           
                       }
                       matt[j][target[0].size()-1-i]=mat[i][j];
                  }
             }
             if(ok)return true;
cnt--;
            }
             return false;
    }
};