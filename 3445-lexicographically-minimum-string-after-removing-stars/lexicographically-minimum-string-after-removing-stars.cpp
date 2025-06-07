class Solution {
public:
    // void solve( map<char,vector<int>>&m, unordered_map<int,int>&vm)
    // {
    //         for(auto &a1:m)
    //         {
    //             //   cout<<a1.second[a1.second.size()-1]<<endl;
    //                  vm[a1.second[a1.second.size()-1]]++;
    //                  a1.second.pop_back();
    //                  if(a1.second.size()<=0)
    //                  m.erase(a1.first);
    //                  return;
    //         }
    // }
    string clearStars(string s) {
        map<char,vector<int>>m;
        unordered_map<int,int>vm;
        for(int i=0;i<s.length();i++)
        {
               if(s[i]!='*')
               m[s[i]].push_back(i);
               else{
                      for(auto &a1:m)
                          {
                //   cout<<a1.second[a1.second.size()-1]<<endl;
                     vm[a1.second[a1.second.size()-1]]++;
                     a1.second.pop_back();
                     if(a1.second.size()<=0)
                     m.erase(a1.first);
                   break;
                          }
               }
        }
        string ans;
        for(int i=0;i<s.length();i++)
        {
               if(s[i]=='*'||vm.find(i)!=vm.end())
               {
                    continue;
               }
               ans.push_back(s[i]);
        }

        return ans;
    }
};