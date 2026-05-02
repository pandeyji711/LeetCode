class Solution {
public:
  bool isrot(int n)
  {
    int y=0;
       while(n>0)
       {
         int r=n%10;
         if(r==3||r==7||r==4)return 0;
          if(r==2||r==5||r==6||r==9)y= true;

          n=n/10;
       }
       return y|0;
  }
    int rotatedDigits(int n) {
        
       int cnt=0;
       for(int i=1;i<=n;i++)
       {
            if(isrot(i))
            {
                // cout<<i<<endl;
                cnt++;
            }
       }
   return cnt;

    }
};
