class RandomizedSet {
public:
  unordered_map<int,int>m;
  int n=1;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        n++;
        if(m.find(val)!=m.end())
        return false;
        else{
             m[val]=1;
             return true;
        }
    }
    
    bool remove(int val) {
        n++;
         if(m.find(val)==m.end())
        return false;
        else{
             m.erase(val);
             return true;
        }
    }
    
    int getRandom()
     {
        //  cout<<m.size();
          int random=rand();
          int ind=random%m.size();
          auto it= m.begin();
          advance(it,ind);
          return it->first;

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */