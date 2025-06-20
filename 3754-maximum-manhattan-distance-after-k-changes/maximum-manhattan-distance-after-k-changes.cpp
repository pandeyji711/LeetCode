class Solution {
public:

     int sum( unordered_map<int,pair<int,int>>&m1,int k)
     {
                    vector<pair<int,int>>v;
                    int ch=0;
                    int val=0;
                    for(auto &a1:m1)
                    {
                        //    v.push_back({a1.second.first,a1.second.second});
                           if(val<a1.second.first)
                           {
                               ch=a1.second.second;
                               val=a1.second.first;
                           }
                      
                    }
                    
                    // int ch=v[0].second;
                    int op=0;
                    if(ch==0)
                    op=1;
                    else if(ch==2)
                    op=3;
                    else if(ch==3)
                    op=2;
                    // cout<<op<<" "<<ch<<endl;
                    int ans=m1[ch].first;
                       int sp=0;
                    if(m1.find(op)!=m1.end()){
                            sp=m1[op].first;
                    }
                    // cout<<sp<<"k";
                    if(k>=sp)
                    {
                        //   cout<<"d";
                         k=k-sp;
                        //  cout<<"g";
                          ans+=sp;
                        //   cout<<ans;

                    } 
                    else{
                        
                           ans+=k;
                           sp=sp-k;
                           ans-=sp;
                        //    cout<<ans;
                           k=0;
                    }
                    // cout<<k<<" "<<ans<<endl;
                      if(m1.find(2)!=m1.end()||m1.find(3)!=m1.end()){
                      if(ch==1||ch==0)
                             {
                                    int x=m1[2].first;
                                    int y=m1[3].first;
                                    int add=0;
                                    // cout<<ans<<" "<<x<<" "<<y<<endl;
                                    if(x>0&&y>0)
                                    {
                                          int minn=min(x,y);
                                         if(k>=minn)
                                         {
                                              ans+=max(x,y)+minn;
                                         }else{
                                               int diff=minn-k;
                                               ans+=(max(x,y)+k-diff);
                                         }
                                    }else
                                    ans+=max(x,y);
                             }
                      }
                       if(m1.find(0)!=m1.end()||m1.find(1)!=m1.end()){
                                if(ch==2||ch==3)
                             {
                                         int x=m1[0].first;
                                    int y=m1[1].first;
                                    int add=0;
                                    
                                 if(x>0&&y>0)
                                    {
                                          int minn=min(x,y);
                                         if(k>=minn)
                                         {
                                              ans+=max(x,y)+minn;
                                         }else{
                                               int diff=minn-k;
                                               ans+=(max(x,y)+k-diff);
                                         }
                                    }else
                                    ans+=max(x,y);
                             }
                       }
                    

                    return ans;

     }
    int maxDistance(string &s, int k) {
        
           unordered_map<int,pair<int,int>>m1;
          
int ans=0;
          for(int i=0;i<s.length();i++)
          {
                if(s[i]=='N')
                m1[0]={m1[0].first+1,0};
               else  if(s[i]=='S')
                m1[1]={m1[1].first+1,1};
                else if(s[i]=='E')
                m1[3]={m1[3].first+1,3};
                else if(s[i]=='W')
                 m1[2]={m1[2].first+1,2};
                //  if(i==2)
             ans=max(ans,sum(m1,k));
            //  cout<<ans<<" "<<i<<endl;
          }
        
          
        return ans;
         
    }
};