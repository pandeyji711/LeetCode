class Solution {
public:
  int solve( unordered_map<char,pair<int,int>>&m,int ans,int n)
  {
                int maxx=INT_MIN;
                 char c='*';
                 for(auto &a1:m)
                 {
                    // cout<<"k";
                       if(a1.second.first<=ans&&maxx<a1.second.second)
                       {
                             maxx=a1.second.second;
                             c=a1.first;
                       }
                 }
                //  cout<<c<<" "<<maxx<<endl;
                 if(c=='*')
                 return  -1;

                 m[c].second--;
                m[c].first=ans+n+1;
                 if(m[c].second==0){
                    //   cout<<c<<" "<<m[c].second<<endl;
                 m.erase(c);


                 }

                 
                 return 0;
  }
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,pair<int,int>>m;
        for(int i=0;i<tasks.size();i++)
        {        
                if(m.find(tasks[i])==m.end()){
                   m[tasks[i]]={0,1};

                }else{
                     m[tasks[i]].second++;
                }
        }

        int ans=0;
        while(!m.empty())
        {
                solve(m,ans,n);

                 ans++;
        }
        return ans;


    }
};