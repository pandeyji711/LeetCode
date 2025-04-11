class Solution {
public:
  bool ch(int n)
  {
        string str=to_string(n);
        int le=str.length();
        if(str.length()%2!=0)return 0;
         int num1=0;
        int num2=0;
        if(le==2){
             num1=(str[0]-'0');
             num2=(str[1]-'0');
             if(num1==num2)return 1;
             else
             return 0;

        }
        else{
               num1=(str[0]-'0')+(str[1]-'0');
                num2=(str[2]-'0')+(str[3]-'0');
                if(num1==num2)return 1;
                else
               return false;

        }
        
  }
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++)
        {
              if(ch(i)){
    
                ans++;}
        }
        return ans;
    }
};