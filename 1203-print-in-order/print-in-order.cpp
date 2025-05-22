class Foo {
private:
binary_semaphore secondReady{0};
binary_semaphore thirdReady{0};

public:
    Foo() {}

    void first(std::function<void()> printFirst) {
        printFirst();
        secondReady.release(); // allow second() to run
    }

    void second(std::function<void()> printSecond) {
        secondReady.acquire(); // wait for first()
        printSecond();
        thirdReady.release(); // allow third() to run
    }

    void third(std::function<void()> printThird) {
        thirdReady.acquire(); // wait for second()
        printThird();
    }
};
