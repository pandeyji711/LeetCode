class Solution {
public:
    string pushDominoes(string dominoes1) {
        //right
        int n=dominoes1.length();
       vector<int>v(n,INT_MAX);
       int num=1;
       char last='*';
       string dominoes=dominoes1;
        for(int i=0;i<dominoes.size();i++)
        {
                   if(dominoes[i]=='R')
                   {
                    num=1;
                    v[i]=num;
                   }else if(dominoes[i]=='.')
                   {
                    if(last=='R'){
                    dominoes[i]='R';
                 
                    v[i]=num;
                       num++;
                    }
                       
                   }
                   if(dominoes[i]=='L'){
                   last='L';
                   num=0;
                   }
                   else if(dominoes[i]=='R')
                   last='R';

        }
        //right
         num=1;
         last='*';
          for(int i=n-1;i>=0;i--)
        {
                  if(dominoes1[i]=='L')
                   {
                    num=1;
                    v[i]=num;
                   }else if(dominoes1[i]=='.')
                   {
                    //   cout<<v[i]<<" "<<num<<endl;
                      if(last=='L'){
                      if(v[i]>num){
                      dominoes[i]='L';
                      }
                      else if(v[i]==num)
                    dominoes[i]='.'; 
                      num++;
                      }

                   }
                   if(dominoes1[i]=='L')
                   last='L';
                   else if(dominoes1[i]=='R'){
                   last='R';
                   num=0;
                   }

        }
return   dominoes;

    }
};