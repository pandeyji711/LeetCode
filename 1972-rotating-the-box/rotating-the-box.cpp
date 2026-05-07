class Solution {
public:
 void fall(vector<vector<char>>& boxGrid,int x,int y)
 {
        
           for(int i=y;i<boxGrid[0].size()-1;i++)
           {
                 if(i+1<boxGrid[0].size())
                 {
                      if(boxGrid[x][i+1]=='.')
                      {
                           boxGrid[x][i+1]='#';
                           boxGrid[x][i]='.';
                      }else{
                          break;
                      }

                 }
           }
 }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        for(int i=0;i<boxGrid.size();i++)
        {
                 for(int j=boxGrid[0].size()-1;j>=0;j--)
                 {
                        if(boxGrid[i][j]=='#'){
                        fall(boxGrid,i,j);
                        //   cout<<
                        }
                 }

        }
        vector<vector<char>>ans;
        for(int j=0;j<boxGrid[0].size();j++)
        {
            vector<char>v;
               for(int i=boxGrid.size()-1;i>=0;i--)
               {
                   v.push_back(boxGrid[i][j]);
               }
               ans.push_back(v);
        }
        return ans;
    }
};