class Solution {
public:

   bool safe(vector<string>&board,int r,int j,int n)
  {
                 //right
                 for(int i=0;i<n;i++ )
                 {
                       if(board[r][i]=='Q')return false;
                 }
           //up
           for(int i=r;i>=0;i--)
           {
                if(board[i][j]=='Q')return false;
           }


                 //top left
                
                  int r1=r;
                  int i1=j;
                  while(r1>=0&&i1>=0)
                  {
                         if(board[r1][i1]=='Q')return false;
                         r1--;
                         i1--;
                  }
                  //top right
                  int r2=r;
                  int i2=j;
                  while(r2>=0&&i2<n)
                  {
                         if(board[r2][i2]=='Q')return false;
                         r2--;
                         i2++;
                  }
                  return true;


  }
  void Nqueen(vector<string>&board,int r,vector<vector<string>>&ans,int n)
  {
           if(r==n){
                ans.push_back(board);
                return ;
           }
           for(int i=0;i<n;i++)
           {
                   if(safe(board,r,i,n))
                   {
                        board[r][i]='Q';
                        Nqueen(board,r+1,ans,n);
                         board[r][i]='.';
                   }
           }
  }
    int totalNQueens(int n) {
           vector<vector<string>>ans;
        vector<string>bord(n,string(n,'.'));
        // for(int i=0;i<)
        Nqueen(bord,0,ans,n);
        return ans.size();
    }
};