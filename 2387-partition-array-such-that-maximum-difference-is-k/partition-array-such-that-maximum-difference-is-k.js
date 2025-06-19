/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var partitionArray = function(nums, k) {
   nums.sort((a, b) => a - b); 
    var maxx= Number.MIN_SAFE_INTEGER;
    var minn= Number.MAX_SAFE_INTEGER;
    //   console.log(maxx);
    var n=nums.length;
    var ans=0;
    for(var i=0;i<n;i++)
    {
        //   console.log(nums[i]);
           maxx=Math.max(maxx,nums[i]);
           minn=Math.min(minn,nums[i]);
//   console.log(maxx);
           if(maxx-minn>k)
           {
                //   console.log(nums[i]);
                  ans++;
                  minn=nums[i];
                  maxx=nums[i];
           }


    }
    //  if(maxx-minn>k)
    //        {
    //               ans++;
                 
    //        }

    return ans+1;
};