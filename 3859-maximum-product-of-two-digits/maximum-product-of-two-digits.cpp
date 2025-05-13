class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
         while(n)
         {
              int r=n%10;
              v.push_back(r);
              n=n/10;
         }
         int ans=INT_MIN;
         sort(v.begin(),v.end());
          return v[v.size()-1]*v[v.size()-2];

    }
};