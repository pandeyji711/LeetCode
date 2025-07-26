/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
         let ans= [];
          arr.forEach((e,i)=>{
            //   const tem=fn(e,i);/
                   ans.push(fn(e,i));
                      
          });
          return ans;
};