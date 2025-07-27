/**
 * @param {number[]} nums
 * @return {number}
 */
var countHillValley = function(nums) {
    let ans=0;
          for(let i=1;i<nums.length-1;i++)
          {
                //non equal 
                  let v=false;
                  let h=false;
                //   if()
                if(i>1&&nums[i]==nums[i-1])
                     continue;
                     for(let j=i-1;j>=0;j--)
                     {
                         if(nums[j]>nums[i])
                         {
                              v=true;
                              break;
                         }else if(nums[j]<nums[i])
                         {
                               h=true;
                               break;
                         }
                     }
                      for(let j=i+1;j<nums.length;j++)
                     {
                         if(nums[j]>nums[i])
                         {
                              if(v)
                              {
                                  ans++;
                                  break;
                              }
                              else{
                                  
                                   break;
                                 
                                  }
                                
                         }else if(nums[j]<nums[i])
                         {
                                if(h)
                              {
                                  ans++;
                                  break;
                              }
                              else{
                                  
                                   break;
                                 
                                  }
                         }
                     }
                    //  console.log(ans+" "+i);
          }
          return ans;
};