class Solution {
public:
    int smallestNumber(int n) {
        int add=0;
        int ind=0;
        int n1=n;
        while(n)
        {
             if(!(n&1))
             {
                 add+=pow(2,ind); 
             }
             n=n>>1;
             ind++;
        }
        return n1+add;
    }
};