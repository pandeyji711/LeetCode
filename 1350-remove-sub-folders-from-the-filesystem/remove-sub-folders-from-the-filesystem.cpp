class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // unordered_map<string,int>m;
        sort(folder.begin(),folder.end());
        int ind=0;
        vector<string>ans;
        while(ind<folder.size())
        {
            string str;
              if(ans.size()>0)
              {
                 str=ans[ans.size()-1]+"/";
              }
                    if(ans.size()==0){
                    ans.push_back(folder[ind]);
                    }
                    else if(str!=folder[ind].substr(0,str.length())){

                        ans.push_back(folder[ind]);

                    }
                 
                    ind++;
        }
        // for(int i=0;i<folder.size();i++)
        // {
        //         string str=folder[i]+"/";
        //          for(int j=i+1;j<folder.size();j++)
        //          {
        //                  if(folder[j].substr(0,str.length())==str)
        //                  {
        //                     m[folder[j]]=1;
        //                     i=j;
        //                  }

        //          }
        // }
        // vector<string>ans;
        // for(string &s:folder)
        // {
        //       if(m.find(s)==m.end())
        //       ans.push_back(s);

        // }
        return ans;
    }
};