class DiningPhilosophers {
    private:
    vector<int>arr;
      unordered_map<int,int>m;
      unordered_map<int,pair<int,int>>msp;
      condition_variable cv;
         mutex mtx;
public:
   bool solve( int philosopher){
            
              if(philosopher==4)
            {
                  
                   //pehle vo apne left me check kare
                      if(msp[4].second==0)
                      {
                        //   cout<<"j";
                             int indr=(m[4]+1)%10;
                            //  cout<<arr[indl]<<" ";
                             if(arr[indr]==1)
                             {
                                  msp[4].second=1;
                                  arr[indr]=0;
                                //   pickRightFork();
                                 

                             }
                      }
                          if( msp[4].first==0) {
                                   int indl=(m[4]%10-1)%10;
                             if(arr[indl]==1)
                             {
                                
                                //   pickLeftFork();
                                    //  eat();
                                     arr[(indl-2)%10]=1;
                                     return true;
                                     

                             }
                         }
            }else{

                      //pehle vo apne right me check kare
                      if(msp[philosopher].first==0)
                      {
                        //   cout<<"j";
                             int indl=(m[philosopher]-1)%10;
                            //  cout<<arr[indl]<<" ";
                             if(arr[indl]==1)
                             {
                                  msp[philosopher].first=1;
                                  arr[indl]=0;
                                //   pickLeftFork();
                                 

                             }
                      }
                          if( msp[philosopher].second==0) {
                                   int indr=(m[philosopher]%10+1)%10;
                             if(arr[indr]==1)
                             {
                                  
                                //   pickRightFork();
                                    //  eat();
                                     arr[(indr-2)%10]=1;
                                     return true;
                                     

                             }
                         }



            }
           
         return false;
   }
    DiningPhilosophers() {
       arr.resize(10,1);
          m[0]=1;
          m[1]=3;
          m[2]=5;
          m[3]=7;
          m[4]=9;
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
          unique_lock<mutex>lock(mtx);
          cv.wait(lock,[this,philosopher]{return solve(philosopher);});
             if(philosopher==4)
             {
               
                pickRightFork();
                 pickLeftFork();
                eat();
                putRightFork();
                putLeftFork();

             }else{
                  pickLeftFork();
                 pickRightFork();
                
                eat();
            
                putLeftFork();
                    putRightFork();
             }
            cv.notify_all();       
		        
    }
};