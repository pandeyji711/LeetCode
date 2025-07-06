class FindSumPairs {
public:
unordered_map<int,int>m1;
vector<int>num1;
vector<int>num2;
// int time=0;
//   void show()
//   {
//        cout<<m1[74]<<" "<<time<<endl;
//   }
    FindSumPairs(vector<int>& numsx, vector<int>& numsy) {
         this->num1=numsx;
         this->num2=numsy;
        //  time++;
           for(int i=0;i<num2.size();i++)
           {
                 m1[num2[i]]++;
           }
        //    show();

    }
    
    void add(int index, int val) {
        // time++;
        //  if(time==9)
        // {
        //      cout<<"======================="<<m1[num2[index]]<<endl;
        // }
        m1[num2[index]]--;
       
        if(m1[num2[index]]<=0)
        m1.erase(num2[index]);
           m1[num2[index]+val]++;
      num2[index]+=val;
        //    show();
        
    }
    
    int count(int tot) {
        //   time++;
          int ans=0;
        //   show();
          for(int i=0;i<num1.size();i++)
          {
                //   if(tot==88)
                //   {
                //        cout<<num1[i]<<" "<<m1[tot-num1[i]]<<" "<<tot-num1[i]<<endl;
                //   }
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