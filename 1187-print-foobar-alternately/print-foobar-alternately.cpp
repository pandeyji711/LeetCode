#include <mutex>
class FooBar {
private:
    int n;
    condition_variable cv;
    mutex mtx;
    bool isfoo;

public:
    FooBar(int n) {
        this->n = n;
        isfoo=true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this]{return isfoo;});
        	printFoo();
            isfoo=false;
             cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
              unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this]{return !isfoo;});
        	// printFoo();
            printBar();
            isfoo=true;
             cv.notify_all();
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	
        }
    }
};