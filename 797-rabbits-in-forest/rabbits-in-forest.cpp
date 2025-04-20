class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int>v(1000);
        for(int i=0;i<answers.size();i++)
        {
               v[answers[i]]++;
        }
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
                  if(v[i]>0){
                    int cover=i+1;
                    int cnt=(v[i]+i)/cover;
                  ans+=(cnt*(i+1));
                  }
        }
        return ans;
    }
};