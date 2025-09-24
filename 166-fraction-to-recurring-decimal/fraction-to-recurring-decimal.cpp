class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
            if(numerator==0)return "0";

               string ans="";
            if((numerator<0)^(denominator<0))
               ans+="-";
               long long de=llabs((long long )denominator);
               long long num=llabs((long long )numerator);
           ans+=to_string(num/de);
            if(num%de==0)
            return ans;
            ans+=".";
           unordered_map<long long,int>m;
          long long  rem=num%de;
             while(rem!=0)
             {
                     if(m.count(rem))
                     {
                            ans.insert(m[rem],"(");
                            ans+=")";
                            break;
                     }
                     m[rem]=ans.size();
                     rem*=10;
                     ans+=to_string(rem/de);
                     rem%=de;
             }
             return ans;
    }
};