class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int>postY(n+1,0);
        vector<int>preN(n+1,0);
        for(int i=0;i<customers.size();i++)
        {
              if(customers[i]=='N')
              {
                  preN[i+1]=preN[i]+1;
              }else
              preN[i+1]=preN[i];
        }
          for(int i=n-1;i>=0;i--)
           {
              if(customers[i]=='Y')
              {
                   postY[i]=postY[i+1]+1;
              }
              else
              postY[i]=postY[i+1];
          }
          int minn=INT_MAX;
          int indx=0;

          for(int i=0;i<customers.size();i++)
          {
                int x=postY[i];
                int y=preN[i];
                 cout<<x<<" "<<y<<endl;
                 int cnt=0;
                //  if(customers[i]=='Y')cnt++;
                    if(x+y+cnt<minn)
                    {
                        minn=x+y+cnt;
                        indx=i;
                    }
                    //  minn=min(minn,x+y+cnt);
          }
           int x=postY[n];
                int y=preN[n];
                 cout<<x<<" "<<y<<endl;
                 int cnt=0;
                //  if(customers[i]=='Y')cnt++;
                    if(x+y+cnt<minn)
                    {
                        minn=x+y+cnt;
                        indx=n;
                    }
          return indx;
    }
};