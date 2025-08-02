class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
    
             unordered_map<int,int>m1;
             unordered_map<int,int>m2;
             unordered_map<int,int>summ;
             int minn=INT_MAX;
             for(int i=0;i<basket1.size();i++)
             {
                   m1[basket1[i]]++;
                   m2[basket2[i]]++;
                   summ[basket1[i]]++;
                   summ[basket2[i]]++;
                   minn=min(minn,min(basket1[i],basket2[i]));

             }
             vector<int>t1;
             vector<int>t2;
             unordered_map<int,int>tm;
             for( auto a1:summ)
             {
                       if(a1.second%2!=0)return -1;
                       if(m1[a1.first]<m2[a1.first])
                       {
                              
                             int need=m2[a1.first]-summ[a1.first]/2;
                             tm[minn]+=need;
                             if(a1.first!=minn)
                             {
                                tm[-1]+=need;
                             }
                            while(need--)
                            {
                                t2.push_back(a1.first);
                            }
                                   
                       }
                        else if(m1[a1.first]>m2[a1.first])
                       {
                              int need=m1[a1.first]-summ[a1.first]/2;
                               tm[minn]+=need;
                             if(a1.first!=minn)
                             {
                                tm[-1]+=need;
                             }
                                  while(need--)
                            {
                                t1.push_back(a1.first);
                            }
                       }


             }
            sort(t1.begin(),t1.end());
            sort(t2.begin(),t2.end());
        //   cout<<t1.size()<<" "<<t2.size();
            int lt1=0;
            int rt1=t1.size()-1;
            int lt2=0;
            int rt2=t2.size()-1;
            long long ans=0;
             while(lt1<=rt1&&lt2<=rt2)
             {
                // cout<<"k";
                        ans+=min(2LL*minn,1LL*min(t1[lt1],t2[rt2]));
                        lt1++;
                        rt2--;
             }

  return ans;

    }
};