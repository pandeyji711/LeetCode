class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        long long ans=0;
         unordered_map<int,pair<int,int>>xm;
         unordered_map<int,pair<int,int>>ym;
          int maxxx=INT_MIN;
        int maxxy=INT_MIN;
        int minnx=INT_MAX;
        int minny=INT_MAX;
          for(int i=0;i<coords.size();i++)
              {
                     int x=coords[i][0];
                    int y=coords[i][1];
                    if(xm.find(coords[i][0])==xm.end())
                    {
                         xm[coords[i][0]]={coords[i][1],coords[i][1]};
                    }else{
                          
                            int val=coords[i][1];
                            xm[coords[i][0]].first=min( xm[coords[i][0]].first,y);
                           xm[coords[i][0]].second=max( xm[coords[i][0]].second,y);
                         
                    }
                   if(ym.find(coords[i][1])==ym.end())
                    {
                         ym[coords[i][1]]={coords[i][0],coords[i][0]};
                    }else{
                            int val=coords[i][0];
                            ym[coords[i][1]].first=min( ym[coords[i][1]].first,x);
                           ym[coords[i][1]].second=max( ym[coords[i][1]].second,x);
                    }
                  maxxx=max(maxxx,coords[i][0]);
                  maxxy=max(maxxy,coords[i][1]);
                  minnx=min(minnx,coords[i][0]);
                  minny=min(minny,coords[i][1]);
                 
              }
        
          for(auto  a1:xm)
              {
                         int minn=a1.second.first;
                         int maxx=a1.second.second;
                          int diff=max(abs(a1.first-maxxx),abs(a1.first-minnx));
                          ans=max(ans,1LL*abs(minn-maxx)*diff);
                         
                    
              }
       
          for(auto  a1:ym)
              {
                     int minn=a1.second.first;
                         int maxx=a1.second.second;
                             int diff=max(abs(a1.first-maxxy),abs(a1.first-minny));
                          ans=max(ans,1LL*abs(minn-maxx)*diff);
                    
              }
        return ans==0?-1:ans;
        
             
    }
};