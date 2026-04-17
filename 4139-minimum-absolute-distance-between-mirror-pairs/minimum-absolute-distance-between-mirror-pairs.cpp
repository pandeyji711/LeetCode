class Solution {
public:
 string rev(int n)
 {
        string str="";
        int nz=0;
        while(n>0)
        {
              int r=n%10;
              if(r>0)
              nz=1;
              if(nz>0)
              str+=to_string(r);
              n=n/10;
        }
        return str;

 }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<string ,int>rm;
        unordered_map<string ,int>rm1;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            string str=to_string(nums[i]);
             if(rm.count(str))
             {
                   ans=min(ans,abs(i-rm[str]));
                    

             }
              string str1=rev(nums[i]);
                     rm[str1]=i;
        }
    
        return ans==INT_MAX?-1:ans;
    }
};
