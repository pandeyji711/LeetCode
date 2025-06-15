class Solution {
public:
    string generateTag(string caption) {
        stringstream ss(caption);
        string tem;
        vector<string>v;
        int cnt=0;
        while(ss>>tem)
        {
               
               if(cnt==0)
               {
                   for(int i=0;i<tem.length();i++)
                   {
                        tem[i]=tolower(tem[i]);
                   }
                    v.push_back(tem);
               }
               else
               {
                    tem[0]=toupper(tem[0]);

                    for(int i=1;i<tem.length();i++)
                   {
                        tem[i]=tolower(tem[i]);
                   }
                    v.push_back(tem);
               }
               cnt++;
        }
        string str;
        str+="#";
        for(int i=0;i<v.size();i++)
        {
                   str+=v[i];
        }
        string ans;
 int n=str.length();
        for(int i=0;i<min(100,n);i++)
        {
              ans.push_back(str[i]);
        }
        return ans;
    }
};