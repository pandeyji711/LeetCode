class Spreadsheet {
public:

//   int sheet[r][26];
vector<vector<int>>v;
 unordered_map<char,int>m;
   
    Spreadsheet(int rows) {
        for(int i=0;i<=rows;i++)
        {
              vector<int>tem(26,0);
              v.push_back(tem);
        }
        char ch='A';
        int ind=0;
        while(ch!='Z')
        {
              m[ch]=ind;
              ind++;
              ch++;
        }
        m[ch]=ind;

    }
       int digitval1(string formula,int ind)
    {
        int sum=0;
            //  int ind=1;
             while(ind<formula.length())
             {
                  sum=sum*10+(formula[ind]-'0');
                  ind++;
             }
             return sum;
    }
    void setCell(string cell, int value) {
        char ch=cell[0];
        int col=m[ch];
        int ro=digitval1(cell,1);
        v[ro][col]=value;
    }
    
    void resetCell(string cell) {
          char ch=cell[0];
        int col=m[ch];
           int ro=digitval1(cell,1);
        v[ro][col]=0;
    }
    int digitval(string formula,int &ind)
    {
        int sum=0;
            //  int ind=1;
             while(formula[ind]!='+')
             {
                  sum=sum*10+(formula[ind]-'0');
                  ind++;
             }
            //  cout<<sum<<" ";
             return sum;
    }
 
    int getValue(string formula) {
    //   cout<<"k";
    // cout<<isdigit('0');
    char ch=formula[1];
    // cout<<ch;
        if(isdigit(ch))
        {
            //   cout<<isdigit('0');
             int ind=1;
            int s1=digitval(formula,ind);
             //after '+
            //  cout<<s1;
             ind++;
             int s2=0;
             if(isdigit(formula[ind]))
             {
                  s2=digitval1(formula,ind);
                  return s1+s2;
             }
             else{
                    char ch=formula[ind];

        int col=m[ch];
        
        int ro=digitval1(formula,ind+1);
        // cout<<ro;
        // cout<<v[ro][col];
                return s1+v[ro][col];
             }

        }else
        {
             
            char ch=formula[1];
        int col=m[ch];
        int ind=2;
       int ro =digitval(formula,ind);
        // int ro=formula[2]-'0';
        //after +
        //  ind=4;
         ind++;
           if(isdigit(formula[ind]))
           {
               int s1=digitval1(formula,ind);
               return v[ro][col]+s1;
           }else{
               
                      char ch1=formula[ind];
        int col1=m[ch1];
        int ro1=digitval1(formula,ind+1);
        // cout<<ro1;
        return v[ro][col]+v[ro1][col1];

           }
         
        }


    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */