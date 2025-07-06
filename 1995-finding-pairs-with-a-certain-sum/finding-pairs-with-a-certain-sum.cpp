class FindSumPairs {
public:
unordered_map<int,int>m1;
vector<int>num1;
vector<int>num2;

    FindSumPairs(vector<int>& numsx, vector<int>& numsy) {
         this->num1=numsx;
         this->num2=numsy;
        
           for(int i=0;i<num2.size();i++)
           {
                 m1[num2[i]]++;
           }
        

    }
    
    void add(int index, int val) {
      
        m1[num2[index]]--;
       
        if(m1[num2[index]]<=0)
        m1.erase(num2[index]);
           m1[num2[index]+val]++;
      num2[index]+=val;
      
        
    }
    
    int count(int tot) {
      
          int ans=0;
     
          for(int i=0;i<num1.size();i++)
          {
                
                    if(m1.find(tot-num1[i])!=m1.end())
                    {
                            ans+=m1[tot-num1[i]];
                    }
          }
          return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */