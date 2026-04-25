class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        // for(int i=0;i<queries.size();i++)
        // {
        //       sort(queries[i].begin(),queries[i].end());

        // }
        // for(int i=0;i<dictionary.size();i++)
        // {
        //       sort(dictionary[i].begin(),dictionary[i].end());
              
        // }
        vector<string>ans;
        // unordered_map<string,int>m;
        for(int i=0;i<queries.size();i++)
        {
               string str=queries[i];

                for(int j=0;j<dictionary.size();j++)
                {
                     if(dictionary[j].length()!=str.length())continue;
                     int cnt=0;
                      for(int k=0;k<min(str.length(),dictionary[j].length());k++)
                      {
                            if(str[k]!=dictionary[j][k])cnt++;
                            if(cnt>2)break;
                      }
                      if(cnt<=2){
                      ans.push_back(str);
                      break;
                    //   m[str]=1;
                      }
                }
        }
        return ans;
    }
};