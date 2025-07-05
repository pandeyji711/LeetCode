class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int ans=0;
        while(l<r)
        {
              int h=min(height[l],height[r]);
             ans=max(ans,(int)h*(r-l));
              if(height[l]<height[r])
              {
                    l++;
              }else if(height[l]>height[r])
              r--;
              else{
                    l++;
                    r--;
              }

        }
        return ans;
    }
};