class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int,int>m;
        for(int i=0;i<friends.size();i++)
        {
               m[friends[i]]=1;
        }
        vector<int>v;
        for(int i=0;i<order.size();i++)
        {
                 if(m.count(order[i]))
                 {
                    v.push_back(order[i]);
                 }
        }
        return v;
    }
};