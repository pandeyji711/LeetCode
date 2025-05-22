class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {
        

           unordered_map<int,int>m;// teleportation store karne ke liye
           int n=board.size();
           int l=0;
           int last=n*n;
           bool right=true;
           //zig -zag traversal
           for(int i=n-1;i>=0;i--)
           {

                    
                    if(right)
                    {
                            for(int j=0;j<n;j++)
                            {
                                 l++;
                                     if(board[i][j]!=-1)
                                     {
                                           m[l]=board[i][j];
                                     }
                            }
                            right=!right;
                    }else{
                       //right se left
                         for(int j=n-1;j>=0;j--)
                            {
                                 l++;
                                     if(board[i][j]!=-1)
                                     {
                                           m[l]=board[i][j];
                                     }
                            }
                            right=!right;
                            
                    }
           }
             queue<int>q;
            //  cout<<m[7]<<endl;
             vector<int>vis(last+1,0);
             q.push(1);
             vis[1]=1;
             int ans=0;
             bool yes=false;
             //bfs 
             while(!q.empty())
             {
                    int n1=q.size();
                    for(int i=0;i<n1;i++)
                    {
                           int node=q.front();
                           q.pop();
                             int ran=6;
                             int cnt=1;
                             while(ran--)
                             {
                                  int dis=0;
                                
                                    if(m.find(node+cnt)!=m.end())
                                   {
                                        //    cout<<node+cnt<<  " ";
                                       if(m[node+cnt]>=last){
                                        //   cout<<node+cnt<<  " ";
                                        yes=true;
                                         break;
                                         }
                                      dis=m[node+cnt];
                                     
                                       if(vis[dis]==0){
                                        
                                       q.push(dis);
                                         vis[dis]=1;
                                       }
                                   }
                                else{
                                   dis=node+cnt;
                                   if(vis[dis]==0)
                                   {
                                        vis[dis]=1;
                                        // cout<<dis<<" ";
                                        q.push(dis);
                                   }
                                   }
                                    if(node+cnt>=last){
                                    yes=true;
                                    break;
                                    }
                                   cnt++;
                             }
                    
                    }
                    
                    ans++;
                    if(yes)return ans;
                    }
             
           return  -1;
    }
};
