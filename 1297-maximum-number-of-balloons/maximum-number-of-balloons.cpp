class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m;
        m['b']=0;
        m['a']=0;
        m['l']=0;
        m['n']=0;
        m['o']=0;
        for(int i=0;i<text.length();i++)
        {
             m[text[i]]++;
        }

        int ans=INT_MAX;
        for(auto &a1:m)
        {
             if(a1.first=='b')
             {
                  ans=min(ans,a1.second);
             }else if(a1.first=='a')
             {
                 ans=min(ans,a1.second);
             }else if(a1.first=='l')
             {
                 ans=min(ans,a1.second/2);
             }else if(a1.first=='o')
             {
                 ans=min(ans,a1.second/2);
             }else if(a1.first=='n')
             {
                 ans=min(ans,a1.second);
             }
        }
        return ans==INT_MAX?0:ans;
    }
};