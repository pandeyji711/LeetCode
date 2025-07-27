/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumMedianSum = function(nums) {
    let cnt= nums.length/3;
    nums.sort((a,b)=>b-a);
    // nums.reverse();

let ind=1;
 let ans=0;
    while(cnt--)
    {
          ans+=nums[ind];
          ind+=2; 
    }
    return ans;
};