import java.util.*;

public class Solution {
    public String removeDuplicateLetters(String s) {
        int[] put = new int[26];
        int[] fre = new int[26];

        for (int i = 0; i < s.length(); i++) {
            fre[s.charAt(i) - 'a']++;
        }

        Stack<Character> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            fre[ch - 'a']--;

            if (put[ch - 'a'] == 1) {
                continue;
            }

            while (!st.isEmpty() && st.peek() > ch && fre[st.peek() - 'a'] > 0) {
                put[st.peek() - 'a'] = 0;
                st.pop();
            }

            st.push(ch);
            put[ch - 'a'] = 1;
        }

        // Build result from stack
        StringBuilder ans = new StringBuilder();
        for (char c : st) {
            ans.append(c);
        }

        return ans.toString();
    }
}
