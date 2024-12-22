class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>ver;
        vector<pair<int,int>>hori;
        for(int i=0;i<rectangles.size();i++)
        {
                 ver.push_back({rectangles[i][1],rectangles[i][3]});
                 hori.push_back({rectangles[i][0],rectangles[i][2]});

        }
        sort(ver.begin(),ver.end());
          sort(hori.begin(),hori.end());
        queue<pair<int,int>>q;
        q.push({ver[0].first,ver[0].second});
        int cnt=0;
        for(int i=0;i<ver.size();i++)
        {
               while(!q.empty()&&q.front().second<=ver[i].first)
               q.pop();
               if(q.empty())
                cnt++;
                if(cnt>=2)
                return true;
                q.push(ver[i]);
        }
         queue<pair<int,int>>q1;
        q1.push({hori[0].first,hori[0].second});
         cnt=0;
           for(int i=0;i<hori.size();i++)
        {
               while(!q1.empty()&&q1.front().second<=hori[i].first)
               q1.pop();
               if(q1.empty())
                cnt++;
                if(cnt>=2)
                return true;
                q1.push(hori[i]);
        }
        return false;

    }
};