class Solution {
public:
   bool ch(string &s)
   {
     int k=s.length();
         for(int i=0;i<k-1;i++)
              {
                   if(s[i]!=s[i+1])return false;
              }
              return true;
   }
    bool hasSpecialSubstring(string s, int k) {
        if(s.length()==k)
        {
              for(int i=0;i<k-1;i++)
              {
                   if(s[i]!=s[i+1])return false;
              }
              return true;
        }
        for(int i=0;i<s.length()-k+1;i++)
        {
                    
                  string str=s.substr(i,k);
                  if(i==0)
                  {
                       if(str[str.length()-1]!=s[k+i]&&ch(str))return true;
                  }
                  else if(i>0&&i+k<s.length())
                  {
                              if(str[str.length()-1]!=s[k+i]&&ch(str)&&s[i-1]!=str[0])return true;
                  }
                  else if(i+k==s.length())
                  {
                              if(ch(str)&&s[i-1]!=str[0])return true;
                  }


        }
        return false;

    }
};