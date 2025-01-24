class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
       int n=isWater.size();
           vector<vector<int>>v(n,vector<int>(isWater[0].size(),0));
           queue<pair<int,int>>q;
        for(int i=0;i<isWater.size();i++)
            {
                 for(int j=0;j<isWater[0].size();j++)
                 {
                              
                              if(isWater[i][j]==1)
                              {
                                   q.push({i,j});
                                   isWater[i][j]=0;
                                   v[i][j]=1;
                              }
                 }
                  
            }
            while(!q.empty())
            {
                     int n1=q.size();
                     for(int i=0;i<n1;i++)
                     {
                             int x=q.front().first;
                             int y=q.front().second;
                             q.pop();
                               if(y>0&& v[x][y-1]!=1)
                             {

                                      isWater[x][y-1]=isWater[x][y]+1;
                                      v[x][y-1]=1;
                                      q.push({x,y-1});
                              }
             //right
             if(y<v[0].size()-1&&v[x][y+1]!=1)
             {
                   isWater[x][y+1]=isWater[x][y]+1;
                                      v[x][y+1]=1;
                                      q.push({x,y+1});

             }
             //up
             if(x>0&& v[x-1][y]!=1)
             {
                  isWater[x-1][y]=isWater[x][y]+1;
                                      v[x-1][y]=1;
                                      q.push({x-1,y});
             }
             //down
             if(x<v.size()-1&&v[x+1][y]!=1)
             {
                   isWater[x+1][y]=isWater[x][y]+1;
                                      v[x+1][y]=1;
                                      q.push({x+1,y});
             }



                     }
            }
            return isWater;

    }
};