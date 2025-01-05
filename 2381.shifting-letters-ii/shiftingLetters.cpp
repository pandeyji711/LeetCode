class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>vs(s.length());
       sort(shifts.begin(), shifts.end());
        int ind=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int shift=0;
        for(int i=0;i<s.length();i++)
        {
            
               while(ind<shifts.size()&&shifts[ind][0]==i)
               {
                     if(shifts[ind][2]==1)
                     shift++;
                     else
                     shift--;
                       q.push({shifts[ind][1],shifts[ind][2]});
                       ind++;
                    //    cout<<shift<<"u";
               }
            //    cout<<"||";
               while(!q.empty()&&q.top().first<i){
                  if(q.top().second==1)
                  shift--;
                  else
                  shift++;
               q.pop();
            //    cout<<shift<<"d";
               }
             vs[i]=shift;
            //  cout<<endl;


        }
   string ans;
        for( int i=0;i<vs.size();i++)
        {
                // cout<<vs[i]<<" ";
               if(vs[i]<0)
               {
                      int x=abs(vs[i]);
                      char c=s[i];
                      while(x--)
                      {
                          if(c=='a')
                          {
                              c='z';
                          }else
                          c--;
                      }
                      ans.push_back(c);
               }else{
                        
                        int x=abs(vs[i]);
                      char c=s[i];
                      while(x--)
                      {
                          if(c=='z')
                          {
                              c='a';
                          }else
                          c++;
                      }
                      ans.push_back(c);

               }
        }
        return ans;
    }
};