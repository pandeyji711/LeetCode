class Solution {
public:
 bool po2(int n)
 {
         if(n<=0)return true;
         while(n>1)
         {
              if(n%2!=0)return false;
              n=n/2;
         }
         return true;
 }
    bool reorderedPowerOf2(int n) {
        string str=to_string(n);
        sort(str.begin(),str.end());
        do{
            if(str[0]=='0')continue;
               int n1=stoi(str);
               if(po2(n1))return true;
        } while(next_permutation(str.begin(),str.end()));

           return false;

    }
};