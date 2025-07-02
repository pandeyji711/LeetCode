class LRUCache {
public:
 unordered_map<int,int>m;
 int time=0;
 int siz=0;
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
 unordered_map<int,int>mv;
    LRUCache(int capacity) {
        siz=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
             time++;
         m[key]=time;
       pq.push({time,key});
      
        return mv[key];
        }else{
               return -1;
        }
        
    }
    
    void put(int key, int value) {
         time++;
            if(m.find(key)!=m.end())
            {
                   
                   mv[key]=value;
                    pq.push({time,key});
                   
                     m[key]=time;
                    return ;
            }
            if(m.size()<siz)
            {
                   m[key]=time;
                   mv[key]=value;
                    pq.push({time,key});
                    // return ;

            }else{
                    //clear
                    while(!pq.empty()&&(m.find(pq.top().second)==m.end()||m[pq.top().second]!=pq.top().first)){
                          pq.pop();
                    }
                    if(!pq.empty())
                    {
                           int x=pq.top().second;
                           m.erase(x);
                           mv.erase(x);
                           pq.pop();

                    }
                    pq.push({time,key});
                    mv[key]=value;
                    m[key]=time;
                  
            }
             
            return ;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */