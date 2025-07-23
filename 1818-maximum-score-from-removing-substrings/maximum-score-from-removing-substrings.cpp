class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string str;
         string more;
         string less;
         int vmore=y;
         int vless=x;
         if(x>y){
         more="ab";
         vmore=x;
          vless=y;
         less="ba";
         }
         else{
         more="ba";
           less="ab";
         }
         int ans=0;
        for(int i=0;i<s.length();i++)
        {
                 if(str.length()>0)
                 {
                       string tem;
                       tem.push_back(str[str.length()-1]);
                       tem.push_back(s[i]);
                       if(tem==more){
                       str.pop_back();
                           ans+=vmore;
                       }
                       else
                        str.push_back(s[i]);
                 }else
                 str.push_back(s[i]);
        }
        string s1;
          for(int i=0;i<str.length();i++)
        {
                 if(s1.length()>0)
                 {
                       string tem;
                       tem.push_back(s1[s1.length()-1]);
                       tem.push_back(str[i]);
                       if(tem==less){
                       s1.pop_back();
                           ans+=vless;
                       }
                       else
                        s1.push_back(str[i]);
                 }else
                 s1.push_back(str[i]);
        }
        return ans;
    }
};