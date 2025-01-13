class Solution {
public:
    int minimumLength(string s) {
        int ans=0;
        vector<int>v(26,0);
   for(int i=0;i<s.length();i++)
   {
            v[s[i]-'a']++;
   }

        for(int i=0;i<v.size();i++)
        {
                int num=v[i]-1;
                 num=num/2;

                ans+=num;
        }
        return s.length()-ans*2;
    }
};
