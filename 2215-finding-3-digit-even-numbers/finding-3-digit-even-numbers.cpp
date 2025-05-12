class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // vector<int>ev;
        // for(int a1:digits)
        // {

        // }
     map<int,int>m;
     for(int i=0;i<digits.size();i++)
     {
           if(digits[i]==0)continue;
                for(int j=0;j<digits.size();j++)
                {
                        if(i==j)continue;
                        for(int k=0;k<digits.size();k++)
                        {
                                if(i==k||j==k)
                                continue;
                                if(digits[k]%2==0)
                                {
                                      int x=digits[i]*100+digits[j]*10+digits[k];
                                      
                                      m[x]++;
                                 }
                        }
                }
     }
     vector<int>ans;
     for(auto a1:m)
     {
            ans.push_back(a1.first);
     }
     return ans;
    }
};