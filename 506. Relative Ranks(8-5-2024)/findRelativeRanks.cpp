class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>du;
        du=score;
        sort(score.begin(),score.end(),greater<int>());
        unordered_map<int,string>m;
        m[score[0]]="Gold Medal";
        if(score.size()>1)
         m[score[1]]="Silver Medal";
         if(score.size()>2)
         m[score[2]]="Bronze Medal";
        for(int i=3;i<score.size();i++)
        {  
            string str=to_string(i+1);
            m[score[i]]=str;
        }
        vector<string>ans;
        for(int i=0;i<du.size();i++)
        {
            ans.push_back(m[du[i]]);
        }
        return ans;
    }
};