class Solution {
public:
//     int solve( vector<int>&two,
//         vector<int>&one)
// {
//          int pair=0;
//          int t=0;
//          int o=0;
        
//          if(two.size()>0&&one.size()>0)
//          {
//                pair=two[two.size()-1]+one[one.size()-1];
//          }
//          if(two.size()>=3)
//          {
//              t=two[two.size()-1]+two[two.size()-2]+two[two.size()-3];
//          }
//          if(one.size()>=3)
//          {
//               o=one[one.size()-1]+one[one.size()-2]+one[one.size()-3];
//          }
//          if(pair>t&&pair>o)
//          return 1;
//           if(t>pair&&t>o)
//          return 2;
//          if(o>t&&o>pair)
//          return 3;


// }

    int maxSumDivThree(vector<int>& nums) {
        vector<int>two;
        vector<int>one;
    int cnttwo=0;
    int cntone=0;
    int zero=0;
     int sum=0;
        for(int i=0;i<nums.size();i++)
        {
                 if(nums[i]%3==0)
                 {
                      zero+=nums[i];
                 }else if(nums[i]%3==1)
                 {
                       one.push_back(nums[i]);
                 }else{
                      two.push_back(nums[i]);
                 }
                 sum+=nums[i];
        }
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        if(sum%3==0)return sum;
        if(sum%3==1)
        {
                if(two.size()<2)
                {
                        return sum-one[0];
                }
                if(one.size()==0)
                return sum-(two[0]+two[1]);
                   if(two.size()>=2&&two[0]+two[1]<one[0])
                   {
                       return sum-(two[0]+two[1]);
                   }else{
                         return sum-one[0];
                   }
        } else{
             if(one.size()<2)
                {
                        return sum-two[0];
                }
                if(two.size()==0)
                return sum-(one[0]+one[1]);
                   if(one.size()>=2&&one[0]+one[1]<two[0])
                   {
                       return sum-(one[0]+one[1]);
                   }else{
                         return sum-two[0];
                   } 
        }      
       

    }
};
 
//  {2,5}{2,8},{1,2}

