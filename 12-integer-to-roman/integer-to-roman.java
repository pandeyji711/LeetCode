class Solution {
    public String intToRoman(int num) {
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] symbols = {
            "M", "CM", "D", "CD", "C", "XC", "L",
            "XL", "X", "IX", "V", "IV", "I"
        };

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < values.length; i++) {
            if (num / values[i] > 0) {
                for (int j = 0; j < num / values[i]; j++) {
                    sb.append(symbols[i]);
                }
                num = num % values[i];
            }
        }

        return sb.toString();
    }
}