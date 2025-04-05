class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>put(26,0);
        vector<int>fre(26,0);
        for(int i=0;i<s.length();i++)
        {
                fre[s[i]-'a']++;
        }
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
                if(st.empty())
                {
                     
                     st.push(s[i]);
                     put[s[i]-'a']=1;
                }
                else{
                       if(put[s[i]-'a']==1)
                       {
                           fre[s[i]-'a']--;
                           continue;
                       }
                        while(!st.empty()&&(st.top()-'a')>=(s[i]-'a')&&fre[st.top()-'a']>1)
                        {
                                    
                                        fre[st.top()-'a']--;
                                         put[st.top()-'a']=0;
                                        st.pop();
                        }
                         if( put[s[i]-'a']==0){
                        st.push(s[i]);
                        put[s[i]-'a']=1;
                         }

                }
        }
        string ans;
        while(!st.empty())
        {
              ans+=st.top();
              st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};