class Solution {
public:
    int distinctPoints(string s, int k) {
        map<pair<int,int>,int>mp;
        int n=s.length();
        vector<int>vx(n+1,0);
        vector<int>vy(n+1,0);
        for(int i=0;i<n;i++)
        {
               if(s[i]=='L')
               {
                     vx[i+1]=vx[i]-1;
                     vy[i+1]=vy[i];
               }
                 else if(s[i]=='U')
               {
                     vx[i+1]=vx[i];
                     vy[i+1]=vy[i]+1;
               }
                else  if(s[i]=='R')
               {
                     vx[i+1]=vx[i]+1;
                     vy[i+1]=vy[i];
               }
                else  if(s[i]=='D')
               {
                     vx[i+1]=vx[i];
                     vy[i+1]=vy[i]-1;
               }
        }
       
        int l=0;
        int r=k;
        while(r<=n)
        {
               int leftsumx=vx[l];
               int rightsumx=vx[r];
               int x=vx[n]-(vx[r]-vx[l]);
            //    cout<<vx[n]-x<<" ";
                int leftsumy=vy[l];
               int rightsumy=vy[r];
               int y=vy[n]-(vy[r]-vy[l]);
            //    cout<<vy[n]-y<<endl;
               mp[{x,y}]++;
            r++;
            l++;
        }
        return mp.size();
    }
};