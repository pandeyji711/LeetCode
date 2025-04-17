class Solution {
public:
 
 //bottom to top diagonal
 void diBtoT(vector<vector<char>>&v,int &ind,int n,int &x,int &y,string &s)
 {
    if(ind>=s.length())
        return;
       x--;

       y++;
    //    cout<<x<<" "<<y<<endl;
       int tem=n-2;
    //    cout<<tem<<" ";
       while((tem>0)&&ind<s.length())
       {
            
               v[x][y]=s[ind];
               ind++;
               x--;
               y++;
               tem--;
       }
        
            // x--;
            //    y++;
            //    cout<<x<<" "<<y<<endl;
       
 }
 void TtoB(vector<vector<char>>&v,int &ind,int n,int &x,int &y,string &s)
 {
    //  cout<<x<<" "<<y<<endl;
     
        if(ind>=s.length())
                   return;
           for(int i=0;i<n;i++)
           {
                   v[i][y]=s[ind];
                   ind++;
                   if(ind>=s.length())
                   break;

           }
           x=n-1;
 }

    string convert(string s, int numRows) {
        string ans;
        // int dis=2*numRows-3;
        vector<vector<char>>v(numRows,vector<char>(s.length(),'1'));

      int ind=0;
      bool tob=true;
  int x=0;
  int y=0;
      while(ind<s.length())
      {
            if(tob)
            {
                //   cout<<x<<" "<<y<<endl;
                TtoB(v,ind,numRows,x,y,s);
                if(ind>=s.length())break;
                tob=false;
            }else{
                //  cout<<x<<" "<<y<<endl;
                diBtoT(v,ind,numRows,x,y,s);
                   if(ind>=s.length())break;
                tob=true;
            }
      }
    //  TtoB(v,ind,numRows,x,y,s);
      for(int i=0;i<v.size();i++)
      {
          for(int j=0;j<v[i].size();j++)
          {
             if(v[i][j]=='1')continue;
            //   if(v[i][j])
            // cout<<v[i][j]<<" ";
              ans.push_back(v[i][j]);
          }
        //   cout<<endl;
      }
      return ans;

    }
};