class Solution {
public:
//  vector<string>base;
 //build base
 unordered_map<string,vector<char>>m;
  unordered_map<int,vector<string>>m2;
   unordered_set<string> bad;
  int flage=0;
  bool base(string &bottom, int ind, string str)
  {
         
           
              if(ind>=bottom.length()-1)
              {
                 
                    //    m2[size].push_back(str);
                        //  base(str,str.length()-1,0,"");
                         return dfs(str);
                
              }
             string temstr;
          temstr.push_back(bottom[ind]);
           temstr.push_back(bottom[ind+1]);
              if(m.count(temstr))
              {
                  
                    for(char &c:m[temstr])
                    {
                           str.push_back(c);
                       if(base(bottom,ind+1,str))return true;
                           str.pop_back();
                    }
              }
              return 0;
           
  }
   bool dfs(string &bottom)
   {
           if (bottom.size() == 1) return true;
        if (bad.count(bottom)) return false;

        string next = "";
        if (base(bottom, 0, next)) return true;

        bad.insert(bottom);   // mark only AFTER all possibilities fail
        return false;
   }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(int i=0;i<allowed.size();i++)
        {
             string str=allowed[i].substr(0,2);
                m[str].push_back(allowed[i][2]);
        }
        //  int siz=bottom.length();
        //   m2[siz].push_back(bottom);
        //  base(bottom,siz-1,0,"");
          return dfs(bottom);
    }
};