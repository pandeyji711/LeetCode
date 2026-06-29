class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(int i=0;i<patterns.size();i++)
        {
              string str=patterns[i];
              if(str.length()>word.length())continue;
              for(int j=0;j<word.length()-str.length()+1;j++)
              {
                // cout<<j<<endl;
                   if(str==word.substr(j,str.length()))
                   {
                       ans++;
                       break;
                   }
                      
              }
        }
        return ans;
    }
};