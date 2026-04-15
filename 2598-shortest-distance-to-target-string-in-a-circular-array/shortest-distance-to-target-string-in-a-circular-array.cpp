class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int target_ind=-1;
        for(int i=0;i<words.size();i++)
        {
               if(words[i]==target){target_ind=i;
                break;
               }
        }
        if(target_ind==-1)return -1;
        //left
        int n=words.size(),n1=words.size();
        int ind1=startIndex,ind2=startIndex;
        int rstep=0,lstep=0;
        while(n>0)
        {
              int ind=ind1%n1;
              if(words[ind]==target){
                   break;
              }
              rstep++;
              ind1++;
              n--;

        }
        int n2=words.size();
        // cout<<rstep<<" ";
    
      while(n1>0)
        {
              int ind=ind2%n2;
              if(words[ind]==target){
                   break;
              }
              lstep++;
              ind2--;
              if(ind2==-1)
              {
                 ind2=words.size()-1;
              }
              n1--;

        }
        cout<<lstep<<" "<<rstep;
     return min(lstep,rstep);
    }
};