class Solution {
public:
    int maxOperations(string s) {
        int cnt=0;
        int ans=0;
        vector<int>v;
    
        for(int i=0;i<s.length();i++)
        {
               if(s[i]=='0'&&cnt>0)
               {
                
                     v.push_back(cnt);
                     cnt=0;
               }else if(s[i]=='1'){
                cnt++;
               }
        }
        int pluse=0;
        for(int i=0;i<v.size();i++)
        {
            // cout<<v[i]<<" ";
              ans=ans+pluse;
              pluse+=v[i];
        }
        ans=ans+pluse;
        return ans;
    }
};
// 10101011101