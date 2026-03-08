class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string t = s + s;

        int ans = INT_MAX;
        int ans1 = 0, ans2 = 0;

        for(int i = 0; i < t.length(); i++) {

            char p1 = (i % 2) ? '1' : '0'; // pattern 010101...
            char p2 = (i % 2) ? '0' : '1'; // pattern 101010...

            if(t[i] != p1) ans1++;
            if(t[i] != p2) ans2++;

            // shrink window
            if(i >= n) {
                char old1 = ((i-n) % 2) ? '1' : '0';
                char old2 = ((i-n) % 2) ? '0' : '1';

                if(t[i-n] != old1) ans1--;
                if(t[i-n] != old2) ans2--;
            }

            // valid rotation window
            if(i >= n-1) {
                ans = min(ans, min(ans1, ans2));
            }
        }

        return ans;
    }
};