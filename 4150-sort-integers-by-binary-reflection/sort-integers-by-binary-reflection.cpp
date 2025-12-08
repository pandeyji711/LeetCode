class Solution {
public:
  int solve(int n)
  {
        string str;
        while(n)
        {
               if(n&1)
               {
                  str.push_back('1');
               }else{
                str.push_back('0');
               }
               n=n>>1;
        }
        reverse(str.begin(),str.end());
        int num=0;
        for(int i=0;i<str.length();i++)
        {
            //   cout<<str[i]<<" ";
               num+=pow(2,i)*(str[i]-'0');
        }
        // cout<<endl;
        return num;

  }
    vector<int> sortByReflection(vector<int>& nums) {
          vector<pair<int,int>>v;

             for(int i=0;i<nums.size();i++)
             {
                       int sum=solve(nums[i]);
                    //    cout<<sum<<" ";
                       v.push_back({sum,nums[i]});
             }
             sort(v.begin(),v.end());
             vector<int>ans;
             for(int i=0;i<v.size();i++)
             {
                   ans.push_back(v[i].second);
             }
             return ans;
    }
};