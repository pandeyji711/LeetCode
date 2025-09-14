class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
         int avg=0;
         set<int>set;
         for(int i=0;i<nums.size();i++)
         {
               avg+=nums[i];
               set.insert(nums[i]);
         }
         
         avg=avg/(int)nums.size();
        //  cout<<avg<<endl;
        //  sort(nums.begin(),nums.end());
          avg++;
          int s=false;
           avg=max(1,avg);
         for(auto a:set)
         {
            // cout<<nums[i]<<" ";
              if(avg==a){
                avg++;
                s=true;
              }
              else if(s&&avg!=a)break;
         }
         return avg;
    }
};