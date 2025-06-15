class Solution {
public:
    int maxDiff(int num) {
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
        int minn=1;
        // cout<<
         char d=str[0];
         int re=1;
         if(d=='1')
         {
              d='*';
              re=0;
         }
         
   
        for(int i=1;i<str.length();i++)
        {
               if(d=='*'&&str[i]=='1'||d=='*'&&str[i]=='0')
               {
                       minn=minn*10+(str[i]-'0');
               }else if(d=='*'&&str[i]!='1')
               {

                    d=str[i];
                    if(re==1)
                    {
                         minn=minn*10+1;
                    }else
                    {
                         minn=minn*10+0;
                    }

               }
                else if(str[i]==d&&re==1)
                  {
                      minn=minn*10+1;
                  }
                    else if(str[i]==d&&re==0)
                  {
                      minn=minn*10+0;
                  }
                  
                  else{
                       minn=minn*10+(str[i]-'0');
                  }
        }
        cout<<9909057-1101007;
        return maxx-minn;
    }
};