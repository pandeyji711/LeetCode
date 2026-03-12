class Solution {
public:
    bool checkOnesSegment(string s) {
       int act=0;
       
       for(int i=0;i<s.length();i++)
       {
            if(act==1&&s[i]=='1')return 0;
              if(s[i]!='1')
              {
                  act=1;
                  
              }
              
       }
     
       return 1;
    }
};