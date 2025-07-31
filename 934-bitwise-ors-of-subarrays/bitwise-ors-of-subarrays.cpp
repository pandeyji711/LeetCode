class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
          unordered_set<int> result;
        unordered_set<int> prev;

        for (int num : arr) {
            unordered_set<int> cur;
            cur.insert(num);

            for (int x : prev) {
                cur.insert(x | num);
            }

            for (int x : cur) {
                result.insert(x);
            }

            prev = cur;
        }

        return result.size();

    }
};