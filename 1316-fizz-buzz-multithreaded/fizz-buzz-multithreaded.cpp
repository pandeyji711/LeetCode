class FizzBuzz {
private:
    int n;
    condition_variable cv;
    mutex mtx;
    int cnt;
    bool tem;

public:
 
   
    FizzBuzz(int n) {
        this->n = n;
        cnt=1;
    }

   
    void fizz(function<void()> printFizz) {

            while(cnt<=n)
            {       
                if(cnt>n)break;
                     unique_lock<mutex>lock(mtx);
                    //  cout<<(cnt%3==0&&cnt%5!=0);
                     cv.wait(lock,[this]{return (cnt%3==0&&cnt%5!=0)||cnt>n;});
                     if(cnt>n)break;
                     printFizz();
                     cnt++;
                    //  cout<<cnt;
                      cv.notify_all();
                    
                    
                     
            }
            // cout<<"fizzbreak";
    }

   
    void buzz(function<void()> printBuzz) {
         while(cnt<=n)
            {
                     unique_lock<mutex>lock(mtx);
                     cv.wait(lock,[this]{return (cnt%3!=0&&cnt%5==0)||cnt>n;});
                     if(cnt>n)break;
                     printBuzz();
                     cnt++;
                     cv.notify_all();
            }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
         while(cnt<=n)
            {
                     unique_lock<mutex>lock(mtx);
                     cv.wait(lock,[this]{return (cnt%3==0&&cnt%5==0)||cnt>n;});
                     if(cnt>n)break;
                     printFizzBuzz();
                     cnt++;
                     cv.notify_all();
            }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
         while(cnt<=n)
            {
                  
                     unique_lock<mutex>lock(mtx);
                    //  tem=(cnt%3!=0&&cnt%5!=0);
                  
                     cv.wait(lock,[this]{return (cnt%3!=0&&cnt%5!=0)||cnt>n;});
                     if(cnt>n) break;
                    printNumber(cnt);
                     cnt++;
                    
                   
                      cv.notify_all();
            }
            //   cout<<"numbreak";
    }
};