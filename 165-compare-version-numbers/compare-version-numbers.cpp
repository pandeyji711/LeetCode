class Solution {
public:
    int compareVersion(string version1, string version2) {
      
        int tem=0;
        vector<int>v1;
        vector<int>v2;
        for(int i=0;i<version1.length();i++)
        {
                if(version1[i]=='.')
                {
                    v1.push_back(tem);
                     
                       tem=0;
                      
                }else{
                       
                      tem=tem*10+(version1[i]-'0');
                      
                }
        }
  v1.push_back(tem);
                 
        tem=0;
   
        for(int i=0;i<version2.length();i++)
        {
                if(version2[i]=='.')
                {
                      v2.push_back(tem);

                   
                       tem=0;
                      
                }else{
                       
                      tem=tem*10+(version2[i]-'0');
                     
                }
        }

         
         v2.push_back(tem);
        int l=0;
        while(l<v1.size()&&l<v2.size())
        {
                if(v1[l]>v2[l])
                {
                      return 1;
                }else if(v1[l]<v2[l])
                {
                     return -1;
                }
                l++;
        }
           while(l<v1.size())
           {
                   if(v1[l]>0)
                   return 1;
                   l++;
           }
             while(l<v2.size())
           {
                   if(v2[l]>0)
                   return -1;
                   l++;
           }
        return 0;
    }
};