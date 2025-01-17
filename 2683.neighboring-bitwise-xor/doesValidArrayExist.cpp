class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        if(derived.size()==1)
        {
                  return !derived[0];     
          }
          int n=derived.size();
        vector<int>v1(n);

        vector<int>v2(n);
        if(derived[0]==1)
        {
              v1[0]=1;
              v1[1]=0;
              v2[0]=0;
              v2[1]=1;
        }else
        {
            v1[0]=1;
              v1[1]=1;
              v2[0]=0;
              v2[1]=0;
        }
        for(int i=1;i<derived.size();i++)
        {
                   if(i==derived.size()-1)
                   {
                         if(v1[i]^v1[0]!=derived[i])
                         return false;
                   }
                   else
                   {
                          if(derived[i]==1)
                          v1[i+1]=!v1[i];
                          else
                          v1[i+1]=v1[i];
                   }
        }
        for(int i=1;i<derived.size();i++)
        {
                   if(i==derived.size()-1)
                   {
                         if(v2[i]^v2[0]!=derived[i])
                         return false;
                   }
                   else
                   {
                          if(derived[i]==1)
                          v2[i+1]=!v2[i];
                          else
                          v2[i+1]=v2[i];
                   }
        }
        return true;
    }
};