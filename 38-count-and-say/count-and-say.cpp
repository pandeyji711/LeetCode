class Solution {
public:
  string solve(string str , int n)
  {
         if(n==1)
         return str;
         string tem="";
         char dub=str[0];
         int cnt=1;
        
         for(int i=1;i<str.length();i++)
         {
               if(dub!=str[i])
               {
                   tem+=to_string(cnt)+str[i-1];
                   dub=str[i];
                   cnt=1;
               }else{
                   cnt++;
               }
         }
          tem+=to_string(cnt)+str[str.length()-1];
        return  solve(tem,n-1);

  }
    string countAndSay(int n) {
        string str="1";
        return solve(str,n);
    }
};