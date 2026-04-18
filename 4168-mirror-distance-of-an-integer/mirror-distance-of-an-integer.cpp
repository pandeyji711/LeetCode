class Solution {
public:
    int mirrorDistance(int n) {
        int mirr=0;
        int n1=n;
        while(n1>0)
        {
            int r=n1%10;
            mirr=mirr*10+r;
            n1=n1/10;

        }
        return abs(n-mirr);
    }
};