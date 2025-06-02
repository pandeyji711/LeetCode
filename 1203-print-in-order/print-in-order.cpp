class Foo {
public:
   condition_variable cv;
   mutex mtx; 
    int chance;
      Foo() {
        chance=1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
          unique_lock<mutex>lock(mtx);
          cv.wait(lock,[this]{return chance==1;});
        printFirst();
        chance=2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
           unique_lock<mutex>lock(mtx);
          cv.wait(lock,[this]{return chance==2;});
       printSecond();
        chance=3;
        cv.notify_all();
       
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
           unique_lock<mutex>lock(mtx);
          cv.wait(lock,[this]{return chance==3;});
           printThird();
           chance=0;
        cv.notify_all();
       
    }
};