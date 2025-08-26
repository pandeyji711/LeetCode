class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
          
          int ans=0;
          double di=0;
          for(int i=0;i<dimensions.size();i++)
          {
                  double d=sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
                  int area=dimensions[i][0]*dimensions[i][1];
                  
                  if(di<d)
                  {
                      ans=area;
                      di=d;


                  }else if(di==d)
                  {
                     
                      ans=max(ans,area);
                  }


          }
 return ans;
    }
};