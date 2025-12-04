class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        // skip all leading L cars
        while (i < n && s[i] == 'L') i++;

        // skip all trailing R cars
        while (j >= 0 && s[j] == 'R') j--;

        // all remaining non-'S' cars collide
        int ans = 0;
        for (int k = i; k <= j; k++) {
            if (s[k] != 'S') ans++;
        }

        return ans;
    }
};
