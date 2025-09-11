class Solution {
public:
 bool isvoval(char str)
 {
        char str1=tolower(str);
          if(str1=='a'||str1=='e'||str1=='i'||str1=='o'||str1=='u')
          return 1;
          return 0;
 }
    string sortVowels(string s) {
        vector<char>v;
        for(int i=0;i<s.length();i++)
        {
             if(isvoval(s[i]))
             {
                //  cout<<s[i]<<" ";
                  v.push_back(s[i]);
             }
        }
    sort(v.begin(),v.end());
    int ind=0;
        for(int i=0;i<s.length();i++)
        {
                   if(isvoval(s[i]))
                   {
                       s[i]=v[ind++];
                   }
        }
        return s;
        
    }
};