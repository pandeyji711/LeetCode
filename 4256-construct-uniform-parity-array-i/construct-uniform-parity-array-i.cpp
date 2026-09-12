class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int arr[2];
      arr[0]=0;
      arr[1]=0;
      for(int i=0;i<nums1.size();i++)
      {
         if(nums1[i]%2==0)arr[0]++;
         else
         arr[1]++;
      }
      int yes=true;
      //even
      for(int i=0;i<nums1.size();i++)
      {
            if(nums1[i]%2==0||arr[0]>1||arr[1]>2)continue;
            else{
                     cout<<arr[0]<<" "<<arr[1];
                 yes=false;
                 break;
            }
      }
      //odd
      if(yes)return 1;
      yes=true;
       for(int i=0;i<nums1.size();i++)
      {
            if(nums1[i]%2!=0||(arr[0]>0&&arr[1]>0))continue;
            else{
                
                 yes=false;
                 break;
            }
      }
      return yes;

    }
};
// 4-2=2
// 4-3=1
// 7-5=2