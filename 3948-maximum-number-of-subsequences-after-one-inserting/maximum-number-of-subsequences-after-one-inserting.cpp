class Solution {
public:
   long long numOfSubsequences(string s) {
    int n = s.length();

    vector<int> leftprec(n + 1, 0);   // prefix count of 'C'
    vector<int> rightprec(n + 1, 0);  // suffix count of 'C'

    vector<int> leftprel(n + 1, 0);   // prefix count of 'L'
    vector<int> rightprel(n + 1, 0);  // suffix count of 'L'

    vector<int> leftpret(n + 1, 0);   // prefix count of 'T'
    vector<int> rightpret(n + 1, 0);  // suffix count of 'T'

    // Build prefix counts
    for (int i = 0; i < n; i++) {
        leftprel[i + 1] = leftprel[i] + (s[i] == 'L' ? 1 : 0);
        leftprec[i + 1] = leftprec[i] + (s[i] == 'C' ? 1 : 0);
        leftpret[i + 1] = leftpret[i] + (s[i] == 'T' ? 1 : 0);
    }

    // Build suffix counts
    for (int i = n - 1; i >= 0; i--) {
        rightprel[i] = rightprel[i + 1] + (s[i] == 'L' ? 1 : 0);
        rightprec[i] = rightprec[i + 1] + (s[i] == 'C' ? 1 : 0);
        rightpret[i] = rightpret[i + 1] + (s[i] == 'T' ? 1 : 0);
    }

    long long ans = 0;
    long long maxxin = 0;   // For inserting 'C'
    long long maxxint = 0;  // For inserting 'T'
    long long maxxinl = 0;  // For inserting 'L'

    for (int i = 0; i < n; i++) {
        if (s[i] == 'C') {
            int left = leftprel[i];       // 'L's before this 'C'
            int right = rightpret[i];     // 'T's after this 'C'
            ans += 1LL * left * right;

            // Insert 'L' before this 'C'  contributes right 'T's
            maxxinl += right;

            // Insert 'T' after this 'C'  contributes left 'L's
            maxxint += left;
        }

        // Insert 'C' at position i: left 'L's × right 'T's
        int leftl = leftprel[i];
        int rightt = rightpret[i];
        maxxin = max(maxxin, 1LL * leftl * rightt);
    }


    return ans + max({maxxin, maxxinl, maxxint});
}

};