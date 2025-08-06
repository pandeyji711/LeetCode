class Solution {
public:
vector<string>ans;
  void solve(  unordered_map<string,vector<string>>&adj,string root, string &tem, int &cnt)
  {
           tem.push_back(root[0]);
          
           for(auto a:adj[root])
           {
                  solve(adj,a,tem,cnt);
           }
            if(tem.length()==cnt)
           ans.push_back(tem);
        //    ans.push_back(tem);
           tem.pop_back();
              
  }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        unordered_map<string,vector<string>>adj;
    
        if(digits.length()==0)
        return {};
        int cnt=0;
        for(int i=0;i<digits.length()-1;i++)
        {
            //  cout<<i<<" "<<digits.length()-1;
               char ch1=digits[i];
               char ch2=digits[i+1];
               for(auto a1:m[ch1])
               {
                     for(auto a2:m[ch2])
                     {
                           adj[a1+to_string(cnt)].push_back(a2+to_string(cnt+1));
                     }
                    
               }
                cnt++;
        }
        // cout<<(bool)(adj.find('d')==adj.end());
        string tem;
        int cnt1=digits.length();
        for(auto a1:m[digits[0]])
        {
              string s;
              s.push_back(a1);
             solve(adj,s+"0",tem,cnt1);
        }
    return ans;

    }
};