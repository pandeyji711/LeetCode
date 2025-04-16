class Solution {
public:
long long const mod= 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
           hFences.push_back(m);
           hFences.push_back(1);
           
       vFences.push_back(n);
       vFences.push_back(1);
       sort(hFences.begin(),hFences.end());
       sort(vFences.begin(),vFences.end());
                   unordered_map<long long ,pair<long long,long long>>m1;
            //   vector<
             long long ans=0;
            for(int i=0;i<hFences.size();i++)
            {
                   for(int j=0;j<vFences.size();j++)
                   {
                          long long diff= vFences[j]-hFences[i];
    
                           if(m1.find(diff)==m1.end())
                           {
                               m1[diff]={vFences[j],hFences[i]};
                                // cout<<vFences[j]<<" "<<hFences[i]<<endl;
                            
                           }else{
                            // m1[diff].pop_back();
                            // m1[diff].push_back({vFences[j],hFences[i]});
                                  long long x=vFences[j]- m1[diff].first;
                                // cout<<vFences[j]<<" "<<hFences[i]<<endl;
                                long long area= 1LL*(x*x);
                      ans=max(ans,area);
                           }
                        //   m1[diff]++;
                        // cout<<m1[diff].size()<<" ";
                   }
            }  
            // long long ans=0;
            // for( auto &a1:m1)
            // {
            //     // cout<<"k";
            //       if(a1.second.size()==2){

            //         // cout<<a1.first<<" " <<a1.second[0].first<<" "<<a1.second[0].second <<" "<<a1.second[1].first<<" "<<a1.second[1].second<<endl;
            //        long long p1=a1.second[1].first;
            //        long long p2=a1.second[0].first;
            //        long long x=p1-p2;
            //     //    cout<<x;
            //           long long area= 1LL*(x*x);
            //           ans=max(ans,area);
            //       }
            // }
            return ans==0?-1:ans%mod;

    }
};