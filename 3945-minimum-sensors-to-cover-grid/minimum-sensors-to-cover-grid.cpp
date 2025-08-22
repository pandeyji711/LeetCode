class Solution {
public:
    int minSensors(int n, int m, int k) {
        if(k==0)return n*m;
        
          int d=2*k+1;
        int l1=0;
         if(n%d==0)
         {
             l1=n/d;
         }else{
               l1=n/d+1;
         }
        int l2=0;
         if(m%d==0)
         {
             l2=m/d;
         }else{
               l2=m/d+1;
         }
        return l2*l1;
        
    }
};