class Solution {
public:
 void construct(string &ans,char c,unordered_map<char,int>&m,int t)
 {
                for(int i=0;i<min(m[c],t);i++)
                {
                       ans+=c;
                }
                m[c]=m[c]-min(m[c],t);
                return;
 }
    string repeatLimitedString(string s, int repeatLimit) {
        string tracker;
        unordered_map<char,int>m;
        for( int i=0;i<s.length();i++)
        {
              m[s[i]]++;

        }
        for( auto a1:m)
        {
              tracker+=a1.first;
        }
        sort(tracker.begin(),tracker.end());
        reverse(tracker.begin(),tracker.end());
        int ind=0;
        int fill=1;
        string ans;
        int n=tracker.length();
        while(true)
        {
              if(ind>=n)
              break;
                   construct(ans,tracker[ind],m,repeatLimit);
                   if(m[tracker[ind]]>0)
                   {    
                       fill=ind+1;
                         while(fill<tracker.length()&&m[tracker[fill]]<=0)
                         {
                             fill++;
                         }
                         if(fill<tracker.length()&& m[tracker[fill]]>0)
                         {    
                            //    cout<< m[tracker[fill]]<<endl;
                               ans+=tracker[fill];
                               
                               m[tracker[fill]]--;
                         }else
                         break;

                   }else 
                     {
                         ind++;
                     }
        }
        return ans;
    }
};