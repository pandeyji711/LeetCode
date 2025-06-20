class Solution {
public:
    int maxDistance(string s, int k) {
        int x=0;
        int y=0;
int ans=0;
           for(int i=0;i<s.length();i++)
           {
                  if(s[i]=='N')
                  y++;
                   if(s[i]=='S')
                  y--;
                   if(s[i]=='E')
                  x++;
                   if(s[i]=='W')
                  x--;
                  int ideal=i+1;
                  int acc=abs(x)+abs(y);
                //   if(i==5)
                //   cout<<acc<<endl;
                  int waste=ideal-acc;
                   int rec=min(2*k,waste);
                   ans=max(ans,acc+rec);
           }
           return ans;
    }
};