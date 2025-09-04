class Solution {
public:
    int findClosest(int x, int y, int z) {
        
         int dis1=abs(z-x);
         int dis2=abs(z-y);
         if(dis1<dis2)
         return 1;
         else if(dis1>dis2)
         {
              return 2;
         }
         return 0;
    }
};