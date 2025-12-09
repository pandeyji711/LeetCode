class Solution {
public:
 bool isprime(int n)
 {
      if(n<2)return 0;
      if(n==2)return 1;
      if(n%2==0)return 0;
      for(int i=3;i*i<=n;i=i+2)
      {

           if(n%i==0)return 0;
      }
      return 1;
 }
    bool completePrime(int num) {
        string str=to_string(num);
        // cout<<str<<" ";
        if(!isprime(num))
        {
               return 0;
        }
        for(int i=0;i<str.length()-1;i++)
        {
             string str1=str.substr(0,i+1);
             
              string str2=str.substr(i+1,str.length()-(i+1));
            //   cout<<str1<<" "<<str2<<endl;
              int num1=stoi(str1);
              int num2=stoi(str2);
            //   cout<<num1<<" "<<num2<<endl;
              if(!(isprime(num1)&&isprime(num2)))
              {
                  return 0;
              }
            //   cout<<num1<<" "<<num2<<endl;
        }
        return 1;
    }
};