class Solution {
public:
unordered_map<string,bool>fm;
 void po2()
 {
          long long n=1;
        while(n<10e+9)
        {
              string s=to_string(n);
              sort(s.begin(),s.end());
            //   cout<<s<<" ";
              fm[s]=1;
              n*=2;      
        }


 }
    bool reorderedPowerOf2(int n) {
        string str=to_string(n);
        sort(str.begin(),str.end());
      po2();
           return fm.find(str)!=fm.end();

    }
};