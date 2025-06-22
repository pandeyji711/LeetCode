class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int cnt=0;
        if(s.length()%k!=0)
        {
               cnt=k-s.length()%k;
        }
        int n=s.length();
        for(int i=0;i<s.length();i=i+k)
        {
                 int siz=min(k,n-i);
                 ans.push_back(s.substr(i,siz));
        }
        while(cnt)
        {
              ans[ans.size()-1].push_back(fill);
              cnt--;
        }
        return ans;

    }
};