class Solution {
public:
     void left(vector<vector<int>>& mat,int ind)
     {
                reverse(mat[ind].begin(),mat[ind].begin()+1);
                reverse(mat[ind].begin()+1,mat[ind].end());
                reverse(mat[ind].begin(),mat[ind].end());

     }
         void right(vector<vector<int>>& mat,int ind)
     {
         reverse(mat[ind].begin(),mat[ind].end());
                reverse(mat[ind].begin(),mat[ind].begin()+1);
                reverse(mat[ind].begin()+1,mat[ind].end());
                

     }
    bool areSimilar(vector<vector<int>>& mat, int k) {
       vector<vector<int>>v=mat;
       int n=mat[0].size();
       k=k%n;
       while(k--){
       for(int i=0;i<mat.size();i++)
       {
             if(i%2==0)
             {
                left(mat,i);
             }else{
                 right(mat,i);
             }
       }



       }
       return mat==v;

    }
};