class Solution {
public:
    bool scoreBalance(string s) {
        vector<int>presum(s.length()+1,0);
        for(int i=0;i<s.length();i++)
        {
             presum[i+1]=presum[i]+(s[i]-'a'+1);
        }
        for(int i=1;i<s.length();i++)
        {
            //  cout<<presum[i]<<" "<<presum[presum.size()-1]<<" "<<presum[i]<<endl;
              if(presum[i]==presum[presum.size()-1]-presum[i])
              {
                  return true;
              }
        }
        return false;

    }
};