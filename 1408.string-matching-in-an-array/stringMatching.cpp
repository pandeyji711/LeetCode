class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
       vector<string>ans;
        for(int i=0;i<words.size();i++)
        {       
            string str=words[i];
            int l=str.length();
            //  if(m.find())
               for(int j=0;j<words.size();j++)
               {
                    int ha=0;
                            if(j==i||words[j].length()<l)
                            continue;
                            for( int k=0;k<words[j].length()-l+1;k++)
                            {
                                     if(words[j].substr(k,l)==str)
                                     {
                                                  
                                                  ans.push_back(str);
                                                  ha=1;
                                                  break;
                                     }
                            }
                            if(ha==1)
                            break;
               }
        }
        return ans;
    }
};