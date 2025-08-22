class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
         
          vector<int>h(grid.size(),0);
           vector<int>l(grid[0].size(),0);

          //top to bottom 

          for(int i=0;i<grid.size();i++)
          {
                 for(int j=0;j<grid[i].size();j++)
                 {
                      
                       h[i]=(h[i]|grid[i][j]);
                       l[j]=(l[j]|grid[i][j]);
                 }
          }
          int leh=0;
          int veh=0;
          int f=-1;
          int sc=-1;
          for(int i=0;i<h.size();i++)
          {
            //   cout<<h[i]<<" ";
                 if(h[i]==1)
                 {
                      if(f==-1)
                       f=i;
                      sc=i;
                 }
          }
          leh=sc-f+1;
        //   cout<<sc<< " "<<f<<endl;
          f=-1;
          sc=0;
        //   cout<<leh<<" ";
           for(int i=0;i<l.size();i++)
          {
            //  cout<<l[i]<<" ";
                 if(l[i]==1)
                 {
                      if(f==-1)
                       f=i;
                      sc=i;
                 }
          }
          veh=sc-f+1;
          return veh*leh;

    }
};