class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
          if(encodedText.length()==0)return "";
        string str;
        int col=encodedText.length()/rows;
        vector<vector<char>>m(rows,vector<char>(col,' '));
        int ind=0;
      
        for(int i=0;i<rows;i++)
        {
             string str;
              for(int j=0;j<col;j++)
              {
                   if(ind<encodedText.size()){
                    m[i][j]=encodedText[ind];
                        ind++;
                   }
                    
                    // ind++;
              }
             
            //   cout<<str<<endl;
        }
        string ans;
        for(int i=0;i<col;i++)
        {
              for(int j=0;j<rows;j++)
              {
                   if(i+j<col)
                    ans.push_back(m[j][i+j]);
              }
               
        }
        while(ans.back()==' ')
        {
              ans.pop_back();
        }
        return ans;
    }
};