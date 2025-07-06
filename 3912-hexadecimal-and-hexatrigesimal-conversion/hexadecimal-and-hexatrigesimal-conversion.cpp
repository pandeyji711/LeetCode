class Solution {
public:
   string hex(int n)
   {
         n=n*n;
         string s;
             if(n<=9)
              {
                   s.push_back(n+'0');
                   return s;
                   
              }else if(n<16) {
                       n=n-10;
                       char c='A'+n;
                       s.push_back(c);
                       return s;
              }
         while(n>1)
         {
             
               int re=n%16;
                if(re<=9)
              {
               
                   s.push_back(re+'0');
                   
              }else {
                       re=re-10;
                       char c='A'+re;
                       s.push_back(c);
              }
               n=n/16;
                if(n<=9)
              {
                   s.push_back(n+'0');
                   return s;
                   
              }else if(n<16) {
                       n=n-10;
                       char c='A'+n;
                       s.push_back(c);
                       return s;
              }


         }
         return s;
   }
    string thex(int n)
   {
         n=n*n*n;
         string s;
             if(n<=9)
              {
                   s.push_back(n+'0');
                   return s;
                   
              }else if(n<36) {
                       n=n-10;
                       char c='A'+n;
                       s.push_back(c);
                       return s;
              }
         while(n>1)
         {
             
               int re=n%36;
                if(re<=9)
              {
                 
                   s.push_back(re+'0');
                   
              }else {
                       re=re-10;
                       char c='A'+re;
                       s.push_back(c);
              }
               n=n/36;
                if(n<=9)
              {
                   s.push_back(n+'0');
                   return s;
                   
              }else if(n<36) {
                       n=n-10;
                       char c='A'+n;
                       s.push_back(c);
                       return s;
              }


         }
         return s;
   }
    string concatHex36(int n) {
         string s1;
         string s2;
          s1=hex(n);
          s2=thex(n);
          reverse(s1.begin(),s1.end());
          reverse(s2.begin(),s2.end());

          return s1+s2;
    }
};