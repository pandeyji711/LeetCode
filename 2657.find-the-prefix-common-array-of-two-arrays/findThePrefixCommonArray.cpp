class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       int n=A.size();
        vector<int>ans(n);
        vector<int>vis(51,0);
       
        for(int i=0;i<n;i++)
        {
                  int cnt=0;
                   for(int j=i;j>=0;j--)
                   {
                         vis[A[j]]++;
                   }
                   for(int j=i;j>=0;j--)
                   {
                         if(vis[B[j]])
                         cnt++;
                   }
                   ans[i]=cnt;
        }
        return ans;
    }
};