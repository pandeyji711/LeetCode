class LFUCache {
public:
 unordered_map<int,int>mv; // store updated value
 unordered_map<int,int>m; // store updated fequency
priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
int siz=0;
int time=0;
    LFUCache(int capacity) {
        siz=capacity;
    }
    
    int get(int key) {
               
            if(mv.find(key)!=m.end())
            {
                 time++;
                    m[key]++;
                    pq.push({m[key],time,key});
                    return mv[key];
            }else{
                 return -1;
            }
    }
    
    void put(int key, int value) {
                 time++;
                if(mv.find(key)!=mv.end())
                {
                      m[key]++;
                    pq.push({m[key],time,key});
                    mv[key]=value;
                    return ;


                }
                if(m.size()<siz)
                {
                     m[key]++;
                    pq.push({m[key],time,key});
                    mv[key]=value;
                }else{
                       
                         //clear
                         while(!pq.empty()&&(m.find(pq.top()[2])==m.end()||m[pq.top()[2]]!=pq.top()[0]))
                         {
                            // cout<<key<<" "<<pq.top().second<<" "<<pq.top().first<<" "<<m[pq.top().second]<<endl;
                               pq.pop();
                         }
                         if(!pq.empty()){
                         int x=pq.top()[2];
                         pq.pop();
                         m.erase(x);
                         mv.erase(x);
                         }
                         mv[key]=value;
                         m[key]++;
                         pq.push({m[key],time,key});



                }
                return ;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */