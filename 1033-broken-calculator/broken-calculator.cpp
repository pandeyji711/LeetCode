class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        if(startValue>target)
        return startValue-target;
           while(startValue!=target)
           {
                 if(target>startValue&&target%2==0)
                 target=target/2;
                 else if(target>startValue&&target%2!=0)
                 {
                    target++;
                 }
                 else if(target<startValue)
                 {
                      target++;
                 }
                 ans++;
           }
           return ans;
         
    }
};
// 100 to 8
// 100 50 25 26 13 14 7 8