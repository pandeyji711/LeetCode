class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>lf(height.size()+2,0);
        vector<int>ri(height.size()+2,0);
        //r l
        for(int i=0;i<height.size();i++)
        {
                 lf[i+1]=max(lf[i],height[i]);
        }
        //l r
          for(int i=height.size()-1;i>=0;i--)
        {
                 ri[i]=max(ri[i+1],height[i]);
        }
        int ans=0;
          for(int i=0;i<height.size();i++)
        {
                 int lm=lf[i];
                 int rm=ri[i+1];
                 int h=min(lm,rm);
                 int diff=max(0,h-height[i]);
                 ans+=diff;
        }
        return ans;
    }
};