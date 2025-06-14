class Solution {
public:
    int minMaxDifference(int num) {
        int maxx=0;
    
        string str=to_string(num);
        char c='*';
        maxx=0;
        for(int i=0;i<str.length();i++)
        {
               if(str[i]=='9'&&c=='*')
               {
                      maxx=maxx*10+(str[i]-'0');
               }else if(str[i]!='9'&&c=='*')
               {
                        c=str[i];
                         maxx=maxx*10+9;
               }
                  else if(str[i]==c)
                  {
                      maxx=maxx*10+9;
                  }else{
                       maxx=maxx*10+(str[i]-'0');
                  }
        }
        int minn=0;
        // cout<<
         char d=str[0];
   
        for(int i=1;i<str.length();i++)
        {
                  if(str[i]==d)
                  {
                      minn=minn*10+0;
                  }else{
                       minn=minn*10+(str[i]-'0');
                  }
        }
        return maxx-minn;
    }
};