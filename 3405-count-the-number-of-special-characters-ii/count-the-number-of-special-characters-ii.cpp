class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>m;
      int   ans=0;
      vector<int>v(26,0);
        for(int i=0;i<word.size();i++)
        {
             char c=tolower(word[i]);
              if(!isupper(word[i])&&v[c-'a']==0)v[c-'a']=1;
              else if(isupper(word[i])&&v[c-'a']==1)v[c-'a']=2;
              else if(!isupper(word[i])&&v[c-'a']==2)v[c-'a']=-1;
              else if(isupper(word[i])&&v[c-'a']==0)v[c-'a']=-1;

        }
        for(auto v1:v)
        {
             if(v1==2)ans++;
        }
        return ans;
    }
};