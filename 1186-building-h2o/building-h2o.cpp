class H2O {
    private:
    condition_variable cv;;
     mutex mtx;
     int h;
     int o;
public:
    H2O() {
        h=0;
        o=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        unique_lock<mutex>lock(mtx);
        cv.wait(lock,[this]{return h==0||h==1;});
        h++;

        releaseHydrogen();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
          unique_lock<mutex>lock(mtx);
        cv.wait(lock,[this]{return h==2;});
        h=0;

        releaseOxygen();
        cv.notify_all();
        
    }
};