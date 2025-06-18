class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        string str;
        // str+="/";
        for(int i=0;i<path.length();i++)
        {
                 if(path[i]=='/'&&str=="")
                 {
                    continue;
                 }
                 else if(path[i]=='/'&&str!="")
                 {
                    //  cout<<str<<" "<<i<<endl;
                           if(str=="..")
                         {
                            if(st.size()>0)
                          st.pop_back();
                          str="";
                          continue;
                       }else if(str=="."){
                        str="";
                        continue;
                       }
                        else{
                            str+="/";
                              st.push_back(str);
                               str="";
                              continue;
                             
                        }
                 }
        
           
                str.push_back(path[i]);

        }
          if(str=="..")
                         {
                             if(st.size()>0)
                          st.pop_back();
                         
                          
                       }
                       else if(str=="."){
                
                       }
                        else{
                          
                              st.push_back(str);
                               
                             
                        }
          string ans;
          ans+="/";
         for(int i=0;i<st.size();i++)
         {
              ans+=st[i];
         }
         int r=ans.length()-1;
         if(r>0&&ans[r]=='/')
         {
            // cout<<"k";
            ans.pop_back();
         
         }
        //   reverse(ans.begin(),ans.end());
          return ans;

    }
};