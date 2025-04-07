class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int st=0;
        int l=0;
        int r=0;
        vector<int>v;
        for(int i=0;i<firstList.size();i++)
        {
                 v.push_back(firstList[i][0]);
                 v.push_back(firstList[i][1]);

        }
         for(int i=0;i<secondList.size();i++)
        {
                 v.push_back(secondList[i][0]);
                 v.push_back(secondList[i][1]);

        }
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<vector<int>>ans;
        sort(v.begin(),v.end());
        int i=0;
        for(int k=0;k<v.size();k++)
        {
              
              i=v[k];
                      if(l<firstList.size()&&i==firstList[l][0])
                      {
                            st=i;
                            pq.push(firstList[l][1]);
                            l++;
                      }if(r<secondList.size()&&i==secondList[r][0])
                      {
                            st=i;
                            pq.push(secondList[r][1]);
                            r++;
                      }
                    //   if(!pq.empty())
                     
                      if(pq.size()>1&&pq.top()==i)
                      {
                           cout<<i<<"j"<<pq.size()<<" ";
                            ans.push_back({st,i});
                            pq.pop();

                      }
                      if(!pq.empty()&&pq.top()==i)pq.pop();
        }
        return ans;
    }
};