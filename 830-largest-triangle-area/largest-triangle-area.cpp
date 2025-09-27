class Solution {
public:
 double disbetw(int p1x,int p1y,int p2x,int p2y,int p3x,int p3y)
 {
                  double num=fabs((p1x-p2x)*(p3y-p1y)-(p2y-p1y)*(p3x-p1x));
                  double de= fsqrt((p2x-p1x)*(p2x-p1x)-(p2y-p1y)*(p2y-p1y));
                  return num/de;
 }
    double largestTriangleArea(vector<vector<int>>& points) {
         
          double ans=0.0;
          for(int i=0;i<points.size();i++)
          {
                for(int j=i+1;j<points.size();j++)
                {
                     for(int k=j+1;k<points.size();k++)
                     {
                               double area = fabs(
                        (points[j][0] - points[i][0]) * (points[k][1] - points[i][1]) -
                        (points[j][1] - points[i][1]) * (points[k][0] - points[i][0])
                    ) / 2.0;
                    
                    ans = max(ans, area);
                              ans=max(area,ans);


                     }
                }
          }
          return ans;
    }
};