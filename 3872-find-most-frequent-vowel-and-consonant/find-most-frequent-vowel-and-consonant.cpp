class Solution {
public:
     bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxFreqSum(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }

        int vav = 0;
        int cons = 0;

        for (auto a1 : m) {
            if (isVowel(a1.first)) {
                vav = max(vav, a1.second);
            } else {
                cons = max(cons, a1.second);
            }
        }

        return vav + cons;
    
    }
};