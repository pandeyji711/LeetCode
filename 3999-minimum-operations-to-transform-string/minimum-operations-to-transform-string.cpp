class Solution {
public:
    int minOperations(string s) {
        vector<int>v(26,0);

        for(int i=0;i<s.length();i++)
        {
              v[s[i]-'a']++;
        }
        int ans=0;
        int pre=-1;
        for(int i=1;i<v.size();i++)
        {
             if(v[i]>0)
             {
                 if(pre==-1)
                 {
                     pre=i;
                     continue;
                 }

                  ans+=(i-pre);
                  pre=i;
             }
        }
        if(pre==25)
        return ans+1;
        if(pre>-1&&pre<25)
        {
              return ans+(26-pre);
        }
        return ans;
    }
};