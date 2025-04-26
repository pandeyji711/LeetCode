class Solution {
public:
    string findCommonResponse(vector<vector<string>>& r) {
           map<string, int> mp;
    for (auto& d : r) {
        set<string>s(d.begin(), d.end());
        for (auto& x : s) 
            mp[x]++;
    }

    int mx = 0;
    for (auto& [k, v] : mp)
        mx = max(mx, v);

    vector<string> v;
    for (auto& [k, v2] : mp) {
        if (v2 == mx) v.push_back(k);
    }

    sort(v.begin(), v.end());
    return v[0];
    }
};