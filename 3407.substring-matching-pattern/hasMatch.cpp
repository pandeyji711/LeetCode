class Solution {
public:
    bool hasMatch(string s, string p) {
       string str1;
        string str2;
        for( int i=0;i<p.length();i++)
            {
                  if(p[i]=='*')
                  {
                      break;
                  }
                      str1+=p[i];
                  
            }
          for( int i=p.length()-1;i>=0;i--)
            {
                  if(p[i]=='*')
                  {
                    break;
                  }
                      str2+=p[i];
                  
                
            }
        int n1=str1.length();
        int n2=str2.length();
        reverse(str2.begin(),str2.end());
        cout<<str1<<" "<<str2;
        for(int i=0;i<s.length();i++)
            {
                  for( int j=i;j<s.length();j++)
                      {
                           if(s.substr(j,n1)==str1)
                           {
                                 if(str2.length()==0)
                                     return true;
                                 for(int k=j+n1;k<s.length();k++)
                                     {
                                           if(s.substr(k,n2)==str2)
                                            return   true;
                                     }
                           }
                      }
            }
        return false;
    }
};