class Solution {
public:
    string answerString(string word, int numFriends) {
         if(numFriends==1)return word;
        int cantake=word.length()-numFriends+1;
     string ans="";
      char ch='a';
        for(int i=0;i<word.length();i++)
        {
             if(word[i]<ch)continue;
              int ind=word.length()-i;            
                    int siz=min(cantake,ind);
                      if(word.substr(i,siz)>ans)
                      {
                        ans=word.substr(i,siz);
                      }
           
              ch=word[i];
        }
        return ans;
    }
};