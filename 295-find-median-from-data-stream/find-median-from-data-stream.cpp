class MedianFinder {
public:
 priority_queue<int>pqmax;
  priority_queue<int,vector<int>,greater<int>>pqmin;
 int n=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       n++;
       cout<<pqmax.size()<<" "<<pqmin.size()<<endl;
         if(pqmax.size()==0)
         pqmax.push(num);
         
       else if(pqmin.size()==pqmax.size())
       {       
              
               if(pqmax.top()>=num)
               pqmax.push(num);
               else {
                    pqmin.push(num);
               }
               if(pqmax.size()<pqmin.size())
               {
                        int x=pqmin.top();
                        pqmin.pop();
                        pqmax.push(x);
               }
       }
        else{

                  if(pqmax.top()>=num)
               pqmax.push(num);
               else {
                    pqmin.push(num);
               }
               if(pqmax.size()<pqmin.size())
               {
                        int x=pqmin.top();
                        pqmin.pop();
                        pqmax.push(x);
               }else if(pqmax.size()>pqmin.size()){


                       int x=pqmax.top();
                        pqmax.pop();
                        pqmin.push(x);
               }
        }
                             
    }
    
    double findMedian() {
       
       
        if(n%2==0)
        {
              int  n1=pqmin.top();
            //   pq.pop();
            int n2=pqmax.top();
            //   pq.push(n1);
              double mid=(n1+n2)/2.0;
             
           return mid;
        }else{


        //    cout<<"j";
        
            double mid=(double)pqmax.top();
             cout<<mid<<"k";
            return mid;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */