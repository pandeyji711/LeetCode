class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)
        return {{1}};
        if(numRows==2)
          return {{1},{1,1}};

          vector<vector<int>>ans;
          ans.push_back({1});
          ans.push_back({1,1});
         int rem=numRows-2;
         while(rem--)
         {
               vector<int>t;
               t.push_back(1);
               for(int i=0;i<ans[ans.size()-1].size()-1;i++)
               {
                        t.push_back(ans[ans.size()-1][i]+ans[ans.size()-1][i+1]);
               }
               t.push_back(1);
               ans.push_back(t);
         }
         return ans;
    }
};