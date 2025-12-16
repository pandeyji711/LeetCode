class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=high-low;
        
         return low%2==0?(cnt+1)/2:cnt/2+1;
    }
};
