class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
          int empty=numBottles;
          int ans=numBottles;
          int fill=0;
          while(empty>=numExchange)
          {
                   ans++;
                   empty++;
                   empty-=numExchange;
                   numExchange++;
          }
          return ans;
    }
};
// 10

