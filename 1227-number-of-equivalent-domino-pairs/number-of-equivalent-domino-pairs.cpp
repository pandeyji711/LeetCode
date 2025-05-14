class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans=0;
        map<pair<int,int>,int>m;
        for(int i=0;i<dominoes.size();i++)
        {
                sort(dominoes[i].begin(),dominoes[i].end());
                m[{dominoes[i][0],dominoes[i][1]}]++;
        }
        for(auto a1:m)
        {
             if(a1.second>1)
             {
                  int x=a1.second;
                  int tem=x*(x-1)/2;
                  ans+=tem;
             }
        }
        return ans;
    }
};