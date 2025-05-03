class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int val1=tops[0];
        int val2=bottoms[0];
        for(int i=1;i<tops.size();i++)
        {
               int t=tops[i];
               int b=bottoms[i];
               if(val1!=t&&val1!=b)
               val1=INT_MAX;
               if(val2!=t&&val2!=b)
               val2=INT_MAX;
               if(val1==INT_MAX&&val2==INT_MAX)return -1;

        }
        int cntval1t=0;
        int cntval2t=0;
        for(int i=0;i<tops.size();i++)
        {
                  if(tops[i]==val1)
                  cntval1t++;
                  if(tops[i]==val2)
                  cntval2t++;
        }
          int cntval1b=0;
        int cntval2b=0;
        for(int i=0;i<bottoms.size();i++)
        {
                  if(bottoms[i]==val1)
                  cntval1b++;
                  if(bottoms[i]==val2)
                  cntval2b++;
        }
    //case1
    if(val1==INT_MAX||val2==INT_MAX)
    {
             int diff1=tops.size()-max(cntval1t,cntval2t);
                   int diff2=bottoms.size()-max(cntval1b,cntval2b);
                   return min(diff1,diff2);
    }
    //case 2
   else if(val1==val2)
    {
                int diff1=tops.size()-cntval1t;
                   int diff2=bottoms.size()-cntval1b;
                   return min(diff1,diff2);
    }
    else{
                int diff1=min(cntval1t,cntval2t);
                   int diff2=min(cntval1b,cntval2b);
                   return min(diff1,diff2);
    }

    }
};