class Solution {
public:
    string decodeString(string s) {
         stack<char>st;
        for(int i=0;i<s.length();i++)
        {
              if(!st.empty()&&s[i]==']')
              {
                   string str;
                //   cout<<st.size()<<" ";
                    while(!st.empty()&&st.top()!='[')
                    {
                          str.push_back(st.top());
                          st.pop();
                    }
                    reverse(str.begin(),str.end());
                    if(!st.empty())
                    st.pop();
                    string num;
                    // cout<<str<<" ";
                //   cout<<isdigit(st.top())&&!st.empty();
                     while(!st.empty()&&isdigit(st.top()))
                    {
                          num.push_back(st.top());
                          st.pop();
                    }
                      reverse(num.begin(),num.end());
                    int num1=stoi(num);
                    while(num1--)
                    {
                          for(char &c:str)
                          {
                               st.push(c);
                          }
                    }
                    
              }
              else
              st.push(s[i]);
        }
        string ans;
        // cout<<st.size()<<" ";
          while(!st.empty())
                    {
                        ans.push_back(st.top());
                        st.pop();
                        // cout<<
                    }
                    reverse(ans.begin(),ans.end());
                    return ans;
    }
};