class Solution {
public:
  bool isvoval(char c)
  {
           return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
  }
    int vowelConsonantScore(string s) {
        int cntc=0;
        int cntv=0;
        for(char c:s)
        {
              if(isdigit(c))continue;
              if(c==' ')continue;
              if(!isvoval(c))
              {
                  cntc++;
              }else{
                   cntv++;
              }
        }
        if(cntc>0)
        {
              return floor(cntv/cntc);
        }else{
             return 0;
        }

    }
};