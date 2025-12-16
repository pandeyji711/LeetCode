class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=high-low;
        int ans=0;
         if(low%2==0)
         {
              int numodd=(cnt+1)/2;
              ans+=numodd;
         }else{
                 int numodd=cnt/2;
              ans+=numodd+1;
         }
         return ans;
    }
};
