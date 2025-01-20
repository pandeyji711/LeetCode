class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>m_ind;
         for(int i=0;i<mat.size();i++)
         {
                for( int j=0;j<mat[0].size();j++)
                {
                     m_ind[mat[i][j]]={i,j};
                }
         }
         unordered_map<int,int>rowm;
      unordered_map<int,int>colm;

        
         for(int i=0;i<arr.size();i++)
         {
                   int x=m_ind[arr[i]].first;
                     int y=m_ind[arr[i]].second;
                    colm[y]++;
                    rowm[x]++;
                    if(colm[y]>=mat.size()||rowm[x]>=mat[0].size())
                    return i;
         }
         return 0;

    }
};
