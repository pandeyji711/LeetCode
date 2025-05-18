class LockingTree {
public:
 unordered_map<int,vector<int>>adj;
  unordered_map<int,int>lockmap;
  unordered_map<int,vector<int>>Radj;
    bool ancestorsCheck(int root)
    {
           queue<int>q;
           q.push(root);
           while(!q.empty())
           {
                   int n=q.size();
                     for(int i=0;i<n;i++)
                     {
                          int node=q.front();
                          q.pop();
                             for(int a1:Radj[node])
                             {
                                      if(lockmap.find(a1)!=lockmap.end())return false;
                                q.push(a1);
                             }
                     }
           }
           return true;
    }
     bool descendant (int root)
    {
           queue<int>q;
           q.push(root);
        
           while(!q.empty())
           {
                 int n=q.size();
                     for(int i=0;i<n;i++)
                     {
                          int node=q.front();
                          q.pop();
                             for(int a1:adj[node])
                             {
                                      if(lockmap.find(a1)!=lockmap.end())return true;
                                q.push(a1);
                             }
                     }
           }
           return false;
    }
   void Unlockdescendant (int root)
    {
           queue<int>q;
           q.push(root);
        
           while(!q.empty())
           {
                   int n=q.size();
                     for(int i=0;i<n;i++)
                     {
                          int node=q.front();
                          q.pop();
                             for(int a1:adj[node])
                             {
                                      if(lockmap.find(a1)!=lockmap.end()){
                                           lockmap.erase(a1);
                                        }
                                q.push(a1);
                             }
                     }
           }
        //    return false;
    }
    LockingTree(vector<int>& parent) {
        for(int i=0;i<parent.size();i++)
        {
              if(parent[i]!=-1){
                adj[parent[i]].push_back(i);
                 Radj[i].push_back(parent[i]);
              }
        }
    }
    
    bool lock(int num, int user) {
          if(lockmap.find(num)==lockmap.end())
          {
                   lockmap[num]=user;
                   return true;
          }
          return false;

    }
    
    bool unlock(int num, int user) {
            
              if(lockmap.find(num)!=lockmap.end())
              {
                      if(lockmap[num]==user)
                      {
                         lockmap.erase(num);
                         return true;
                      }else
                      return false;
              }
              return false;
    }
    
    bool upgrade(int num, int user) {
        if(lockmap.find(num)!=lockmap.end())return false;
        //  cout<<ancestorsCheck(num)<<" "<<descendant(num);
         if(ancestorsCheck(num)&&descendant(num))
         {
              Unlockdescendant(num);
              lockmap[num]=user;
              return true;
         }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */