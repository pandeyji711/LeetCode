class Solution {
public:
  bool pal(string &str,int l,int r)
  {
       while(l<r)
       {
           if(str[l]!=str[r])return 0;
           l++;
           r--;
       }
       return 1;
  }
  vector<vector<string>>ans;
    void solve(string &s,vector<string>&vtem,int l,int r)
    {
           if(r==s.length())
           {
                // r--;
                // if(pal(s,l,r)){
                //   vtem.push_back(s.substr(l,r-l+1)); 
                  ans.push_back(vtem);
                // }
                  return;
           }
          else if(r>=s.length())
           return;

         for(int i=r;i<s.length();i++)
         {
               if(pal(s,l,i)){
               vtem.push_back(s.substr(l,i-l+1));
            //    cout<<<<endl;
               solve(s,vtem,i+1,i+1);
               vtem.pop_back();
               }
               
         }

    }
    vector<vector<string>> partition(string s) {
           vector<string>vtem;
           solve(s,vtem,0,0);
        //    cout<<pal(s,0,1);
           return ans;
    }
};