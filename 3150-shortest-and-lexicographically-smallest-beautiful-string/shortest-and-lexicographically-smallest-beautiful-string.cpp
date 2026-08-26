class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        set<string>st;
        int sm=INT_MAX;
        int l=0;
        int r=0;
        int cnt=0;
        while(r<s.length()){
                if(s[r]=='1')cnt++;
              while(cnt>=k)
              {
                    if(r-l+1<sm)
                    {
                         st.clear();
                        //  cout<<s.substr(l,r-l+1)<<endl;
                         st.insert(s.substr(l,r-l+1));
                         sm=r-l+1;
                    }else if(r-l+1==sm)
                    {
                      st.insert(s.substr(l,r-l+1)); 
                    //    cout<<s.substr(l,r-l+1)<<endl; 
                         sm=r-l+1;  
                    }
                    if(s[l]=='1')
                    cnt--;
                    l++;

              }
              r++;
        }
        return st.empty()?"":*st.begin();
    }
};