class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>v(n);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
             if(i==n)
             {
                  v[i-1]=-1*(sum);
                  break;
             }else
             {
                sum+=i;
             v[i-1]=i;
             }
        }
        return v;

    }
};