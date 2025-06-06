class Solution {
public:
  bool  check( map<char,vector<int>>&m,char &a,int i)
  {
        for(auto &a1:m)
        {
              if(a1.first<a&&a1.second[a1.second.size()-1]>i)
              {
                     return true;
              }
        }
        return false;
  }
    string robotWithString(string s) {
        map<char,vector<int>>m;
        for(int i=0;i<s.length();i++)
        {
                 m[s[i]].push_back(i);
        }
    stack<char>st;
   string ans;
    for(int i=0;i<s.length();i++)
    {
              st.push(s[i]);
              while(!st.empty()&&!check(m,st.top(),i))
              {
                   ans.push_back(st.top());
                   st.pop();
              }
              
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;

    }
};