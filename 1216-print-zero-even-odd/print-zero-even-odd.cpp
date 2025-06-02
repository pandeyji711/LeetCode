class ZeroEvenOdd {
private:
    int n;
    condition_variable cv;
     mutex mtx;
     bool iszero;
     bool iseven;
     int cnt;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        iszero=true;
        iseven=true;
        cnt=1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;i++){
          unique_lock<mutex>lock(mtx);
          cv.wait(lock,[this]{return iszero;});
          printNumber(0);
          iseven=!iseven; //odd
          iszero=false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=0;i<n/2;i++){
          unique_lock<mutex>lock(mtx);
          cv.wait(lock,[this]{return !iszero&&iseven;});
         printNumber(cnt);
         cnt++;
        
          iszero=true;
       cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
         
         for(int i=0;i<n/2+(n%2!=0);i++){
            unique_lock<mutex>lock(mtx);
          cv.wait(lock,[this]{return !iszero&&!iseven;});
           printNumber(cnt);
         cnt++;
       
          iszero=true;
       cv.notify_all();
         }
    }
};