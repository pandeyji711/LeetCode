class Solution {
public:
    bool checkStrings(string s1, string s2) {
          vector<vector<int>>v(26,vector<int>(2,0));
          vector<vector<int>>v2(26,vector<int>(2,0));
          for(int i=0;i<s1.length();i++)
          {
              if(i%2==0)
              v[s1[i]-'a'][0]++;
              else
              v[s1[i]-'a'][1]++;
          }  
           for(int i=0;i<s2.length();i++)
          {
              if(i%2==0)
              v2[s2[i]-'a'][0]++;
              else
              v2[s2[i]-'a'][1]++;
          } 
          for(int i=0;i<26;i++)
          {
                if(v[i][0]!=v2[i][0]||v[i][1]!=v2[i][1])return 0;
          }  
          return true;
    }
    
};

