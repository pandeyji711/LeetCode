class Solution {
public:
  int fsum(int n)
  {
    int sum=0;
    while(n)
    {
           sum+=n%10;
           n=n/10;
    }
 return sum;
       
  }
  int ans=0;
//     bool com(const pair<int,int>&a,const pair<int,int>&b)
//    {
//                  if(a.first>b.first){
//                     ans++;
//                     return 1;
//                     };
//                  if(a.first==b.first)
//                  {
//                       if(a.second<b.second)
//                       {
//                         ans++;
//                         return 1;
//                       }
//                  } 
//                  return 0;
//    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>>vp;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
               int x=fsum(nums[i]);
               m[nums[i]]=i;
               vp.push_back({x,nums[i]});
        }
        vector<pair<int,int>>vp1;
        vp1=vp;
    //   int ans = 0;

    sort(vp.begin(), vp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first < b.first) {
            
            return true;
        }
        if (a.first == b.first && a.second < b.second) {
          
            return true;
        }
        return false;
    });
     int ans = 0;
     for(int i=0;i<vp.size();i++)
     {
          cout<<vp[i].second<<" ";
               if(vp[i].second!=nums[i])
               {
                     ans++;
                     int frind=i;
                     int toind=m[vp[i].second];
                     m[nums[frind]]=toind;
                     m[nums[toind]]=frind;
                    //    cout<<frind<<" "<<toind<<endl;
                     swap(nums[frind],nums[toind]);
               }
     }
        return ans;

    }
};