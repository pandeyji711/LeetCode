/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumDifference = function(nums) {
     var n=nums.length;
       const maxx = new Array(n+1).fill(Number.MIN_SAFE_INTEGER);
       const minn = new Array(n+1).fill(Number.MAX_SAFE_INTEGER);
       for(var i=0;i<n;i++)
       {
                minn[i+1]=Math.min(minn[i],nums[i]);

       }
         for(var i=n-1;i>=0;i--)
       {
                maxx[i+1]=Math.max(maxx[i],nums[i]);
                
       }
       var ans=0;
         for(var i=0;i<n;i++)
       {
                var tem=maxx[i+1]-minn[i];
                ans=Math.max(ans,tem);

       }
       return ans===0?-1:ans;


};